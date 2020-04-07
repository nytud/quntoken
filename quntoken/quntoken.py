#! /usr/bin/env python3
"""Sentence splitter and tokenizer for hungarian texts in utf-8.
Read from STDIN, write to STDOUT.
"""


import subprocess
import sys
import os


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

