#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "qtoken_api.h"


int main(int argc, char** argv)
{
    // input file
    if (argc < 2)
    {
        std::cerr << "Missing file name!" << std::endl;
        exit(0);
    }

    // create input stringstream from file:
    std::ifstream in(argv[1]);
    std::stringstream fst_input;
    fst_input << in.rdbuf();

    // 'print' versions
    qtoken_print({PREP, SNT, SNTCORR, SNTCORR, TOKEN}, &fst_input, XML);
    /* full_qtoken_print(&fst_input, XML); */
    /* tkn_qtoken_print(&fst_input, XML); */
    /* snt_qtoken_print(&fst_input, XML); */

    // 'get_str' versions:
    /* std::string result; */
    /* qtoken_get_str(result, {PREP, SNT, SNTCORR, SNTCORR, TOKEN}, &fst_input, XML); */
    /* full_qtoken_get_str(result, &fst_input, XML); */
    /* tkn_qtoken_get_str(result, &fst_input, XML); */
    /* snt_qtoken_get_str(result, &fst_input, XML); */
    /* std::cout << result; */

    std::cout << std::endl;

    return 0;
}

