TARGET_DIR		= bin
TMP_DIR			= tmp
SOURCE_DIR		= src
QTOKEN_DIR		= $(SOURCE_DIR)/qtoken
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
				# -DQUEX_OPTION_MULTI

CXXFLAGS_GTEST =	$(CXXFLAGS) \
					-pthread \


#####  M A I N   T A R G E T S  ###############################################
all: $(TARGET_DIR)/qtoken $(TARGET_DIR)/test

.PHONY: all


$(TARGET_DIR)/qtoken: $(TMP_DIR)/snt.o $(TMP_DIR)/main.o
	$(CXX) $^ -o $@ `icu-config --ldflags`


$(TARGET_DIR)/test: $(TMP_DIR)/test.o $(TMP_DIR)/snt.o $(TMP_DIR)/gtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_GTEST) -lpthread $^ -o $@ `icu-config --ldflags`


CMD_INSTALL_GTEST = cd $(SOURCE_DIR) ; git clone https://github.com/google/googletest.git
preparation:
	mkdir -p $(TARGET_DIR)
	mkdir -p $(TMP_DIR)
	if ! [ -d $(GTEST_DIR) ] ; then $(CMD_INSTALL_GTEST) ; fi

.PHONY: preparation


CMD_UPDATE_GTEST = cd $(GTEST_DIR) ; git pull
update:
	$(CMD_UPDATE_GTEST)

.PHONY: update


clean:
	rm -rfv $(TARGET_DIR)/*
	rm -rfv $(TMP_DIR)/*

.PHONY: clean


######  A U X I L I A R Y   T A R G E T S  ####################################
### object files
$(TMP_DIR)/test.o: $(QTOKEN_DIR)/test.cpp $(TMP_DIR)/snt_snt_lexer.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_QUEX) -c $< -o $@

$(TMP_DIR)/snt.o: $(TMP_DIR)/snt_snt_lexer.cpp
	$(CXX) $(CXXFLAGS_QUEX) -c $< -o $@


$(TMP_DIR)/main.o: $(QTOKEN_DIR)/main.cpp $(TMP_DIR)/snt_snt_lexer.cpp
	$(CXX) $(CXXFLAGS_QUEX) -c $< -o $@


### quex
$(TMP_DIR)/snt_snt_lexer.cpp: $(QTOKEN_DIR)/character_classes.qx $(QTOKEN_DIR)/snt.qx
	cd $(TMP_DIR) ; quex -i ../$(QTOKEN_DIR)/character_classes.qx ../$(QTOKEN_DIR)/snt.qx \
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

