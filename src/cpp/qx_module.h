#ifndef QX_MODULE_H
#define QX_MODULE_H

#include <sstream>
#include "quntoken_api.h"
#include "prep_prep_lexer"
#include "snt_snt_lexer"
#include "sntcorr_sntcorr_lexer"
#include "token_token_lexer"
#include "convxml_convxml_lexer"
#include "convjson_convjson_lexer"


class QxModule {

// private members
private:
    MODULE_TYPE type;
    std::stringstream output;
    std::stringstream* input_p;

// constructors & destructors
public:
    // constructor:
    QxModule();

    // destructor:
    ~QxModule();

// private functions
private:
    template <class LEXER, class TOKEN>
    void module(QUEX_TYPE_TOKEN_ID termination);

// public functions
public:
    void set_type(MODULE_TYPE t);
    void set_input_p(std::stringstream* inp_p);
    std::stringstream* get_output_p();
    void using_module();

};

#endif // QX_MODULE_H

