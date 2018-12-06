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


def get_command(form, mode, word_break):
    mydir = os.path.dirname((os.path.abspath(__file__)))
    prefix = os.path.join(mydir, 'qt_')
    cmd = ['preproc', 'snt', 'sntcorr', 'sntcorr']
    if mode == 'token':
        cmd.append('token')
    if word_break:
        cmd.insert(1, 'hyphen')
    if form != 'raw':
        cmd.append('conv{0}'.format(form))
    cmd = [prefix + x for x in cmd]
    return ' | '.join(cmd)


def tokenize(cmd, text):
    """Low level entry point
    """
    proc = subprocess.Popen(cmd, shell=True,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True)
    out, err = proc.communicate(text)
    return out, err


def main(form, mode, word_break):
    """Entry point.
    """
    cmd = get_command(form, mode, word_break)
    text = sys.stdin.read()
    out, err = tokenize(cmd, text)
    print(out, file=sys.stdout)
    print(err, file=sys.stderr)


if __name__ == '__main__':
    args = get_args()
    main(**args)
