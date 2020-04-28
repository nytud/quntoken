# ABBREV := data/abbreviations_nytud-hu.txt
ABBREV := data/abbreviations_orig-hu.txt
MODULES := preproc hyphen snt sntcorr token convxml convjson convtsv convspl
# MODULES := token


# build ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
all:
	@make -s build OPT='-ggdb'
	@make -s test
.PHONY: all


release:
	@make -s build OPT='-O1'
	@make -s test
	@make -s targz
.PHONY: release


test:
	@pytest --verbose test/test_quntoken.py
.PHONY: test


targz:
	@tar -czf "quntoken_`uname -s`_`uname -m`_v`grep -Po '\d+\.\d+\.\d+' quntoken/version.py`.tar.gz" quntoken/qt_* quntoken/quntoken.py quntoken/__init__.py
.PHONY: targz


COMPILER := g++-5 $(OPT) -Wall -Werror -Wno-error=maybe-uninitialized -pedantic -static -std=c++11 -I./ -Iquex/ -DQUEX_OPTION_ASSERTS_DISABLED -DQUEX_OPTION_POSIX -DWITH_UTF8 -DQUEX_SETTING_BUFFER_SIZE=2097152 -DQUEX_OPTION_ASSERTS_DISABLED
build: quex
	@echo 'Compile binaries.'
	@cp src/cpp/main.cpp tmp/
	@cd tmp/ ; for module in $(MODULES) ; do \
		 { $(COMPILER) $${module}Lexer.cpp main.cpp -DLEXER_CLASS="$${module}Lexer" -DMYLEXER="\"$${module}Lexer\"" -o ../quntoken/qt_$${module} ; echo "- $${module}" ; } & \
	done ; wait ;
	@echo -e 'Done.\n'
.PHONY: build


QXCMD := export QUEX_PATH=quex ; quex/quex-exe.py --bet wchar_t -i ../src/quex_modules/definitions.qx abbrev.qx
quex: abbrev
	@echo 'Run Quex.'
	@cd tmp/ ; for module in $(MODULES) ; do \
		{ $(QXCMD) ../src/quex_modules/$${module}.qx -o $${module}Lexer ; echo "- $${module}" ; } & \
	done ; wait ;
	@echo -e 'Done.\n'
.PHONY: quex


abbrev:
	@echo 'Generate abbrev.qx' ;
	@./src/scripts/generate_abbrev.qx.py -d $(ABBREV) -o tmp/abbrev.qx
	@echo -e 'Done.\n'
.PHONY: abbrev


# aux ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
prereq: clean create_dirs install_quex venv
.PHONY: prereq


venv:
	python3 -m venv venv
	./venv/bin/pip3 install -r requirements-dev.txt
.PHONY: venv


clean:
	@rm -f quntoken/qt_*
	@rm -rf tmp/
	@rm -rf venv/
.PHONY: clean


create_dirs:
	@mkdir -p tmp
.PHONY: create_dirs


QUEX_VERSION = 0.67.5
QUEX_VERSION_MINOR = `echo $(QUEX_VERSION) | sed -E 's/\.[0-9]+$$//'`
QUEX_LINK = https://sourceforge.net/projects/quex/files/HISTORY/$(QUEX_VERSION_MINOR)/quex-$(QUEX_VERSION).tar.gz/download
install_quex:
	@cd tmp ; \
	rm -rf quex ; \
	wget -q -O quex.tar.gz $(QUEX_LINK) ; \
	tar zxf quex.tar.gz ; \
	mv quex-$(QUEX_VERSION)/ quex ; \
	rm quex.tar.gz
.PHONY: install_quex

