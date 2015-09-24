COMPILER = g++
COMPILER_FLAG = -Wall -Werror -Wconversion\
			     -c \
			    -I$(QUEX_PATH) \
			    -DQUEX_OPTION_ASSERTS_DISABLED \
			    -DQUEX_OPTION_SEND_AFTER_TERMINATION_ADMISSIBLE \
				-DENCODING_NAME='"UTF8"' \
				-DPRINT_TOKEN \
			    # -DQUEX_OPTION_MULTI \


lexer:					chr.o main.o
	$(COMPILER) chr.o main.o -o lexer `icu-config --ldflags`


chr.o:					chr_chr_lexer.cpp
	$(COMPILER) $(COMPILER_FLAG) chr_chr_lexer.cpp -o chr.o


main.o:					main.cpp
	$(COMPILER) $(COMPILER_FLAG) main.cpp -o main.o


# itt -b 2 is lehetne, de ekkor egyes unicode char. propert.-eket
# használó szabálynál pampog a quex, hogy 2 bájtba nem fér minden bele
chr_chr_lexer.cpp:		char.qx
	quex -i char.qx \
		 -o chr::chr_lexer \
		 --token-id-prefix CHR_ \
		 -b 4 \
		 --icu


clean:
	rm -rf chr_chr*
	rm -rf *.o
	rm -rf lexer

# icu konverter használata:
#   - telepíteni kell a libicu52-t és a libicu-dev-et
#   - quex-nek kell az --icu kapcsoló
#   - g++-nak linkelésnél kell a `icu-config --ldflags`, ami visszaadja a
#     linkernek szánt paramétereket
#   - példa: ../quex/Demo/Cpp/003/-ban

