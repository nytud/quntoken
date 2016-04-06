#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <unistd.h>
#include "quntoken_api.h"


std::map<std::string, OUTPUT_TYPE> create_format_map();


int main(int argc, char** argv) {

    // commandline arguments
    int c;
    int format_flag = 0;
    std::string format;
    while( (c = getopt(argc, argv, "f:")) != -1 ) {
        switch (c) {
            case 'f':
                format_flag = 1;
                format = optarg;
                break;
            default:
                exit(1);
                break;
        }
    }

    // input file
    char* input_file;
    if(optind < argc) {
        input_file = argv[optind];
    }
    else {
        std::cerr << "Missing file name!" << std::endl;
        exit(0);
    }

    // output format
    std::map<std::string, OUTPUT_TYPE> format_map = create_format_map();
    OUTPUT_TYPE out_type;
    try {
        out_type = (format_flag ? format_map.at(format) : XML );
    }
    catch(const std::out_of_range & err) {
        std::cerr << "Wrong format. Valid formats: xml, json" << std::endl;
        exit(1);
    }

    // call quntoken
    std::ifstream inp_fstream(input_file);
    std::stringstream inp_sstream;
    inp_sstream << inp_fstream.rdbuf();
    quntoken_print({PREP, SNT, SNTCORR, SNTCORR, TOKEN}, &inp_sstream, out_type);

    std::cout << std::endl;

    return 0;
}



std::map<std::string, OUTPUT_TYPE> create_format_map() {
    std::map<std::string, OUTPUT_TYPE> format_map;
    format_map["json"] = JSON;
    format_map["xml"] = XML;
    return format_map;
}

