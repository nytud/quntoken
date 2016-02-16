#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "printer.h"
#include "using_module.h"
#include "prep_prep_lexer" // a *_lexer-eknek elobb kell lenniuk, mint a tobbi quex-esnek
#include "snt_snt_lexer"
#include "sntcorr_sntcorr_lexer"
#include "token_token_lexer"
#include <quex/code_base/multi.i> // több quex modulhoz osszekapcsolasahoz
#include <quex/code_base/definitions> // QUEX_CONVERTER_STRING-hez


int main(int argc, char** argv)
{
    // input file
    if (argc < 2)
    {
        std::cerr << "Missing file name!" << std::endl;
        exit(0);
    }
    FILE* fh = fopen(argv[1], "rb");
    Printer xml_printer(XML);

    std::stringstream ss1; // output of prepocessing, input of snt processing
    std::stringstream ss2; // output of snt modul, input of sntcorr modul
    std::stringstream ss3; // output of sntcorr1, input of sntcorr2
    std::stringstream ss4; // output of sntcorr modul, input of token modul
    using_module<FILE*, std::stringstream, prep::prep_lexer, prep::Token>(fh, ss1, PREP_TERMINATION);
    using_module<std::stringstream*, std::stringstream, snt::snt_lexer, snt::Token>(&ss1, ss2, SNT_TERMINATION);
    using_module<std::stringstream*, std::stringstream, sntcorr::sntcorr_lexer, sntcorr::Token>(&ss2, ss3, SNTCORR_TERMINATION);
    using_module<std::stringstream*, std::stringstream, sntcorr::sntcorr_lexer, sntcorr::Token>(&ss3, ss4, SNTCORR_TERMINATION);
    using_module<std::stringstream*, Printer, token::token_lexer, token::Token>(&ss4, xml_printer, TOKEN_TERMINATION);

    // teszteles: test-tel tetszoleges stringstream kiirathato:
    /* std::cout << std::endl << "---------- T E S T ----------" << std::endl; */
    /* std::string test = ss1.str(); */
    /* std::cout << xml_printer.convert_tags(test); */

    std::cout << std::endl;

    return 0;
}

/* Megj.: token kinyeresenek modjai: */
/* 1. típus + token, pretty-zve: token_p->get_string() */
/* 2. csak token, pretty-zve:    token_p->pretty_char_text() */
/* 3. nyers token: QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text()) */
/* (a pretty iszképeli a \n-, \r-, \t-ket, mast nem valtoztat) */

