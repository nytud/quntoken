#include "qx_module_queue.h"
#include "qx_module.h"
#include "printer.h"
#include <sstream>
#include <string>
#include <vector>


// constructor:
QxModuleQueue::QxModuleQueue(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type)
: types(types), modules(MODULE_VECTOR(types.size())), printer(Printer(out_type)), processed(false) {
    // empty queue, do nothing
    if(types.empty()) {
        return;
    }
    // fill the modules vector
    std::stringstream* ss_p = nullptr;
    MODULE_VECTOR::iterator it = modules.begin();
    for (auto type : types) {
        it->set_type(type);
        // setup input pointers
        if(ss_p) {
            it->input_p = ss_p;
        }
        ss_p = &(it->output);
        ++it;
    }
    // setup input pointer of the first module
    modules.front().input_p = fst_input_p;
}

// destructor:
QxModuleQueue::~QxModuleQueue() { }

// private functions:
void QxModuleQueue::process() {
    for(MODULE_VECTOR::iterator it = modules.begin();
        it != modules.end();
        ++it) {
        it->using_module();
    }
    processed = true;
}

void QxModuleQueue::get_result(std::string& result) {
    if(!processed) {
        process();
    }
    result = modules.back().output.str();
    printer.convert_tags(result);
}

void QxModuleQueue::print_result() {
    if(!processed) {
        process();
    }
    printer << modules.back().output.str();
}

