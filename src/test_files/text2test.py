#! /usr/bin/env python3
# coding=utf8
"""Szöveges fájlokból googletest forrásfájlok generálása

A szöveges fájlok jellemzői:
    - komment: "#"
    - bemeneti blokk: "IN : "
    - kimeneti blokk: "OUT: "
Példa:
IN : Nana. # megjegyzés
OUT: Nono.
"""
# TODO: jelen formában nem alkalmas a sorvégek tesztelésére (csak "\n" lehet)

import sys
import glob
from string import Template


def process_file(file_, assertions):
    IN = ''
    OUT = ''
    flipflop = False
    for line in file_:
        line = line.rstrip()
        in_line = line.startswith(IN_PREFIX) or line == IN_PREFIX[:-1]
        out_line = line.startswith(OUT_PREFIX) or line == OUT_PREFIX[:-1]
        if not in_line and not out_line:
            continue
        line = line[len(IN_PREFIX):] # feltesszük a két prefix hossza megegyezik
        line = line.replace('"', '\\"')
        if in_line:
            if not flipflop:
                if IN or OUT: # előző kör kiírása
                    assertions.append(ASSERT_TEMPLATE.substitute(IN_=IN, OUT_=OUT))
                flipflop = True
                IN = line
            else:
                IN += '\\n' + line
        elif out_line:
            if flipflop:
                flipflop = False
                # OUT = line + '\\n'
                OUT = line
            else:
                # OUT += line + '\\n'
                OUT += '\\n' + line
    if IN or OUT: # utolsó kör kiírása
        assertions.append(ASSERT_TEMPLATE.substitute(IN_=IN, OUT_=OUT))


def main():
    assertions = []
    for file_name in glob.glob(INPUT_DIR+'test_*'):
        with open(file_name) as file_:
            process_file(file_, assertions)
    assertions = '\n    '.join(assertions)
    res = FILE_TEMPLATE.substitute(assertions_=assertions)
    with open(OUTPUT_DIR+'test.cpp', 'w') as test:
        test.write(res)
    # print(res)


if __name__ == "__main__":
    INPUT_DIR = "src/test_files/"
    OUTPUT_DIR = "tmp/"
    IN_PREFIX = "IN : "
    OUT_PREFIX = "OUT: "
    # Nem túl szép. A output végén mindig lesz egy sortörés, azt pedig itt is
    # meg kell adni. Azt használjuk ki, hogy a compiler konkatenálja a
    # szomszédos c-stringeket:
    ASSERT_TEMPLATE = Template("""
    ASSERT_STREQ(
        "$OUT_""\\n",
        process_text("$IN_").c_str());
    """)
    FILE_TEMPLATE = Template("""
#include <iostream>
#include <string>
#include <sstream>
#include <gtest/gtest.h>
#include "prep_prep_lexer" // ennek előbb kell lennie, mint a többi quex-esnek
#include "snt_snt_lexer" // ennek előbb kell lennie, mint a többi quex-esnek
#include <quex/code_base/multi.i> // a több quex modulhoz
#include <quex/code_base/definitions> // QUEX_CONVERTER_STRING-hez


std::string process_text(std::string text)
{
    prep::Token* token_prep_p = 0x0;
    std::stringstream ss_to_prep(text); // input of prep
    std::stringstream ss_to_snt; // output of prep, input of snt
    prep::prep_lexer lexer_prep(&ss_to_prep, "UTF8");
    for (lexer_prep.receive(&token_prep_p);
         token_prep_p->type_id() != PREP_TERMINATION;
         lexer_prep.receive(&token_prep_p))
    {
        ss_to_snt << QUEX_CONVERTER_STRING(unicode, char)(token_prep_p->get_text());
    }

    std::string res; // output of snt
    snt::Token* token_snt_p = 0x0;
    snt::snt_lexer lexer_snt(&ss_to_snt, "UTF8");
    for (lexer_snt.receive(&token_snt_p);
         token_snt_p->type_id() != SNT_TERMINATION;
         lexer_snt.receive(&token_snt_p))
    {
        res += QUEX_CONVERTER_STRING(unicode, char)(token_snt_p->get_text()) + "\\n";
    }

    return res;
}

TEST(process_text, PositiveNos) { 
    $assertions_
}
 
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
    """)
    main()

