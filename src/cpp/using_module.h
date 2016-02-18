#ifndef USING_MODULE_H
#define USING_MODULE_H


template<class INP, class OUT, class LEX, class TOK>
void using_module(INP input, OUT & output, QUEX_TYPE_TOKEN_ID termination) {
    TOK * token_p = 0x0;
    LEX lexer(input, "UTF8");
    for(lexer.receive(&token_p);
        token_p->type_id() != termination;
        lexer.receive(&token_p)) {
        output << QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text());
    }
}

#endif // USING_MODULE_H

