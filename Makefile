# CONFIGURATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Fejlesztoi konfiguracio megadasa (milyen modulok es tesztek forduljanak).
# Uj valtozat keszitesenel egy uj config fajlt kell kesziteni es azt
# megadni a default helyett. Peldaul:
#   make clean
#   make all CONFIG_FILE=alter_config.mk
CONFIG_FILE 	:= default_config.mk
include $(CONFIG_FILE)


# NAMES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
NAME			:= quntoken
QXSUFFIX		:= _Lexer
CLASS			:= qxqueue


# DIRECTORIES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BIN				:= bin
LIB				:= lib
TMP				:= tmp
SRC				:= src
SRC_CPP			:= $(SRC)/cpp
SRC_SCRIPT		:= $(SRC)/scripts
QUEX			:= quex
GTEST			:= googletest/googletest
GTEST_HEADERS	:= $(GTEST)/include/gtest/*.h $(GTEST)/include/gtest/internal/*.h


# FILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
PROGBIN	    	:= $(BIN)/$(NAME)
PROGOBJ	    	:= $(TMP)/$(NAME).o
TESTBIN			:= $(BIN)/test_$(NAME)
TESTOBJ			:= $(TESTBIN:$(BIN)/%=$(TMP)/%.o)
TESTCPP			:= $(TESTOBJ:%.o=%.cpp)
LIBRARY			:= $(LIB)/lib$(NAME).a
CLASSOBJS		:= $(CLASS:%=$(TMP)/%.o)
CPPOBJS			:= $(PROGOBJ) $(CLASSOBJS)
QXOBJS			:= $(QXLEXERS:%=$(TMP)/%$(QXSUFFIX).o)
QXCPPS			:= $(QXLEXERS:%=$(TMP)/%$(QXSUFFIX).cpp)
ABBRLEXER		:= $(TMP)/$(basename $(notdir $(ABBREVIATIONS))).qx
QXDEPS			:= $(SRC_QX)/$(DEFINITIONS) $(ABBRLEXER)


# COMPILERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# quex command
QXCMD = export QUEX_PATH=$(QUEX) ; $(QUEX)/quex-exe.py

# quex flags
QXFLAGS = \
	-i $^ \
	--odir $(TMP)/ \
	-o $(@:$(TMP)/%$(QXSUFFIX).cpp=%::$(subst _,,$(QXSUFFIX))) \
	--token-id-prefix $(@:$(TMP)/%$(QXSUFFIX).cpp=%_) \
	-b 4 \
	--bet wchar_t \
	--token-policy queue \
	--iconv

# c preprocesszor
CPPFLAGS +=	-isystem $(GTEST)/include

# g++ kapcsoloi altalaban
CXXFLAGS += \
	-Wall \
	-Wextra \
	-Wconversion \
	-pedantic \
	-Werror -Wno-sign-compare \
	-o $@ \
	-std=c++11 \
	-DQUEX_OPTION_ASSERTS_DISABLED \
	-DQUEX_OPTION_SEND_AFTER_TERMINATION_ADMISSIBLE \
	-DQUEX_OPTION_MULTI \
	-DQUEX_SETTING_BUFFER_SIZE=2097152 \
	-I./ \
	-I$(TMP)/ \
	-I$(QUEX) \
	-I$(SRC_CPP)
	# -g
	# -DENCODING_NAME='"UTF8"' \
	# -DQUEX_OPTION_INFORMATIVE_BUFFER_OVERFLOW_MESSAGE \
	# -DQUEX_OPTION_POSIX \
	# -liconv \


# g++ kapcsoloi gtest-es fajlokhoz
CXXFLAGS_GTEST	= $(CXXFLAGS) -pthread


# TARGETS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

all: common $(PROGBIN) $(TESTBIN) test

.PHONY: all


common:
	$(MAKE) -j $(QXCPPS)
	$(MAKE) -j $(QXOBJS)

.PHONY: common


test: $(TESTBIN)
	./$(TESTBIN) 2>/dev/null

.PHONY: test


$(PROGBIN): $(TMP)/$(NAME).o $(LIBRARY)
	$(CXX) $< -L$(LIB) -static-libstdc++ -static -lquntoken -o $@


$(TESTBIN): $(TESTOBJ) $(LIBRARY) $(TMP)/gtest.a
	$(CXX) $(CXXFLAGS_GTEST) -lpthread -static-libstdc++ $^


$(TESTOBJ): $(TESTCPP) $(SRC_CPP)/*.h $(QXCPPS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<


$(TESTCPP): $(SRC_SCRIPT)/test.tmpl2cpp.py $(TESTCPP:$(TMP)%=$(SRC_CPP)%) $(TEST_FILES)
	./$< -t $(word 2, $^) -d $(TEST_FILES) -o $@


$(LIBRARY): $(QXOBJS) $(CLASSOBJS)
	$(AR) rscv $@ $^


$(CPPOBJS): $(TMP)/%.o: $(SRC_CPP)/%.cpp $(SRC_CPP)/*.h
	$(CXX) $(CXXFLAGS) -c $<


$(QXOBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<


$(QXCPPS): $(TMP)/%$(QXSUFFIX).cpp: $(QXDEPS) $(SRC_QX)/%.qx
	$(QXCMD) $(QXFLAGS)


# abbreviations
$(ABBRLEXER): $(SRC_SCRIPT)/generate_abbrev.qx.py $(ABBREVIATIONS)
	./$< -d $(word 2, $^) -o $@


# gtest
$(TMP)/gtest-all.o: $(GTEST)/src/*.cc $(GTEST)/src/*.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) -I$(GTEST) $(CXXFLAGS_GTEST) -c $(GTEST)/src/gtest-all.cc

$(TMP)/gtest.a : $(TMP)/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^


# clean
clean:
	@rm -fv  $(PROGBIN)
	@rm -fv  $(TESTBIN)
	@rm -rfv $(LIBRARY)
	@rm -rfv $(TMP)/*

.PHONY: clean


# install requirements ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
prereq: create_dirs install_quex
.PHONY: prereq


create_dirs:
	mkdir -p $(BIN)
	mkdir -p $(TMP)
.PHONY: create_dirs


QUEX_VERSION = 0.67.5
QUEX_VERSION_MINOR = `echo $(QUEX_VERSION) | sed -E 's/\.[0-9]+$$//'`
QUEX_LINK = https://sourceforge.net/projects/quex/files/HISTORY/$(QUEX_VERSION_MINOR)/quex-$(QUEX_VERSION).tar.gz/download

install_quex:
	rm -rvf $(QUEX) ; \
	cd $(TMP) ; \
	wget -O quex.tar.gz $(QUEX_LINK) ; \
	tar zxvf quex.tar.gz ; \
	mv quex-$(QUEX_VERSION)/ ../$(QUEX) ; \
	rm quex.tar.gz
.PHONY: install_quex

