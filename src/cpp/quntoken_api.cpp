#include <iostream>
#include "quntoken_api.h"
#include "qx_module_queue.h"
#include <quex/code_base/multi.i> // több quex modulhoz osszekapcsolasahoz
#include <quex/code_base/definitions> // QUEX_CONVERTER_STRING-hez


// functions to print result
void quntoken_print(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    QxModuleQueue qx_queue(TYPE_VECTOR(types), fst_input_p, out_type);
    std::string result;
    std::cout << qx_queue.get_result(result);
}

void full_quntoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    quntoken_print({PREP, SNT, SNTCORR, SNTCORR, TOKEN}, fst_input_p, out_type);
}

/* void tkn_quntoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type) { */
/*     quntoken_print({PREP, SNT, SNTCORR, SNTCORR, TOKEN}, fst_input_p, out_type); */
/* } */

void snt_quntoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    quntoken_print({PREP, SNT, SNTCORR, SNTCORR}, fst_input_p, out_type);
}


// functions to get results as stirng
void quntoken_get_str(std::string& result, TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    QxModuleQueue qx_queue(TYPE_VECTOR(types), fst_input_p, out_type);
    qx_queue.get_result(result);
}

void full_quntoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    quntoken_get_str(result, {PREP, SNT, SNTCORR, SNTCORR, TOKEN}, fst_input_p, out_type);
}

/* void tkn_quntoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) { */
/*     quntoken_get_str(result, {PREP, SNT, SNTCORR, SNTCORR, TOKEN}, fst_input_p, out_type); */
/* } */

void snt_quntoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type) {
    quntoken_get_str(result, {PREP, SNT, SNTCORR, SNTCORR}, fst_input_p, out_type);
}

