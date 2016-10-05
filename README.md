# quntoken

New Hungarian tokenizer based on quex and huntoken.

## Requirements

* linux
* python 2.x as default python
* python 3.x
* g++ >= 4.8.2

## Install

```
git clone https://github.com/dlt-rilmta/quntoken.git
cd quntoken
make install
make all
```

## Usage

```
./quntoken [OPTIONS] [-f FORMAT] FILE
```
### Options

* -d: Remove division of words at the end of the lines.
* -f: Define output format. Valid formats: xml, json. Default format: xml.
* -V: Display version number and exit.
* -h: Display help and exit.

