#! /usr/bin/env python3
# coding=utf8
"""Googletest forrasfajl generalasa (tmp/test.cpp).

A generalashoz meg kell adni a sablon fajlt es a teszteseteket
tartalmazo fajlokat.
"""
# TODO: jelen formában nem alkalmas a sorvégek tesztelésére (csak "\n" lehet)

import sys
import argparse
from string import Template


def args_handling():
    """ Parancssori argumentumok kezelése.
    """
    descr_tmpl = 'A templatumot tartalmazo forrasfajlok.'
    descr_data = 'A testeseteket tartalmazo forrasfajlok'
    descr_out  = 'Cel fájl neve (eleresi uttal egyutt).'
    pars = argparse.ArgumentParser(description=__doc__)
    pars.add_argument(
            '-t',
            '--template-file',
            help=descr_tmpl,
            required=True,
            nargs=1)
    pars.add_argument(
            '-d',
            '--data-files',
            help=descr_data,
            required=True,
            nargs='+')
    pars.add_argument(
            '-o',
            '--object-file',
            help=descr_out,
            required=True,
            nargs=1)
    return vars(pars.parse_args())

def process_lines(lines):
    """Vegig megy egy fajlon, kigyujti a be/ki parokat es expectaciokat csinal.

    Az expectation-ok egy fuggvenyhez tartoznak (egy modult tesztelnek), egy
    string-kent kerulnek visszaadasra.
    """
    # TODO: a for ciklus eleg olvashatatlan, at kene dolgozni!
    res = []
    inp = ''
    out = ''
    flipflop = False
    for line in lines:
        line = line.rstrip()
        inp_line = line.startswith(INP_PREFIX) or line == INP_PREFIX[:-1]
        out_line = line.startswith(OUT_PREFIX) or line == OUT_PREFIX[:-1]
        if not inp_line and not out_line:
            continue
        line = line[len(INP_PREFIX):] # feltesszük, hogy a két prefix hossza
                                      # megegyezik
        line = line.replace('"', '\\"')
        if inp_line:
            if not flipflop:
                if inp or out: # előző kör kiírása
                    res.append(EXPECT_TEMPLATE.safe_substitute(INP=inp, OUT=out))
                flipflop = True
                inp = line
            else:
                inp += '\\n' + line
        elif out_line:
            if flipflop:
                flipflop = False
                out = line
            else:
                out += '\\n' + line
    if inp or out: # utolsó kör kiírása
        res.append(EXPECT_TEMPLATE.safe_substitute(INP=inp, OUT=out))
    return '\n    '.join(res)


def generate_tests(test_file):
    """Visszater a kapott fajlbol kinyerheto testesthez tartozo koddal.
    """
    # TODO: atirni try-al!
    with open(test_file) as file_:
        fst_line = file_.readline()
        lines = file_.readlines()
    fst_line = fst_line.lstrip('#')
    fst_line = fst_line.strip()
    fst_line = fst_line.split()
    if len(fst_line) != 2 or fst_line[0] not in MODULES2FUNCTIONS.keys():
        print(ERROR_MSG, file=sys.stderr)
        sys.exit
    testcase = fst_line[0]
    testname = fst_line[1]
    expectations = process_lines(lines)
    expectations = Template(expectations)
    expectations = expectations.substitute(FUNCTION=MODULES2FUNCTIONS[testcase])
    res = TEST_TEMPLATE.substitute(TESTCASE=testcase+'_TEST',
                                   TESTNAME=testname,
                                   EXPECTATIONS=expectations)
    return res


def generate_cpp(tmpl, tests):
    """Behelyettesiti a template-be az osszegyujtott testeseteket.
    """
    tmpl = Template(tmpl.read())
    return tmpl.substitute(TESTS=tests)


def main():
    # parancssori argumentumok
    args = args_handling()
    TMPL_FILE = args['template_file'][0]
    DATA_FILES = args['data_files'] # lista!
    OUT_FILE  = args['object_file'][0]
    # tesztek generalasa
    tests = [ generate_tests(x) for x in DATA_FILES ]
    tests = '\n'.join(tests)
    # template feltoltese a tesztekkel
    with open(TMPL_FILE, 'r') as tmpl:
        cpp = generate_cpp(tmpl, tests)
    # kiiras
    with open(OUT_FILE, 'w') as out:
        out.write(cpp)


if __name__ == "__main__":
    INP_PREFIX = "IN : "
    OUT_PREFIX = "OUT: "
    MODULES2FUNCTIONS = {'PREP':'prepTest', 'SNT':'sntTest', 'SNTCORR':'sntcorrTest', 'TOKEN':'tokenTest'}
    TEST_TEMPLATE = Template("""TEST(${TESTCASE}, ${TESTNAME}){
    ${EXPECTATIONS}\n}""")
    EXPECT_TEMPLATE = Template("""
    EXPECT_EQ(
        std::string("${OUT}"),
        ${FUNCTION}("${INP}"));""")
    ERROR_MSG = '''
    Rosszul formalt teszt fajl.

    Elso sor '#'-al kezdodjek, tartalmazza a tesztelendo modul nevet es a
    tesztelni kivant tulajdonsag nevet (sima ascii azonosito, '_' nelkul).
    Jelenelg elerheto modulok:
        - PREP: elofeldolgozas, ervenytelen  karakterek szurese, html entity-k,
          xml tag-ek kezelese
        - SNT: alap mondatra bontas
        - SNTCORR: mondatrabontas hibainak korrigalasa (roviditesek, datumok)

    Pelda: '# SNT sortores'
    '''
    main()

