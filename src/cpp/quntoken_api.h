#ifndef QTOKEN_API_H
#define QTOKEN_API_H

#include "prep_prep_lexer"
#include "snt_snt_lexer"
#include "sntcorr_sntcorr_lexer"
#include "token_token_lexer"
#include "qx_module_queue.h"
#include <quex/code_base/multi.i> // több quex modulhoz osszekapcsolasahoz
#include <quex/code_base/definitions> // QUEX_CONVERTER_STRING-hez


// functions to print result
void qtoken_print(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
void full_qtoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
void tkn_qtoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
void snt_qtoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type);

// functions to get results as stirng
void qtoken_get_str(std::string& result, TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
void full_qtoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
void tkn_qtoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
void snt_qtoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);


#endif // QTOKEN_API_H

