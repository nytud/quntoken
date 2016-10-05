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
        case PREP:
            module<prep::prep_lexer, prep::Token>(PREP_TERMINATION);
            break;
        case HYPHEN:
            module<hyphen::hyphen_lexer, hyphen::Token>(HYPHEN_TERMINATION);
            break;
        case SNT:
            module<snt::snt_lexer, snt::Token>(SNT_TERMINATION);
            break;
        case SNTCORR:
            module<sntcorr::sntcorr_lexer, sntcorr::Token>(SNTCORR_TERMINATION);
            break;
        case TOKEN:
            module<token::token_lexer, token::Token>(TOKEN_TERMINATION);
            break;
        case CONVXML:
            module<convxml::convxml_lexer, convxml::Token>(CONVXML_TERMINATION);
            break;
        case CONVJSON:
            module<convjson::convjson_lexer, convjson::Token>(CONVJSON_TERMINATION);
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

