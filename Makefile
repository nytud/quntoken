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
QXCPPS			:= $(QXLEXERS:%=$(TMP)/%$(QXSUFFIX).cpp)
QXOBJS			:= $(QXLEXERS:%=$(TMP)/%$(QXSUFFIX).o)


# COMPILERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# quex command
QXCMD		= export QUEX_PATH=$(QUEX) ; $(QUEX)/quex-exe.py

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
	-I./ \
	-I$(TMP)/ \
	-I$(QUEX) \
	-I$(SRC_CPP)
	# -g
	# -DENCODING_NAME='"UTF8"' \
	# -DQUEX_SETTING_BUFFER_SIZE=65536 \
	# -DQUEX_OPTION_INFORMATIVE_BUFFER_OVERFLOW_MESSAGE \
	# -DQUEX_OPTION_POSIX \
	# -liconv \


# g++ kapcsoloi gtest-es fajlokhoz
CXXFLAGS_GTEST =	$(CXXFLAGS) \
					-pthread \



# PARHUZAMOSITAS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
NUMCPUS = `grep -c '^processor' /proc/cpuinfo`
MAKE += -j $(NUMCPUS)

#####  M A I N   T A R G E T S  ###############################################
all: common $(NAME) test

.PHONY: all


$(NAME): $(BIN)/$(NAME)

.PHONY: $(NAME)


test: $(BIN)/test
	./$(BIN)/test 2>/dev/null

.PHONY: test


prereq: create_dirs install_gtest install_quex

.PHONY: prereq


update: update_gtest update_quex

.PHONY: update


clean:
	rm -rfv $(BIN)/*
	rm -rfv $(LIB)/*
	rm -rfv $(TMP)/*

.PHONY: clean


######  A U X I L I A R Y   T A R G E T S  ####################################
### common files
common:
	$(MAKE) $(QXCPPS)
	$(MAKE) object_files


### binaries
$(BIN)/$(NAME): $(TMP)/$(NAME).o $(LIB)/libquntoken.a
	$(CXX) $< -L$(LIB) -static-libstdc++ -static -lquntoken -o $@

$(BIN)/test: $(TMP)/test.o $(LIB)/libquntoken.a $(TMP)/gtest.a
	$(CXX) $(CXXFLAGS_GTEST) -lpthread -static-libstdc++ $^ -o $@


### libraries
$(LIB)/libquntoken.a: $(QXOBJS) $(TMP)/qx_module.o $(TMP)/qx_module_queue.o $(TMP)/quntoken_api.o
	$(AR) rscv $@ $^


### object files
object_files: $(QXOBJS) $(TMP)/qx_module.o $(TMP)/qx_module_queue.o $(TMP)/quntoken_api.o $(TMP)/test.o $(TMP)/$(NAME).o

.PHONY: object_files

$(TMP)/$(NAME).o: $(SRC_CPP)/$(NAME).cpp $(SRC_CPP)/*.h $(SRC_CPP)/quntoken_api.h
	$(CXX) -o $@ $(CXXFLAGS) -c $<

$(TMP)/test.o: $(TMP)/test.cpp $(SRC_CPP)/*.h $(QXCPPS)
	$(CXX) -o $@ $(CPPFLAGS) $(CXXFLAGS) -c $<

$(TMP)/quntoken_api.o: $(SRC_CPP)/quntoken_api.cpp $(SRC_CPP)/quntoken_api.h $(SRC_CPP)/qx_module_queue.h
	$(CXX) -o $@ $(CXXFLAGS) -c $<

$(TMP)/qx_module_queue.o: $(SRC_CPP)/qx_module_queue.cpp $(SRC_CPP)/qx_module_queue.h $(SRC_CPP)/quntoken_api.h $(SRC_CPP)/qx_module.h $(QXCPPS)
	$(CXX) -o $@ $(CXXFLAGS) -c $<

$(TMP)/qx_module.o: $(SRC_CPP)/qx_module.cpp $(SRC_CPP)/qx_module.h $(SRC_CPP)/quntoken_api.h $(QXCPPS)
	$(CXX) -o $@ $(CXXFLAGS) -c $<


$(QXOBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PRECIOUS: $(QXOBJS)


$(QXCPPS): $(TMP)/%$(QXSUFFIX).cpp: $(QXDEPS) $(SRC_QX)/%.qx
	$(QXCMD) $(QXFLAGS)

.PRECIOUS: $(QXCPPS)


print:
	@echo 'qxobjs:' $(QXOBJS)

.PHONY: nana


# generate lexer for abbreviations
$(TMP)/$(ABBREVIATIONS:%.txt=%.qx): $(SRC_SCRIPT)/generate_abbrev.qx.py $(SRC_ABBR)/$(ABBREVIATIONS)
	./$< -d $(word 2, $^) -o $@



### test.cpp
$(TMP)/test.cpp: $(SRC_SCRIPT)/test.tmpl2cpp.py $(SRC_CPP)/test.cpp.tmpl $(TEST_FILES)
	./$< -t $(word 2, $^) -d $(wordlist 3, $(words $^), $^) -o $@

### gtest
GTEST_SRCS_ = $(GTEST)/src/*.cc $(GTEST)/src/*.h $(GTEST_HEADERS)

$(TMP)/gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST) $(CXXFLAGS_GTEST) -c \
            $(GTEST)/src/gtest-all.cc -o $@

$(TMP)/gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST) $(CXXFLAGS_GTEST) -c \
            $(GTEST)/src/gtest_main.cc -o $@

$(TMP)/gtest.a : $(TMP)/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(TMP)/gtest_main.a : $(TMP)/gtest-all.o $(TMP)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


######  I N S T A L L   A N D   U P D A T E  ##################################
CMD_INSTALL_GTEST = git clone https://github.com/google/googletest.git
CMD_UPDATE_GTEST = cd $(GTEST) ; git pull
# NOTE: a jelenlegi Quex verzio nem rossz, a 0.65.4-os az utolso hasznalhato
# verzio. Ezert egyelore nem lehet hasznalni sem az aktualis verzio sima svn-es
# letolteset, sem a svn-es frissitest. Ehelyett a history-bol kell letolteni es
# nem szabad frissiteni.
# CMD_INSTALL_QUEX =
# 	cd $(TMP) ; \
# 	svn checkout https://svn.code.sf.net/p/quex/code/trunk ; \
# 	mv trunk/ ../$(QUEX)
QUEX_STABLE_VERSION = quex-0.65.4
QUEX_LINK = downloads.sourceforge.net/project/quex/HISTORY/0.65/$(QUEX_STABLE_VERSION).tar.gz
CMD_INSTALL_QUEX = \
	rm -rvf $(QUEX) ; \
	cd $(TMP) ; \
	wget $(QUEX_LINK) ; \
	tar zxvf $(QUEX_STABLE_VERSION).tar.gz ; \
	mv $(QUEX_STABLE_VERSION)/ ../$(QUEX) ; \
	rm $(QUEX_STABLE_VERSION).tar.gz
CMD_UPDATE_QUEX = cd $(QUEX) ; svn up

create_dirs:
	mkdir -p $(BIN)
	mkdir -p $(TMP)
	mkdir -p $(LIB)

.PHONY: create_dirs

install_gtest:
	if ! [ -d $(GTEST) ] ; then $(CMD_INSTALL_GTEST) ; fi

.PHONY: install_gtest

install_quex:
	if ! [ -d $(QUEX) ] ; then $(CMD_INSTALL_QUEX) ; fi

.PHONY: install_quex


update_gtest:
	if [ -d $(GTEST) ] ; then $(CMD_UPDATE_GTEST) ; fi

.PHONY: update_gtest


update_quex:
	@echo "Updating Quex is not secure!"
	# if [ -d $(QUEX) ] ; then $(CMD_UPDATE_QUEX) ; fi

.PHONY: update_quex




