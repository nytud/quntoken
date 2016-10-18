# Itt lehet megadni a forditando modulokat, a hozzajuk tartozo teszteketes
# egyeb tartozekaikat.


# DIRECTORIES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SRC_QX			= src/quex_modules
SRC_ABBR		= data


# FILES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ABBREVIATIONS	= abbreviations_orig-hu.txt
ABBRLEXER		= $(ABBREVIATIONS:%.txt=%.qx)
DEFINITIONS		= definitions.qx
QXDEPS			= $(SRC_QX)/$(DEFINITIONS) $(TMP)/$(ABBRLEXER)
QXLEXERS		= preproc hyphen snt sntcorr token convxml convjson


# modules - TODO: make this deprecated ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
PREP_MODULE    	= $(SRC_QX)/preproc.qx
HYPHEN_MODULE   = $(SRC_QX)/hyphen.qx
SNT_MODULE     	= $(SRC_QX)/snt.qx
SNTCORR_MODULE 	= $(SRC_QX)/sntcorr.qx
TOKEN_MODULE	= $(SRC_QX)/token.qx

# roviditeseket tartalmazo fajl az SNTCORR_MODULE-hoz
# Megj: fejleszteshez erdemes az orig-ot haznalni, mert joval gyorsabban fordul
# ABBREVIATIONS	= data/abbreviations_nytud-hu.txt


# tesztfajlok:
MYTEST_DIR = test
TEST_FILES = $(MYTEST_DIR)/test_default_prep_invalid.txt \
             $(MYTEST_DIR)/test_default_hyphen_all.txt \
             $(MYTEST_DIR)/test_default_snt_boundary.txt \
             $(MYTEST_DIR)/test_default_snt_newline.txt  \
             $(MYTEST_DIR)/test_default_sntcorr_all.txt \
             $(MYTEST_DIR)/test_default_sntcorr_luth.txt \
             $(MYTEST_DIR)/test_default_token_hyphen.txt \
             $(MYTEST_DIR)/test_default_token_dots.txt \
             $(MYTEST_DIR)/test_default_token_it.txt \
             $(MYTEST_DIR)/test_default_token_parenthesis.txt \
             $(MYTEST_DIR)/test_default_token_misc.txt \
             $(MYTEST_DIR)/test_default_token_numbers.txt \
             $(MYTEST_DIR)/test_default_token_quote.txt \
             $(MYTEST_DIR)/test_default_token_smiley.txt \

