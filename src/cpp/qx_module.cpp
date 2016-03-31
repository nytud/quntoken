#ifndef QX_MODULE_H
#define QX_MODULE_H

#include <iostream> // cerr
#include <cstdlib> // exit
#include <map>

enum MODULE_TYPE {
        PREP = 0,
        SNT,
        SNTCORR,
        TOKEN
};


class QxModule {

// friendship
friend class QxModuleQueue;

// private members
private:
    MODULE_TYPE type;
    std::stringstream output;
    std::stringstream* input_p;

// constructors & destructors
public:
    // constructor:
    QxModule()
        : input_p(nullptr) { }

    // destructor:
    ~QxModule() { }

// private functions
private:
    void set_type(MODULE_TYPE t) {
        type = t;
    }

    void using_module() {
        switch(type) {
            case PREP:
                module<prep::prep_lexer, prep::Token>(PREP_TERMINATION);
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
            default:
                std::cerr << "Wrong module type!" << std::endl;
                exit(1);
        }
    }

    template <class LEXER, class TOKEN>
    void module(QUEX_TYPE_TOKEN_ID termination) {
        TOKEN* token_p = 0x0;
        LEXER lexer(input_p, "UTF8");
        for(lexer.receive(&token_p);
            token_p->type_id() != termination;
            lexer.receive(&token_p)) {
            output << QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text());
        }
    }

};

#endif // QX_MODULE_H

/* Megj.: token kinyeresenek modjai: */
/* 1. típus + token, pretty-zve: token_p->get_string() */
/* 2. csak token, pretty-zve:    token_p->pretty_char_text() */
/* 3. nyers token: QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text()) */
/* (a pretty iszképeli a \n-, \r-, \t-ket, mast nem valtoztat) */
// TODO: wstring- / wstringstream-re atirni, hogy a kevesebb konverzioval
// idot nyerjunk! Eleg lenne a kiiras elott konvertalni.

