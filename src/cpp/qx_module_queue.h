#ifndef QX_MODULE_QUEUE_H
#define QX_MODULE_QUEUE_H

#include <vector>
#include "qx_module.h"
#include "printer.h"

// type definitions
typedef std::vector<MODULE_TYPE> TYPE_VECTOR;
typedef std::vector<QxModule> MODULE_VECTOR;

class QxModuleQueue {

// friendship
friend void qtoken_print(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);
friend void qtoken_get_str(std::string& result, TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);

// class members
private:
    TYPE_VECTOR types;
    MODULE_VECTOR modules;
    Printer printer;
    bool processed;

// constructors & destructors
private:
    // constructor:
    QxModuleQueue(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type)
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
public:
    ~QxModuleQueue() { }

// private functions:
private:
    void process() {
        for(MODULE_VECTOR::iterator it = modules.begin();
            it != modules.end();
            ++it) {
            it->using_module();
        }
        processed = true;
    }
    
    void get_result(std::string& result) {
        if(!processed) {
            process();
        }
        result = modules.back().output.str();
        printer.convert_tags(result);
    }

    void print_result() {
        if(!processed) {
            process();
        }
        printer << modules.back().output.str();
    }

};


#endif // QX_MODULE_QUEUE_H

