#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "qxqueue.h"

#include "preproc_Lexer"
#include "hyphen_Lexer"
#include "snt_Lexer"
#include "sntcorr_Lexer"
#include "token_Lexer"
#include "convxml_Lexer"
#include "convjson_Lexer"

#include <quex/code_base/multi.i>
#include <quex/code_base/definitions>



// ctor:
QxQueue::QxQueue(TYPE_VECTOR types) :
    types(types),
    streams(STREAM_VECTOR(types.size()+1, nullptr))
{
    return;
}


// dtor:
QxQueue::~QxQueue()
{
    delete_streams();
    return;
}


// private functions:
void QxQueue::create_streams()
{
    for(int i=1; i<(external_last ? streams.size()-1 : streams.size()); ++i)
    {
        streams[i] = new std::stringstream;
    }
}


void QxQueue::delete_streams()
{
    for(int i=1; i<(external_last ? streams.size()-1 : streams.size()); ++i)
    {
        delete streams[i];
        streams[i] = nullptr;
    }
}


// auxiliary function, not a QxQueue member
template <class LEXER, class TOKEN, QUEX_TYPE_TOKEN_ID termination>
void module(std::stringstream* inp, std::stringstream* out)
{
    TOKEN* token_p = 0x0;
    LEXER lexer(inp, "UTF8");
    for(lexer.receive(&token_p);
        token_p->type_id() != termination;
        lexer.receive(&token_p)) {
        *out << QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text());
    }
}


// public functions:
void QxQueue::run(std::stringstream* inp, std::stringstream* out /*=nullptr*/)
{
    external_last = out ? true : false; // ha meg van adva out, akkor azt nem szabad torolni
    delete_streams();
    streams.front() = inp;
    streams.back() = out;
    create_streams();

    for(int i=0; i<types.size(); ++i)
    {
        switch(types[i])
        {
            case PREPROC:
                module<preproc::Lexer, preproc::Token, preproc_TERMINATION>(streams[i], streams[i+1]);
                break;
            case HYPHEN:
                module<hyphen::Lexer, hyphen::Token, hyphen_TERMINATION>(streams[i], streams[i+1]);
                break;
            case SNT:
                module<snt::Lexer, snt::Token, snt_TERMINATION>(streams[i], streams[i+1]);
                break;
            case SNTCORR:
                module<sntcorr::Lexer, sntcorr::Token, sntcorr_TERMINATION>(streams[i], streams[i+1]);
                break;
            case TOKEN:
                module<token::Lexer, token::Token, token_TERMINATION>(streams[i], streams[i+1]);
                break;
            case CONVXML:
                module<convxml::Lexer, convxml::Token, convxml_TERMINATION>(streams[i], streams[i+1]);
                break;
            case CONVJSON:
                module<convjson::Lexer, convjson::Token, convjson_TERMINATION>(streams[i], streams[i+1]);
                break;
            default:
                std::cerr << "Wrong module type!" << std::endl;
                exit(1);
        }
    }

    if(not external_last) // print to stdout
    {
        std::cout << streams.back()->str();
    }

    return;
}



/* Megj.: token kinyeresenek modjai: */
/* 1. típus + token, pretty-zve: token_p->get_string() */
/* 2. csak token, pretty-zve:    token_p->pretty_char_text() */
/* 3. nyers token: QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text()) */
/* (a pretty iszképeli a \n-, \r-, \t-ket, mast nem valtoztat) */
// TODO: wstring- / wstringstream-re atirni, hogy a kevesebb konverzioval
// idot nyerjunk! Eleg lenne a kiiras elott konvertalni.

