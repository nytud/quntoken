CC := g++ -Wall -Werror -DQUEX_OPTION_MULTI -I$(QUEX_PATH) -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_SEND_AFTER_TERMINATION_ADMISSIBLE

lexer:			snt.o tkn.o main.o
	g++ main.o snt.o tkn.o -o lexer

tkn.o:			tkn_tkn_lexer.cpp
	$(CC) -c tkn_tkn_lexer.cpp -o tkn.o

snt.o:			snt_snt_lexer.cpp
	$(CC) -c snt_snt_lexer.cpp -o snt.o

main.o:			main.cpp
	$(CC) -c main.cpp -o main.o

tkn_tkn_lexer.cpp:	tkn.qx
	quex -i tkn.qx -o tkn::tkn_lexer --token-id-prefix TKN_

snt_snt_lexer.cpp:	snt.qx
	quex -i snt.qx -o snt::snt_lexer --token-id-prefix SNT_

clean:
	rm -rf snt_snt*
	rm -rf tkn_tkn*
	rm -rf *.o
	rm -rf lexer

