# Itt lehet megadni a forditando modulokat, a hozzajuk tartozo teszteket es
# egyeb tartozekaikat.


# DIRECTORIES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SRC_QX			= src/quex_modules


# LEXERS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
QXLEXERS		= preproc hyphen snt sntcorr token convxml convjson


# AUXILIARY FILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Megj: fejleszteshez erdemes az abbreviations_orig-ot hasznalni,
# 		mert joval gyorsabban fordul, mint az abbreviations_nytud-hu
# ABBREVIATIONS	= data/abbreviations_nytud-hu.txt
ABBREVIATIONS	= data/abbreviations_orig-hu.txt
DEFINITIONS		= definitions.qx


# TESTFILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MYTEST_DIR = test
TEST_FILES = $(MYTEST_DIR)/test_default_prep_invalid.txt \
             $(MYTEST_DIR)/test_default_hyphen_all.txt \
             $(MYTEST_DIR)/test_default_snt_boundary.txt \
             $(MYTEST_DIR)/test_default_snt_newline.txt  \
             $(MYTEST_DIR)/test_default_sntcorr_all.txt \
             $(MYTEST_DIR)/test_default_sntcorr_segfault.txt \
             $(MYTEST_DIR)/test_default_token_hyphen.txt \
             $(MYTEST_DIR)/test_default_token_dots.txt \
             $(MYTEST_DIR)/test_default_token_it.txt \
             $(MYTEST_DIR)/test_default_token_parenthesis.txt \
             $(MYTEST_DIR)/test_default_token_misc.txt \
             $(MYTEST_DIR)/test_default_token_numbers.txt \
             $(MYTEST_DIR)/test_default_token_quote.txt \
             $(MYTEST_DIR)/test_default_token_smiley.txt \
             $(MYTEST_DIR)/test_default_token_enumofnames.txt \

