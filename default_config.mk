# Itt lehet megadni a forditando modulokat, a hozzajuk tartozo teszteketes
# egyeb tartozekaikat.

# quex modulok es modul templatumok forrasai
QMODULES_DIR = src/quex_modules

DEFINITIONS		= $(QMODULES_DIR)/definitions.qx
PREP_MODULE    	= $(QMODULES_DIR)/preproc.qx
SNT_MODULE     	= $(QMODULES_DIR)/snt.qx
SNTCORR_MODULE 	= $(QMODULES_DIR)/sntcorr.qx
TOKEN_MODULE	= $(QMODULES_DIR)/token.qx

# roviditeseket tartalmazo fajl az SNTCORR_MODULE-hoz
# Megj: fejleszteshez erdemes az orig-ot haznalni, mert joval gyorsabban fordul
ABBREVIATIONS	= data/abbreviations_orig-hu.txt
# ABBREVIATIONS	= data/abbreviations_nytud-hu.txt


# tesztfajlok:
MYTEST_DIR = test
TEST_FILES = $(MYTEST_DIR)/test_default_prep_invalid.txt \
             $(MYTEST_DIR)/test_default_snt_boundary.txt \
             $(MYTEST_DIR)/test_default_snt_newline.txt  \
             $(MYTEST_DIR)/test_default_sntcorr_all.txt \
             $(MYTEST_DIR)/test_default_sntcorr_luth.txt \
             $(MYTEST_DIR)/test_default_token_dots.txt \
             $(MYTEST_DIR)/test_default_token_parenthesis.txt \
             $(MYTEST_DIR)/test_default_token_hyphen.txt \
             $(MYTEST_DIR)/test_default_token_it.txt \

