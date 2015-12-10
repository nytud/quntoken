COMPILER = g++
COMPILER_FLAG = -Wall -Werror -Wconversion\
				-std=c++11 \
			    -c \
			    -I$(QUEX_PATH) \
			    -DQUEX_OPTION_ASSERTS_DISABLED \
			    -DQUEX_OPTION_SEND_AFTER_TERMINATION_ADMISSIBLE \
				-DENCODING_NAME='"UTF8"' \
				-DPRINT_TOKEN \
			    # -DQUEX_OPTION_MULTI \

# tester:					snt.o main.o tests.cpp
# 	$(COMPILER) $(COMPILER_FLAG) -l pthread tests.cpp -o tester

lexer:					snt.o main.o
	$(COMPILER) snt.o main.o -o lexer `icu-config --ldflags`


snt.o:					snt_snt_lexer.cpp
	$(COMPILER) $(COMPILER_FLAG) snt_snt_lexer.cpp -o snt.o


main.o:					main.cpp
	$(COMPILER) $(COMPILER_FLAG) main.cpp -o main.o


# itt -b 2 is lehetne, de ekkor egyes unicode char. propert.-eket
# használó szabálynál pampog a quex, hogy 2 bájtba nem fér minden bele
snt_snt_lexer.cpp:		snt.qx
	quex -i snt.qx \
		 -o snt::snt_lexer \
		 --token-id-prefix SNT_ \
		 -b 4 \
		 --bet wchar_t \
		 --icu


clean:
	rm -rf snt_snt*
	rm -rf *.o
	rm -rf lexer

# icu konverter használata:
#   - telepíteni kell a libicu52-t és a libicu-dev-et
#   - quex-nek kell az --icu kapcsoló
#   - g++-nak linkelésnél kell a `icu-config --ldflags`, ami visszaadja a
#     linkernek szánt paramétereket
#   - példa: ../quex/Demo/Cpp/003/-ban

