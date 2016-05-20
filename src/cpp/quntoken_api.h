#ifndef QUNTOKEN_API_H
#define QUNTOKEN_API_H


#include <vector>
#include <sstream>
#include <string>


enum OUTPUT_TYPE {
    XML = 0,
    JSON,
    TSV
};


enum MODULE_TYPE {
        PREP = 0,
        SNT,
        SNTCORR,
        TOKEN
};


// type definitions
typedef std::vector<MODULE_TYPE> TYPE_VECTOR;


// functions to print result
void quntoken_print(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
void full_quntoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
/* void tkn_quntoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type); */
void snt_quntoken_print(std::stringstream* fst_input_p, OUTPUT_TYPE out_type);

// functions to get results as stirng
void quntoken_get_str(std::string& result, TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
void full_quntoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
/* void tkn_quntoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type); */
void snt_quntoken_get_str(std::string& result, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);


#endif // QUNTOKEN_API_H

