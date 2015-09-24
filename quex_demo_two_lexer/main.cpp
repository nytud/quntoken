#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

#include "snt_snt_lexer"
#include "tkn_tkn_lexer"
#include <quex/code_base/multi.i>





int main(int argc, char** argv)
{

    // Szentencizálás
    snt::Token*       token_snt_p = 0x0;
    snt::snt_lexer    qlex_snt("input.txt"); // Bemeneti fájl átadása az elemzőnek
    std::stringstream tmp; // stringstream, ezen keresztül kommunikál a két elemző

    for (qlex_snt.receive(&token_snt_p); token_snt_p->type_id() != SNT_TERMINATION; qlex_snt.receive(&token_snt_p))
    {
        if(token_snt_p->type_id() == SNT_ANYCHAR)
        {
            tmp << token_snt_p->get_text().c_str();
        }
        else
        {
            // nyitó tag
            tmp << "<" << token_snt_p->type_id_name() << ">\n";
            // token
            tmp << token_snt_p->get_text().c_str();
            // záró tag
            tmp << "</" << token_snt_p->type_id_name() << ">\n";
        }
    }


    // Tokenizálás
    tkn::Token*       token_tkn_p = 0x0;
    tkn::tkn_lexer    qlex_tkn(&tmp); // strinstream átadása az elemzőnek
    
    for (qlex_tkn.receive(&token_tkn_p); token_tkn_p->type_id() != TKN_TERMINATION; qlex_tkn.receive(&token_tkn_p))
    {
        if(token_tkn_p->type_id() == TKN_ANYCHAR or token_tkn_p->type_id() == TKN_TAG)
        {
            std::cout << token_tkn_p->get_text().c_str();
        }
        else
        {
            // nyitó tag
            std::cout << "<" << token_tkn_p->type_id_name() << ">";
            // token
            std::cout << token_tkn_p->get_text().c_str();
            // záró tag
            std::cout << "</" << token_tkn_p->type_id_name() << ">" << std::endl;
        }
    }

    return 0;
}

