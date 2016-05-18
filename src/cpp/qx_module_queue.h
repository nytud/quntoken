#ifndef QX_MODULE_QUEUE_H
#define QX_MODULE_QUEUE_H


#include <sstream>
#include <string>
#include <vector>
#include "converter.h"
#include "qx_module.h"
#include "quntoken_api.h"


// type definitions
typedef std::vector<QxModule> MODULE_VECTOR;


class QxModuleQueue {

// class members
private:
    TYPE_VECTOR types;
    MODULE_VECTOR modules;
    Converter* converter_p;
    bool processed;

// constructors & destructors
public:
    // constructor:
    QxModuleQueue(TYPE_VECTOR types, std::stringstream* fst_input_p, OUTPUT_TYPE out_type);

    // destructor:
    ~QxModuleQueue();

// private functions:
private:
    void process();

// public functions:
public:
    void get_result(std::string& result);

    void print_result();

};


#endif // QX_MODULE_QUEUE_H

