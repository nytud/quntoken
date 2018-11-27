#include <iostream>
#include MYLEXER
#include <quex/code_base/buffer/lexatoms/converter/iconv/Converter_IConv>
#include <quex/code_base/buffer/lexatoms/converter/iconv/Converter_IConv.i>


int main(int argc, char** argv) {
    using namespace quex;

    Token*                 token;
    LEXER_CLASS*           lexer;
    QUEX_NAME(Converter)*  converter = QUEX_NAME(Converter_IConv_new)("UTF8", NULL);
    QUEX_NAME(ByteLoader)* loader = QUEX_NAME(ByteLoader_POSIX_new)(0); /* 0 = stdin */
    QUEX_NAME(ByteLoader_seek_disable)(loader);
    lexer = LEXER_CLASS::from_ByteLoader(loader, converter);

    for(lexer->receive(&token);
            token->type_id() != QUEX_TKN_TERMINATION;
            lexer->receive(&token)) {
        std::cout << QUEX_CONVERTER_STRING(unicode, char)(token->get_text());
        /* std::cout << QUEX_CONVERTER_STRING(unicode, char)(token->get_text()).c_str(); */
    }

    delete lexer;
    return 0;
}
