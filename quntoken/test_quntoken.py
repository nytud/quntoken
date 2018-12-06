#! /usr/bin/env python3


import pytest
from glob import glob
try:
    from quntoken.quntoken import tokenize
except:
    from quntoken import tokenize


def get_cmd(filename):
    """Tesztfajl nevebol generalja a futtatando modulok listajat.
    """
    module = filename.split('_')[2]
    rawcmd = {
        'hyphen': 'preproc hyphen',
        'preproc': 'preproc',
        'snt': 'preproc snt',
        'sntcorr': 'preproc snt sntcorr sntcorr',
        'token': 'preproc snt sntcorr sntcorr token'
    }[module]
    cmd = rawcmd.split()
    cmd.append('convxml')
    return cmd


def get_pairs(filename):
    """Teszt-fajlbol olvas, visszater az input-elvartoutput parok listajaval
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


def logging(cmd, inp, exp, out, err, logfile):
    """Megadott fajlobjektumba irja a megadott adatokat.
    """
    myinp = ['INP: {0}'.format(x) for x in inp.split('\n')]
    myinp = '\n'.join(myinp)
    myexp = ['EXP: {0}'.format(x) for x in exp.split('\n')]
    myexp = '\n'.join(myexp)
    myout = ['OUT: {0}'.format(x) for x in out.split('\n')]
    myout = '\n'.join(myout)
    myerr = ['ERR: {0}'.format(x) for x in err.split('\n')]
    myerr = '\n'.join(myerr)
    log = '\n'.join([str(cmd), myinp, myexp, myout, myerr, '\n'])
    print(log, file=logfile)


@pytest.fixture(params=sorted(glob('test/test_default_*')))
def get_data(request):
    """Pytest fixture.
    
    Fajlnev alapjan visszater a hozzatarozo logfajl nevevel,
    a futtatand paranccsal es a fajlbol kiolvashato bemenet/elvart
    kimenet parokkal.
    """
    filename = request.param
    logname = filename.replace('test', 'tmp', 1).replace('.txt', '.log')
    cmd = get_cmd(filename)
    pairs = get_pairs(filename)
    return logname, cmd, pairs


def test_modules(get_data):
    """Pytest teszt-fuggveny.
    
    Minden, tesztadatokat tartalmazo test/-beli
    fajlra lefut.
    """
    logname, cmd, pairs = get_data
    with open(logname, 'w') as logfile:
        for inp, exp in pairs:
            out, err =  tokenize(cmd, inp)
            logging(cmd, inp, exp, out, err, logfile)
            assert out == exp
