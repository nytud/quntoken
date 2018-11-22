#include <iostream>
#include <string>
#include <sstream>
#include <gtest/gtest.h>
#include "qxqueue.h"


std::string prepTest(std::string text) {
    std::stringstream inp(text);
    std::stringstream out;
    QxQueue q({PREPROC, CONVXML});
    q.run(&inp, &out);
    return out.str();
}


std::string hyphenTest(std::string text) {
    std::stringstream inp(text);
    std::stringstream out;
    QxQueue q({PREPROC, HYPHEN, CONVXML});
    q.run(&inp, &out);
    return out.str();
}


std::string sntTest(std::string text) {
    std::stringstream inp(text);
    std::stringstream out;
    QxQueue q({PREPROC, SNT, CONVXML});
    q.run(&inp, &out);
    return out.str();
}


std::string sntcorrTest(std::string text) {
    std::stringstream inp(text);
    std::stringstream out;
    QxQueue q({PREPROC, SNT, SNTCORR, SNTCORR, CONVXML});
    q.run(&inp, &out);
    return out.str();
}

std::string tokenTest(std::string text) {
    std::stringstream inp(text);
    std::stringstream out;
    QxQueue q({PREPROC, SNT, SNTCORR, SNTCORR, TOKEN, CONVXML});
    q.run(&inp, &out);
    return out.str();
}


${TESTS}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// vim:set syntax=cpp:

