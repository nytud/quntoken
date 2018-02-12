#ifndef QX_MODULE_QUEUE_H
#define QX_MODULE_QUEUE_H


#include <vector>
#include <sstream>


enum MODULE_TYPE {
        PREPROC = 0,
        HYPHEN,
        SNT,
        SNTCORR,
        TOKEN,
        CONVXML,
        CONVJSON,
        CONVVERT
};


typedef std::vector<MODULE_TYPE> TYPE_VECTOR;
typedef std::vector<std::stringstream*> STREAM_VECTOR;


class QxQueue
{

// members
private:
    TYPE_VECTOR types;
    STREAM_VECTOR streams;
    bool external_last; // jelzi, hogy streams utolso tagjat kell-e letrehozni/torolni

// ctor & dtor
public:
    // ctor:
    QxQueue(TYPE_VECTOR types);

    // dtor:
    ~QxQueue();

// private functions:
private:
    void create_streams();
    void delete_streams();

// public functions:
public:
    void run(std::stringstream* inp, std::stringstream* out=nullptr);

};



#endif // QX_MODULE_QUEUE_H

