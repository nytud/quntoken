#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <unistd.h>
#include "quntoken_api.h"


// globals:
const std::string HELP_STR = "Usage:\n"
                             "\tquntoken [OPTION] FILE\n"
                             "Options:\n"
                             "\t-f FORMAT\toutput format; valid formats: xml, json\n"
                             "\t-V\t\tdisplay version number\n"
                             "\t-h\t\tdisplay this help and exit";
const std::string VERSION  = "quntoken 0.2.0";


int main(int argc, char** argv) {

    // commandline arguments
    int c;
    int format_flag = 0;
    std::string format;
    while( (c = getopt(argc, argv, "hVf:")) != -1 ) {
        switch (c) {
            case 'f':
                format_flag = 1;
                format = optarg;
                break;
            case 'h':
                std::cout << HELP_STR << std::endl;
                exit(0);
                break;
            case 'V':
                std::cout << VERSION << std::endl;
                exit(0);
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
        exit(1);
    }

    // output format
    MODULE_TYPE out_type = CONVXML;
    if(format_flag)
    {
        if(format == "xml") {}
        else if(format == "json") { out_type = CONVJSON; }
        else
        {
            std::cerr << "Wrong format. Valid formats: xml, json" << std::endl;
            exit(1);
        }
    }

    // call quntoken
    std::ifstream inp_fstream(input_file);
    std::stringstream inp_sstream;
    inp_sstream << inp_fstream.rdbuf();
    quntoken_print({PREP, SNT, SNTCORR, SNTCORR, TOKEN, out_type}, &inp_sstream);

    std::cout << std::endl;

    return 0;
}

