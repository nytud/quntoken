#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <unistd.h>
#include "qxqueue.h"


// globals:
const std::string HELP_STR = "Usage:\n"
                             "\tquntoken [OPTIONS] [-f FORMAT] FILE\n"
                             "Options:\n"
                             "\t-d\t\tRemove division of words at the end of the lines.\n"
                             "\t-f FORMAT\tDefine output format. Valid formats: xml, json, vert. Default format: xml.\n"
                             "\t-V\t\tDisplay version number and exit.\n"
                             "\t-h\t\tDisplay this help and exit";
const std::string VERSION  = "quntoken 1.0.0";


int main(int argc, char** argv) {

    // commandline arguments
    int c;
    int format_flag = 0;
    int hyphen_flag = 0;
    std::string format;
    while( (c = getopt(argc, argv, "hVdf:")) != -1 ) {
        switch (c) {
            case 'f':
                format_flag = 1;
                format = optarg;
                break;
            case 'd':
                hyphen_flag = 1;
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
        else if(format == "vert") { out_type = CONVVERT; }
        else
        {
            std::cerr << "Wrong format. Valid formats: xml, json" << std::endl;
            exit(1);
        }
    }

    // queue
    std::ifstream inp_fstream(input_file);
    std::stringstream inp_sstream;
    inp_sstream << inp_fstream.rdbuf();
    if(hyphen_flag)
    {
        QxQueue q({PREPROC, HYPHEN, SNT, SNTCORR, SNTCORR, TOKEN, out_type});
        q.run(&inp_sstream);
    }
    else
    {
        QxQueue q({PREPROC, SNT, SNTCORR, SNTCORR, TOKEN, out_type});
        q.run(&inp_sstream);
    }

    std::cout << std::endl;

    return 0;
}

