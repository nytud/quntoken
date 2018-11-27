#! /bin/bash


cat - \
    | sed \
        -e 's/🀰/SNT_OPEN/g' \
        -e 's/🀱/SNT_CLOSE/g' \
        -e 's/🀲/WS_OPEN/g' \
        -e 's/🀳/WS_CLOSE/g' \
        -e 's/🀴/WORD_OPEN/g' \
        -e 's/🀵/WORD_CLOSE/g' \
        -e 's/🀶/PUNCT_OPEN/g' \
        -e 's/🀷/PUNCT_CLOSE/g'
