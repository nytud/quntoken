#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

#include "chr_chr_lexer"





int main(int argc, char** argv)
{

    chr::Token*       token_p = 0x0;
    // chr::chr_lexer    lexer("input.txt"); ez is fordul, de rossz kimenetet ad
    FILE* fh = fopen("input.txt", "rb");
    chr::chr_lexer lexer(fh, "UTF8");

    for (lexer.receive(&token_p); token_p->type_id() != CHR_TERMINATION; lexer.receive(&token_p))
    {
        // nyitó tag
        std::cout << "<" << token_p->type_id_name() << ">";
        // token
        std::cout << token_p->pretty_char_text();
        // záró tag
        std::cout << "</" << token_p->type_id_name() << ">" << std::endl;
    }

    return 0;
}

