#include <iostream>
#include "quntoken_api.h"
#include "qxqueue.h"
#include <quex/code_base/multi.i> // több quex modulhoz osszekapcsolasahoz
#include <quex/code_base/definitions> // QUEX_CONVERTER_STRING-hez


// functions to print result
void quntoken_print(TYPE_VECTOR types, std::stringstream* fst_input_p) {
    QxQueue qx_queue(TYPE_VECTOR(types), fst_input_p);
    qx_queue.print_result();
}


// functions to get results as stirng
void quntoken_get_str(std::string& result, TYPE_VECTOR types, std::stringstream* fst_input_p) {
    QxQueue qx_queue(TYPE_VECTOR(types), fst_input_p);
    qx_queue.get_result(result);
}

