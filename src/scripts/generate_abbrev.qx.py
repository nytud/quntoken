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
    descr_data = 'Roviditeseket tartalmazo fajl.'
    descr_out  = 'Cél fájl neve (elérési úttal együtt).'
    pars = argparse.ArgumentParser(description=__doc__)
    pars.add_argument(
            '-d',
            '--data-file',
            help=descr_data,
            required=True,
            nargs=1)
    pars.add_argument(
            '-o',
            '--output-file',
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
    return '\n           |'.join(abbrevs)

def generate_qx(data):
    """Templatum behelyettesites.
    """
    tmpl = Template(QX_TMPL)
    abbrevs = get_abbrevs(data)
    return tmpl.substitute(ABBREV=abbrevs)


def main():
    args = args_handling()
    DATA_FILE = args['data_file'][0]
    OUT_FILE  = args['output_file'][0]

    with open(DATA_FILE, 'r') as data:
        qx = generate_qx(data)
    with open(OUT_FILE, 'w') as out:
        out.write(qx)


if __name__ == '__main__':
    QX_TMPL = 'define {\n    ABBREV (${ABBREV})\n}\n\n'
    main()


