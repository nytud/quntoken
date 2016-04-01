#ifndef QX_MODULE_H
#define QX_MODULE_H

#include <sstream>
#include "quntoken_api.h"
#include "prep_prep_lexer"
#include "snt_snt_lexer"
#include "sntcorr_sntcorr_lexer"
#include "token_token_lexer"


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
    QxModule();

    // destructor:
    ~QxModule();

// private functions
private:
    void set_type(MODULE_TYPE t);

    void using_module();

    template <class LEXER, class TOKEN>
    void module(QUEX_TYPE_TOKEN_ID termination);

};

#endif // QX_MODULE_H

