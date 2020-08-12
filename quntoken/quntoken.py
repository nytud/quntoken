#! /usr/bin/env python3
"""Sentence splitter and tokenizer for hungarian texts in utf-8.
Read from STDIN, write to STDOUT.
"""


import subprocess
import sys
import os


def call_modules(inp, modules):
    """Low level entry point.

    inp -- input iterator
    modules -- list of modules
    """
    mydir = os.path.dirname((os.path.abspath(__file__)))
    prefix = os.path.join(mydir, 'qt_')
    cmd = [prefix + x for x in modules]
    cmd = ' | '.join(cmd)
    proc = subprocess.Popen(cmd, shell=True,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True)
    inp = iter(inp)
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
            handle.writelines(inp)
            handle.close()
        # An IOError here means some *other* part of the program
        # crashed, so don't complain here.
        except IOError:
            pass
        os._exit(0)


def get_modules(form, mode, word_break):
    """Generate list of modules from 'form', 'mode', etc. parameters.
    """
    modules = ['preproc', 'snt', 'sntcorr', 'sntcorr']
    if mode == 'token' and form != 'spl':
        modules.append('token')
    if word_break:
        modules.insert(1, 'hyphen')
    if form != 'raw':
        modules.append('conv{0}'.format(form))
    return modules


def tokenize(inp=sys.stdin, form='tsv', mode='token', word_break=False):
    """Entry point, return an iterator object.

    inp -- input iterator (default: stdin)
    form -- format of result (tsv, xml, json, raw)
    mode -- token (tokenization, default) or sentence (just sentence segmenting)
    word_break -- eliminate word break from end of lines (default: False)
    """
    modules = get_modules(form, mode, word_break)
    return iter(call_modules(inp, modules))


class EmTokenPy:
    """API for emtsv / xtsv.
    (https://github.com/dlt-rilmta/emtsv, https://github.com/dlt-rilmta/xtsv)
    """
    pass_header = True

    def __init__(self, source_fields=None, target_fields=None):

        # Field names for e-magyar TSV
        if source_fields is None:
            source_fields = set()

        if target_fields is None:
            target_fields = []

        self.source_fields = source_fields
        self.target_fields = target_fields

    @staticmethod
    def process_sentence(sen, _=None):
        res = tokenize(sen)
        return res

    @staticmethod
    def prepare_fields(field_names):
        return field_names
