#include <cstdlib>
#include <iostream>
#include "qxqueue.h"
#include "qx_module.h"
#include <sstream>
#include <string>
#include <vector>


// constructor:
QxQueue::QxQueue(TYPE_VECTOR types, std::stringstream* fst_input_p)
: modules(MODULE_VECTOR(types.size())), processed(false) {
    // empty queue, do nothing
    if(types.empty())
    {
        std::cerr << "Empty module vector!" << std::endl;
        exit(1);
    }
    // fill the modules vector
    std::stringstream* ss_p = nullptr;
    MODULE_VECTOR::iterator it = modules.begin();
    for (auto type : types)
    {
        it->set_type(type);
        // setup input pointers
        if(ss_p) {
            it->set_input_p(ss_p);
        }
        ss_p = it->get_output_p();
        ++it;
    }
    // empty input stream:
    if(fst_input_p->rdbuf()->in_avail() == 0)
    {
        processed = true;
    }
    // setup input pointer of the first module
    modules.front().set_input_p(fst_input_p);
}

// destructor:
QxQueue::~QxQueue() {}

// private functions:
void QxQueue::process()
{
    for(MODULE_VECTOR::iterator it = modules.begin();
        it != modules.end();
        ++it)
    {
        it->using_module();
    }
    processed = true;
}

std::string& QxQueue::get_result(std::string& result)
{
    if(!processed)
    {
        process();
    }
    result = modules.back().get_output_p()->str();
    return result;
}

void QxQueue::print_result()
{
    if(!processed)
    {
        process();
    }
    std::cout << modules.back().get_output_p()->str();
}

