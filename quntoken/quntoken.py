#! /usr/bin/env python3
"""Sentence splitter and tokenizer for hungarian texts in utf-8.
Read from STDIN, write to STDOUT.
"""


import argparse
import subprocess
import sys
import os


FORMATS = {'json', 'raw', 'tsv', 'xml'}
MODES = {'sentence', 'token'}


def check_format(form):
    """Check format argument.
    """
    if form not in FORMATS:
        raise argparse.ArgumentError
    return form


def check_mode(mode):
    """Check mode argument.
    """
    if mode not in MODES:
        raise argparse.ArgumentError
    return mode


def get_args():
    """Handling of commandline arguments.
    """
    pars = argparse.ArgumentParser(description=__doc__)
    pars.add_argument(
        '-f',
        '--form',
        help= 'Valid formats: json, tsv and xml. Default format: tsv.',
        default='tsv',
        type=check_format
    )
    pars.add_argument(
        '-m',
        '--mode',
        help= 'Modes: sentence and token. Default: token',
        default='token',
        type=check_mode
    )
    pars.add_argument(
        '-w',
        '--word-break',
        help='Eliminate word break from end of lines.',
        action='store_true'
    )
    res = vars(pars.parse_args())
    return res


def get_command(rawcmd):
    """From list of modules generate a runnable command string.
    """
    mydir = os.path.dirname((os.path.abspath(__file__)))
    prefix = os.path.join(mydir, 'qt_')
    cmd = [prefix + x for x in rawcmd]
    return ' | '.join(cmd)


def tokenize(cmd, input_iterator):
    """Low level entry point, return an iterator object.

    cmd -- list of module names (str)
    text -- text to tokenize
    """
    cmd = get_command(cmd)
    proc = subprocess.Popen(cmd, shell=True,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True)
    input = iter(input_iterator)
    handle = proc.stdin
    if os.fork():
        # parent
        handle.close()
        for line in proc.stdout:
            yield line
        else:
            for err in proc.stderr:
                print(err, file=sys.stderr)
    else:
        # child
        try:
            handle.writelines(input)
            handle.close()
        # An IOError here means some *other* part of the program
        # crashed, so don't complain here.
        except IOError:
            pass
        os._exit(0)


def main(form, mode, word_break):
    """Command line entry point.
    """
    cmd = ['preproc', 'snt', 'sntcorr', 'sntcorr']
    if mode == 'token':
        cmd.append('token')
    if word_break:
        cmd.insert(1, 'hyphen')
    if form != 'raw':
        cmd.append('conv{0}'.format(form))
    for line in tokenize(cmd, sys.stdin):
        print(line, end='', file=sys.stdout)



if __name__ == '__main__':
    args = get_args()
    main(**args)
