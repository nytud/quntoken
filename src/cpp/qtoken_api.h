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


// I M P L E M E N T A T I O N S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void qtoken_print(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    QxModuleQueue qx_queue(TYPE_VECTOR(types), fst_input_p, out_type);
    qx_queue.print_result();
}

void full_qtoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    qtoken_print({PREP, SNT, SNTCORR, SNTCORR, TOKEN}, fst_input_p, out_type);
}

void tkn_qtoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    qtoken_print({PREP, SNT, SNTCORR, SNTCORR, TOKEN}, fst_input_p, out_type);
}

void snt_qtoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    qtoken_print({PREP, SNT, SNTCORR, SNTCORR}, fst_input_p, out_type);
}

void qtoken_get_str(std::string& result, TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    QxModuleQueue qx_queue(TYPE_VECTOR(types), fst_input_p, out_type);
    qx_queue.get_result(result);
}

void full_qtoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    qtoken_get_str(result, {PREP, SNT, SNTCORR, SNTCORR, TOKEN}, fst_input_p, out_type);
}

void tkn_qtoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    qtoken_get_str(result, {PREP, SNT, SNTCORR, SNTCORR, TOKEN}, fst_input_p, out_type);
}

void snt_qtoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    qtoken_get_str(result, {PREP, SNT, SNTCORR, SNTCORR}, fst_input_p, out_type);
}

#endif // QTOKEN_API_H

