#ifndef QUNTOKEN_API_H
#define QUNTOKEN_API_H

#include <vector>
#include <sstream>
#include <string>


enum MODULE_TYPE {
        PREP = 0,
        SNT,
        SNTCORR,
        TOKEN,
        CONVXML,
        CONVJSON
};


// type definitions
typedef std::vector<MODULE_TYPE> TYPE_VECTOR;


// functions to print result
void quntoken_print(TYPE_VECTOR types, std::stringstream* fst_input_p);

// functions to get results as stirng
void quntoken_get_str(std::string& result, TYPE_VECTOR types, std::stringstream* fst_input_p);


#endif // QUNTOKEN_API_H

