#! /usr/bin/env python3
# coding=utf8
"""sntcorr.qx modul generalasa sablonbol es roviditeseket tartalmazo  faljabol.
"""

import sys
import argparse
from string import Template


def args_handling():
    """ Parancssori argumentumok kezelése.
    """
    descr_tmpl = 'Forrás fájl: templátum.'
    descr_data = 'Forrás fájl: adatok.'
    descr_out  = 'Cél fájl neve (elérési úttal együtt).'
    pars = argparse.ArgumentParser(description=__doc__)
    pars.add_argument(
            '-t',
            '--template-file',
            help=descr_tmpl,
            required=True,
            nargs=1)
    pars.add_argument(
            '-d',
            '--data-file',
            help=descr_data,
            required=True,
            nargs=1)
    pars.add_argument(
            '-o',
            '--object-file',
            help=descr_out,
            required=True,
            nargs=1)
    return vars(pars.parse_args())

def get_abbrevs(data):
    """Roviditesek nagybetus alakokkal bovitett listajanak generalasa.
    """
    abbrevs = [ x.rstrip() for x in data if not x.startswith('#') ]
    abbrevs = [ x for x in abbrevs if x ]
    abbrevs = [ x.rstrip('.') for x in abbrevs ]
    abbrevs = [ '"'+x.replace(' ', '"{SPACE}"')+'"' for x in abbrevs ]
    capital_abbrevs = [ x[0]+x[1].upper()+x[2:] for x in abbrevs ] # x[0]=='"'!
    upper_abbrevs = [ x.upper() for x in abbrevs ]
    abbrevs += capital_abbrevs + upper_abbrevs
    abbrevs = sorted(set(abbrevs))
    return '|'.join(abbrevs)

def generate_qx(tmpl, data):
    """Templatum behelyettesites.
    """
    tmpl = Template(tmpl.read())
    abbrevs = get_abbrevs(data)
    return tmpl.substitute(ABBREV=abbrevs)


def main():
    args = args_handling()
    TMPL_FILE = args['template_file'][0]
    DATA_FILE = args['data_file'][0]
    OUT_FILE  = args['object_file'][0]

    with open(TMPL_FILE, 'r') as tmpl, open(DATA_FILE, 'r') as data:
        qx = generate_qx(tmpl, data)
    with open(OUT_FILE, 'w') as out:
        out.write(qx)


if __name__ == '__main__':
    main()


