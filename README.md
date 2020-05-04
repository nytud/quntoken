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
  -f FORM, --form FORM  Valid formats: json, tsv, xml and spl (sentence per
                        line). Default format: tsv.
  -m MODE, --mode MODE  Modes: sentence or token. Default: token
  -w, --word-break      Eliminate word break from end of lines.
  -v, --version         show program's version number and exit
```

### Python API

quntoken.**tokenize**(*inp=sys.stdin, form='tsv', mode='token',
word_break=False*)
 
>Entry point, returns an iterator object. Parameters:
>
>- *inp*: Input iterator, default: *sys.stdin*.
>- *form*: Format of output. Valid formats: `'tsv'` (default), `'json'`, `'xml'`
>and `'spl'` (sentence per line).
>- *mode*: `'sentence'` (only sentence segmenting) or `'token'` (full
>tokenization - default).
>- *word_break*: If `'True'`, eliminates word break from end of lines. Default:
>`'False'`.

Example:

```py
from quntoken import tokenize

for tok in tokenize(open('input.txt')):
    print(tok, end='')
```
