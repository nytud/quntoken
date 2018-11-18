quex --bet wchar_t -i definitions.qx abbreviations_orig-hu.qx preproc.qx -o preprocLexer --token-id-prefix preproc_ &
quex --bet wchar_t -i definitions.qx abbreviations_orig-hu.qx hyphen.qx -o hyphenLexer --token-id-prefix hyphen_ &
quex --bet wchar_t -i definitions.qx abbreviations_orig-hu.qx snt.qx -o sntLexer --token-id-prefix snt_ &
quex --bet wchar_t -i definitions.qx abbreviations_orig-hu.qx sntcorr.qx -o sntcorrLexer --token-id-prefix sntcorr_ &
quex --bet wchar_t -i definitions.qx abbreviations_orig-hu.qx token.qx -o tokenLexer --token-id-prefix token_ &
quex --bet wchar_t -i definitions.qx abbreviations_orig-hu.qx convxml.qx -o convxmlLexer --token-id-prefix convxml_ &
quex --bet wchar_t -i definitions.qx abbreviations_orig-hu.qx convjson.qx -o convjsonLexer --token-id-prefix convjson_ &
wait


g++ -ggdb -Wall -Werror -pedantic -I./ -I$QUEX_PATH -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_POSIX -std=c++11 -DWITH_UTF8 preprocLexer.cpp preproc_main.cpp -o preproc &
g++ -ggdb -Wall -Werror -pedantic -I./ -I$QUEX_PATH -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_POSIX -std=c++11 -DWITH_UTF8 hyphenLexer.cpp hyphen_main.cpp -o hyphen &
g++ -ggdb -Wall -Werror -pedantic -I./ -I$QUEX_PATH -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_POSIX -std=c++11 -DWITH_UTF8 sntLexer.cpp snt_main.cpp -o snt &
g++ -ggdb -Wall -Werror -pedantic -I./ -I$QUEX_PATH -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_POSIX -std=c++11 -DWITH_UTF8 sntcorrLexer.cpp sntcorr_main.cpp -o sntcorr &
g++ -ggdb -Wall -Werror -pedantic -I./ -I$QUEX_PATH -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_POSIX -std=c++11 -DWITH_UTF8 tokenLexer.cpp token_main.cpp -o token &
g++ -ggdb -Wall -Werror -pedantic -I./ -I$QUEX_PATH -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_POSIX -std=c++11 -DWITH_UTF8 convxmlLexer.cpp convxml_main.cpp -o convxml &
g++ -ggdb -Wall -Werror -pedantic -I./ -I$QUEX_PATH -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_POSIX -std=c++11 -DWITH_UTF8 convjsonLexer.cpp convjson_main.cpp -o convjson &
