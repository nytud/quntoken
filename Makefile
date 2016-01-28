TARGET_DIR		= bin
TMP_DIR			= tmp
SOURCE_DIR		= src
QTOKEN_DIR		= $(SOURCE_DIR)/qtoken
MYTEST_DIR		= $(SOURCE_DIR)/test_files
GTEST_DIR		= $(SOURCE_DIR)/googletest/googletest
GTEST_HEADERS	= $(GTEST_DIR)/include/gtest/*.h \
				  $(GTEST_DIR)/include/gtest/internal/*.h

CPPFLAGS +=	-isystem $(GTEST_DIR)/include

CXXFLAGS +=	-Wall \
			-Wextra \
			-Wconversion \
			-Werror \
			-std=c++11 \
			# -g \

CXXFLAGS_QUEX =	$(CXXFLAGS) \
				-I$(QUEX_PATH) \
				-I$(TMP_DIR) \
				-DQUEX_OPTION_ASSERTS_DISABLED \
				-DQUEX_OPTION_SEND_AFTER_TERMINATION_ADMISSIBLE \
				-DENCODING_NAME='"UTF8"' \
				-DPRINT_TOKEN \
				-DQUEX_OPTION_MULTI

CXXFLAGS_GTEST =	$(CXXFLAGS) \
					-pthread \

QUEXFLAGS =	-b 4 \
		 	--bet wchar_t \
		 	--icu
# Megj1: icu konverter használata:
#   - telepíteni kell a libicu52-t és a libicu-dev-et
#   - quex-nek kell az --icu kapcsoló
#   - g++-nak linkelésnél kell a `icu-config --ldflags`, ami visszaadja a
#     linkernek szánt paramétereket (valami érthetetlen oknál fogva nem mindegy
#     az `icu-config --ldflags` helye a kapcsolók között!)
#   - példa: ../quex/Demo/Cpp/003/-ban
# Megj2: -b 2 is lehetne, de ekkor egyes unicode char. propert.-eket
# használó szabálynál pampog a quex, hogy 2 bájtba nem fér minden bele



#####  M A I N   T A R G E T S  ###############################################
all: qtoken test

.PHONY: all

qtoken: $(TARGET_DIR)/qtoken

.PHONY: qtoken

test: $(TARGET_DIR)/test

.PHONY: test

# TODO: install_quex
install: prepare install_gtest

.PHONY: install

# TODO: update_quex_
update: update_gtest

.PHONY: update

clean:
	rm -rfv $(TARGET_DIR)/*
	rm -rfv $(TMP_DIR)/*

.PHONY: clean


######  A U X I L I A R Y   T A R G E T S  ####################################
### binaries
$(TARGET_DIR)/qtoken: $(TMP_DIR)/prep.o $(TMP_DIR)/snt.o $(TMP_DIR)/sntcorr.o $(TMP_DIR)/main.o
	$(CXX) $^ `icu-config --ldflags` -o $@

$(TARGET_DIR)/test: $(TMP_DIR)/prep.o $(TMP_DIR)/snt.o $(TMP_DIR)/test.o $(TMP_DIR)/gtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_GTEST) -lpthread $^ -o $@ `icu-config --ldflags`


### object files
$(TMP_DIR)/test.o: $(TMP_DIR)/test.cpp $(TMP_DIR)/prep_prep_lexer.cpp $(TMP_DIR)/snt_snt_lexer.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_QUEX) -c $< -o $@

$(TMP_DIR)/main.o: $(QTOKEN_DIR)/main.cpp $(TMP_DIR)/prep_prep_lexer.cpp $(TMP_DIR)/snt_snt_lexer.cpp $(TMP_DIR)/sntcorr_sntcorr_lexer.cpp
	$(CXX) $(CXXFLAGS_QUEX) -c $< -o $@

$(TMP_DIR)/prep.o: $(TMP_DIR)/prep_prep_lexer.cpp
	$(CXX) $(CXXFLAGS_QUEX) -c $< -o $@

$(TMP_DIR)/snt.o: $(TMP_DIR)/snt_snt_lexer.cpp
	$(CXX) $(CXXFLAGS_QUEX) -c $< -o $@

$(TMP_DIR)/sntcorr.o: $(TMP_DIR)/sntcorr_sntcorr_lexer.cpp
	$(CXX) $(CXXFLAGS_QUEX) -c $< -o $@


### quex
$(TMP_DIR)/prep_prep_lexer.cpp: $(QTOKEN_DIR)/definitions.qx $(QTOKEN_DIR)/preproc.qx
	cd $(TMP_DIR) ; \
	quex 	-i ../$(QTOKEN_DIR)/definitions.qx ../$(QTOKEN_DIR)/preproc.qx \
			-o prep::prep_lexer \
			--token-id-prefix PREP_ \
			$(QUEXFLAGS)

$(TMP_DIR)/snt_snt_lexer.cpp: $(QTOKEN_DIR)/definitions.qx $(QTOKEN_DIR)/snt.qx
	cd $(TMP_DIR) ; \
	quex 	-i ../$(QTOKEN_DIR)/definitions.qx ../$(QTOKEN_DIR)/snt.qx \
			-o snt::snt_lexer \
			--token-id-prefix SNT_ \
			$(QUEXFLAGS)

$(TMP_DIR)/sntcorr_sntcorr_lexer.cpp: $(QTOKEN_DIR)/definitions.qx $(QTOKEN_DIR)/sntcorr.qx
	cd $(TMP_DIR) ; \
	quex 	-i ../$(QTOKEN_DIR)/definitions.qx ../$(QTOKEN_DIR)/sntcorr.qx \
			-o sntcorr::sntcorr_lexer \
			--token-id-prefix SNTCORR_ \
			$(QUEXFLAGS)


### test.cpp
$(TMP_DIR)/test.cpp: $(MYTEST_DIR)/text2test.py $(MYTEST_DIR)/test_*
	./$(MYTEST_DIR)/text2test.py


### gtest
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

$(TMP_DIR)/gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS_GTEST) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@

$(TMP_DIR)/gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS_GTEST) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@

$(TMP_DIR)/gtest.a : $(TMP_DIR)/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(TMP_DIR)/gtest_main.a : $(TMP_DIR)/gtest-all.o $(TMP_DIR)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


######  I N S T A L L   A N D   U P D A T E  ##################################
CMD_INSTALL_GTEST = cd $(SOURCE_DIR) ; git clone https://github.com/google/googletest.git
CMD_UPDATE_GTEST = cd $(GTEST_DIR) ; git pull

prepare:
	mkdir -p $(TARGET_DIR)
	mkdir -p $(TMP_DIR)

.PHONY: prepare

install_gtest:
	if ! [ -d $(GTEST_DIR) ] ; then $(CMD_INSTALL_GTEST) ; fi

.PHONY: install_gtest

update_gtest:
	$(CMD_UPDATE_GTEST)

.PHONY: update_gtest


