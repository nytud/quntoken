#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "snt_snt_lexer"


/* int main(int argc, char** argv) */
int main()
{

    snt::Token*       token_p = 0x0;
    FILE* fh = fopen("input.txt", "rb");
    snt::snt_lexer lexer(fh, "UTF8");

    for (lexer.receive(&token_p); token_p->type_id() != SNT_TERMINATION; lexer.receive(&token_p))
    {
        // csak a token szövegét használjuk fel, a típus nem érdekes (a szöveg
        // már a quex-ben dekorálva lett)
        // std::cout << token_p->type_id_name() << "\t" << token_p->pretty_char_text() << std::endl;
        std::cout << token_p->pretty_char_text() << std::endl;
    }

    return 0;
}

