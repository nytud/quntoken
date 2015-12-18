#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "snt_snt_lexer" // ennek előbb kell lennie, mint a többi quex-esnek
#include <quex/code_base/definitions> // QUEX_CONVERTER_STRING-hez


/* int main(int argc, char** argv) */
int main()
{

    snt::Token*       token_p = 0x0;
    FILE* fh = fopen("input.txt", "rb");
    snt::snt_lexer lexer(fh, "UTF8");

    for (lexer.receive(&token_p); token_p->type_id() != SNT_TERMINATION; lexer.receive(&token_p))
    {
        // típus + token (pretty-zve)
        /* std::cout << token_p->get_string() << std::endl; */
        // csak token, de a pretty iszképeli a \n-, \r-, \t-ket
        /* std::cout << token_p->pretty_char_text() << std::endl; */
        // csak token, nyersen
        std::cout << QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text()) << std::endl;
    }

    return 0;
}

