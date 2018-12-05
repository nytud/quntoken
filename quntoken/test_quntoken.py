#! /usr/bin/env python3

import io
import os
import sys
from pprint import pprint
from glob import glob
try:
    from quntoken.quntoken import tokenize
except:
    from quntoken import tokenize


def get_files(module):
    """Modul nev alapjan visszaadja a hozza tartozo tesztfajlok listajat.
    """
    if module == 'snt':
        module = 'snt_'
    mydir = os.path.dirname((os.path.abspath(__file__)))
    testdir = os.path.join(mydir, '..', 'test')
    files = glob(os.path.join(testdir, f'test_default_{module}*'))
    files = [os.path.abspath(x) for x in files]
    return files


def get_cmd(rawcmd):
    """Parameterkent veszi a modulnevek felsorolasat tartalmazo stringet,
    visszater a Popen()-nek atadhato paranccsal.
    """
    prefix = './quntoken/qt_'
    cmd = rawcmd.split()
    cmd.append('convxml')
    cmd = [prefix + x for x in cmd]
    cmd = ' | '.join(cmd)
    return cmd


def print_err(filename, cmd, inp, exp, out, err):
    """Mindenfele adatot kiir hiba eseten.
    """
    print(f'filename: {filename}', file=sys.stderr)
    print(f'cmd: {cmd}', file=sys.stderr)
    print(f'inp: {inp}', file=sys.stderr)
    print(f'out: {out}', file=sys.stderr)
    print(f'exp: {exp}', file=sys.stderr)
    for line in err.split('\n'):
        print(f'err: {line}', file=sys.stderr)
    print('~'*40)


def get_pairs(filename):
    """Teszt-fajlbol kigyujti az input-elvartoutput parokat.
    Ezek listajat adja vissza.
    """
    with open(filename) as f:
        lines = f.readlines()
    inp_prefix = 'IN : '
    out_prefix = 'OUT: '
    pairs = []
    inp = ''
    out = ''
    in_progress = False
    for line in [line.rstrip('\n') for line in lines]:
        inp_line = line.startswith(inp_prefix) or line == inp_prefix[:-1]
        out_line = line.startswith(out_prefix) or line == out_prefix[:-1]
        if not inp_line and not out_line:
            continue
        line = line[len(inp_prefix):]
        if inp_line:
            if not in_progress:
                if inp or out: # előző kör kiírása
                    pairs.append((inp, out))
                in_progress = True
                inp = line
            else:
                inp += '\n' + line
        elif out_line:
            if in_progress:
                in_progress = False
                out = line
            else:
                out += '\n' + line
    if inp or out: # utolsó kör kiírása
        pairs.append((inp, out))
    return pairs


def common(rawcmd):
    """Modulok tesztelesenek kozos fuggvenye.
    """
    # TODO: ezt at kene irni ilyen fixture-s megoldasra
    cmd = get_cmd(rawcmd)
    files = get_files(rawcmd.split()[-1])
    for filename in files:
        pairs = get_pairs(filename)
        for inp, exp in pairs:
            out, err = tokenize(cmd, inp)
            if err:
                print_err(filename, cmd, inp, exp, out, err)
            assert out == exp, f'Should be {exp}'


def test_preproc():
    common('preproc')


def test_hyphen():
    common('preproc hyphen')


def test_snt():
    common('preproc snt')


def test_sntcorr():
    common('preproc snt sntcorr sntcorr')


def test_token():
    common('preproc snt sntcorr sntcorr token')


test_preproc()
test_hyphen()
test_snt()
test_sntcorr()
test_token()
