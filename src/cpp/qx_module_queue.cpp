#include <cstdlib>
#include <iostream>
#include "qx_module_queue.h"
#include "qx_module.h"
#include <sstream>
#include <string>
#include <vector>


// constructor:
QxModuleQueue::QxModuleQueue(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type)
: modules(MODULE_VECTOR(types.size())), processed(false) {
    // empty queue, do nothing
    if(types.empty()) {
        std::cerr << "Empty module vector!" << std::endl;
        exit(1);
    }
    switch(out_type) {
        case XML:
            converter_p = new XmlConverter();
            break;
        case JSON:
            converter_p = new JsonConverter();
            break;
        default:
            // TODO!
            break;
    }
    // fill the modules vector
    std::stringstream* ss_p = nullptr;
    MODULE_VECTOR::iterator it = modules.begin();
    for (auto type : types) {
        it->set_type(type);
        // setup input pointers
        if(ss_p) {
            it->set_input_p(ss_p);
        }
        ss_p = it->get_output_p();
        ++it;
    }
    // empty input stream:
    if(fst_input_p->rdbuf()->in_avail() == 0) {
        processed = true;
    }
    // setup input pointer of the first module
    modules.front().set_input_p(fst_input_p);
}

// destructor:
QxModuleQueue::~QxModuleQueue() {
    delete converter_p;
}

// private functions:
void QxModuleQueue::process() {
    for(MODULE_VECTOR::iterator it = modules.begin();
        it != modules.end();
        ++it) {
        it->using_module();
    }
    processed = true;
}

std::string& QxModuleQueue::get_result(std::string& result) {
    if(!processed) {
        process();
    }
    result = modules.back().get_output_p()->str();
    converter_p->convert_tags(result);
    return result;
}

