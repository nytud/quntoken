# download gtest: https://github.com/google/googletest/tree/master/googletest
# GTEST_DIR-t esetleg át kell írni a megfelelő környvtárra
GTEST_DIR = $(HOME)/src/googletest/googletest

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -Wall \
			-Wextra \
			-Wconversion \
			-Werror \
			-std=c++11 \
		    # -g \

CXXFLAGS_QUEX = $(CXXFLAGS) \
		    -I$(QUEX_PATH) \
		    -DQUEX_OPTION_ASSERTS_DISABLED \
		    -DQUEX_OPTION_SEND_AFTER_TERMINATION_ADMISSIBLE \
			-DENCODING_NAME='"UTF8"' \
			-DPRINT_TOKEN \
		    # -DQUEX_OPTION_MULTI \

CXXFLAGS_GTEST = $(CXXFLAGS) \
			-pthread \


#####  M A I N   T A R G E T S  ###############################################
all:	lexer tester

lexer:	snt.o main.o
	$(CXX) snt.o main.o -o lexer `icu-config --ldflags`

tester:	tester.o snt.o gtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_GTEST) -lpthread $^ -o $@ `icu-config --ldflags`

clean:
	rm -rf snt_snt*
	rm -rf *.o
	rm -rf *.a
	rm -rf lexer
	rm -rf tester


######  A U X I L I A R Y   T A R G E T S  ####################################
### object files
tester.o: tester.cpp snt_snt_lexer.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_QUEX) -c tester.cpp -o $@

snt.o:	snt_snt_lexer.cpp
	$(CXX) $(CXXFLAGS_QUEX) -c snt_snt_lexer.cpp -o snt.o


main.o:	main.cpp
	$(CXX) $(CXXFLAGS_QUEX) -c main.cpp -o main.o


### quex
snt_snt_lexer.cpp:	snt.qx
	quex -i snt.qx \
		 -o snt::snt_lexer \
		 --token-id-prefix SNT_ \
		 -b 4 \
		 --bet wchar_t \
		 --icu
# Megj1: icu konverter használata:
#   - telepíteni kell a libicu52-t és a libicu-dev-et
#   - quex-nek kell az --icu kapcsoló
#   - g++-nak linkelésnél kell a `icu-config --ldflags`, ami visszaadja a
#     linkernek szánt paramétereket
#   - példa: ../quex/Demo/Cpp/003/-ban
# Megj2: -b 2 is lehetne, de ekkor egyes unicode char. propert.-eket
# használó szabálynál pampog a quex, hogy 2 bájtba nem fér minden bele


### gtest
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS_GTEST) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS_GTEST) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

