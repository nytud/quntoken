#include <stdio.h>
#include <sntcorrLexer>
#include <quex/code_base/buffer/lexatoms/converter/iconv/Converter_IConv>
#include <quex/code_base/buffer/lexatoms/converter/iconv/Converter_IConv.i>

#define LEXER_CLASS sntcorrLexer


int main(int argc, char** argv)
{
    using namespace quex;

    Token*                 token;
    LEXER_CLASS*           qlex;
    QUEX_NAME(Converter)*  converter = QUEX_NAME(Converter_IConv_new)("UTF8", NULL);
    QUEX_NAME(ByteLoader)* loader = QUEX_NAME(ByteLoader_POSIX_new)(0); /* 0 = stdin */

    QUEX_NAME(ByteLoader_seek_disable)(loader);

    qlex = LEXER_CLASS::from_ByteLoader(loader, converter);

    do {
        qlex->receive(&token);
        printf("%s", QUEX_CONVERTER_STRING(unicode, char)(token->get_text()).c_str());
    } while( token->_id != QUEX_TKN_TERMINATION);

    delete qlex;
    return 0;
}
