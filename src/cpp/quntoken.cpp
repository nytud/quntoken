#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <unistd.h>
#include "qxqueue.h"


// globals:
const std::string HELP_STR = "Usage:\n"
                             "\tquntoken [OPTIONS] [-f FORMAT] FILE\n"
                             "Options:\n"
                             "\t-d\t\tRemove division of words at the end of the lines.\n"
                             "\t-m MODULE\tDefine target module. Valid targets: pre, snt, cor and tok. Default module: tok\n"
                             "\t-f FORMAT\tDefine output format. Valid formats: xml, json, vert and raw. Default format: vert.\n"
                             "\t-V\t\tDisplay version number and exit.\n"
                             "\t-h\t\tDisplay this help and exit";
const std::string VERSION  = "quntoken 1.0.0";


int main(int argc, char** argv) {

    // commandline arguments
    int c;
    int format_flag = 0;
    int hyphen_flag = 0;
    int module_flag = 0;
    std::string format;
    std::string mod;
    while( (c = getopt(argc, argv, "hVdm:f:")) != -1 ) {
        switch (c) {
            case 'm':
                module_flag = 1;
                mod = optarg;
                break;
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

    // modules
    std::vector<MODULE_TYPE> modules;
    if (module_flag) { // default
        if(mod == "pre") {
            modules = {PREPROC};
        }
        else if (mod ==  "snt") {
            modules = {PREPROC, SNT};
        }
        else if (mod ==  "cor") {
            modules = {PREPROC, SNT, SNTCORR, SNTCORR};
        }
        else if (mod ==  "tok") {
            modules = {PREPROC, SNT, SNTCORR, SNTCORR, TOKEN};
        }
        else {
            std::cerr << "Wrong module name: " << mod << std::endl;
            std::cerr << "Valid names: 'pre', 'snt', 'cor' and 'tok'" << std::endl;
            exit(1);
        }
    }
    else {
        modules = {PREPROC, HYPHEN, SNT, SNTCORR, SNTCORR, TOKEN};
    }

    // output format
    if (format_flag) {
        if (format == "raw") {
            // skip
        }
        else if (format == "xml") {
            modules.push_back(CONVXML);
        }
        else if (format == "json") {
            modules.push_back(CONVJSON);
        }
        else if (format == "vert") {
            modules.push_back(CONVVERT);
        }
        else {
            std::cerr << "Wrong format. Valid formats: xml, json" << std::endl;
            exit(1);
        }
    }
    else { // default
        modules.push_back(CONVVERT);
    }

    // hyphen
    if (hyphen_flag) {
        modules.insert(modules.begin()+1, HYPHEN);
    }

    // queue
    std::ifstream inp_fstream(input_file);
    std::stringstream inp_sstream;
    inp_sstream << inp_fstream.rdbuf();
    QxQueue q(modules);
    q.run(&inp_sstream);

    std::cout << std::endl;

    return 0;
}

