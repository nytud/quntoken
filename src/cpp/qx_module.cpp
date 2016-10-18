#include "qx_module.h"
#include <iostream> // cerr
#include <cstdlib> // exit


// constructor:
QxModule::QxModule() : input_p(nullptr) { }

// destructor:
QxModule::~QxModule() { }

// private functions
void QxModule::set_type(MODULE_TYPE t) {
    type = t;
}

void QxModule::set_input_p(std::stringstream * inp_p) {
    input_p = inp_p;
}

std::stringstream* QxModule::get_output_p() {
    return &output;
}


void QxModule::using_module() {
    switch(type) {
        case PREPROC:
            module<preproc::Lexer, preproc::Token>(preproc_TERMINATION);
            break;
        case HYPHEN:
            module<hyphen::Lexer, hyphen::Token>(hyphen_TERMINATION);
            break;
        case SNT:
            module<snt::Lexer, snt::Token>(snt_TERMINATION);
            break;
        case SNTCORR:
            module<sntcorr::Lexer, sntcorr::Token>(sntcorr_TERMINATION);
            break;
        case TOKEN:
            module<token::Lexer, token::Token>(token_TERMINATION);
            break;
        case CONVXML:
            module<convxml::Lexer, convxml::Token>(convxml_TERMINATION);
            break;
        case CONVJSON:
            module<convjson::Lexer, convjson::Token>(convjson_TERMINATION);
            break;
        default:
            std::cerr << "Wrong module type!" << std::endl;
            exit(1);
    }
}

template <class LEXER, class TOKEN>
void QxModule::module(QUEX_TYPE_TOKEN_ID termination) {
    TOKEN* token_p = 0x0;
    LEXER lexer(input_p, "UTF8");
    for(lexer.receive(&token_p);
        token_p->type_id() != termination;
        lexer.receive(&token_p)) {
        output << QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text());
    }
}


/* Megj.: token kinyeresenek modjai: */
/* 1. típus + token, pretty-zve: token_p->get_string() */
/* 2. csak token, pretty-zve:    token_p->pretty_char_text() */
/* 3. nyers token: QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text()) */
/* (a pretty iszképeli a \n-, \r-, \t-ket, mast nem valtoztat) */
// TODO: wstring- / wstringstream-re atirni, hogy a kevesebb konverzioval
// idot nyerjunk! Eleg lenne a kiiras elott konvertalni.

