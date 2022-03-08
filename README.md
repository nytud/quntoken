# quntoken

New Hungarian tokenizer based on quex and huntoken.
This tool is also [integrated](https://github.com/dlt-rilmta/hunlp-GATE)
into the [e-magyar](http://www.e-magyar.hu) language processing system
under the name [emToken](http://e-magyar.hu/hu/textmodules/emtoken).

## Requirements

* OS: linux x86-64
* python 3.6+

Developer requirements: 

* python 2.7 (for quex)
* g++ = 5

## Install

```sh
pip3 install quntoken
```

## Usage


### Command line

*quntoken* reads plain text in UTF-8 from STDIN and writes to STDOUT.

The default (and recommended) format of output is TSV. It has two columns.
The first contains the token, the second contains the white space sequence
after the token. Sentence boundaries are marked with empty lines.

Example: tokenizing *input.txt* file, writing the TSV output into *output.tsv* file.

```
quntoken <input.txt >output.tsv
```

Optional arguments:

```txt
  -h, --help            show this help message and exit
  -f {json,raw,spl,tsv,xml}, --form {json,raw,spl,tsv,xml}
                        Valid formats: json, tsv, xml and spl (sentence per
                        line, ignores mode). Default format: tsv.
  -m {sentence,token}, --mode {sentence,token}
                        Modes: sentence or token (does not apply for
                        form=spl). Default: token
  -c, --conll-text      Add CoNLL text metafield to contain the detokenized
                        sentence (only for mode == token and format == tsv).
                        Default: False
  -w, --word-break      Eliminate word break from end of lines.
  -v, --version         show program's version number and exit
```

### Python API

quntoken.**tokenize**(*inp=sys.stdin, form='tsv', mode='token',
word_break=False, w_conll_text_meta_field=False*)
 
>Entry point, returns an iterator object. Parameters:
>
>- *inp*: Input iterator, default: *sys.stdin*.
>- *form*: Format of output. Valid formats: `'tsv'` (default), `'json'`, `'xml'`
>and `'spl'` (sentence per line, ignores `mode`).
>- *mode*: `'sentence'` (only sentence segmenting) or `'token'` (full
>tokenization - default, does not apply for `form=spl`).
>- *word_break*: If `True`, eliminates word break from end of lines. Default:
>`False`.
>- *w_conll_text_meta_field*: If `True`, add CoNLL text metafield to contain the detokenized
>sentence (Only for mode == token and format == tsv). Default:
>`False`.

Example:

```py
from quntoken import tokenize

for tok in tokenize(open('input.txt')):
    print(tok, end='')
```
