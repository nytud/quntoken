try:
    from quntoken.version import __version__
except ModuleNotFoundError:
    from version import __version__
from quntoken import tokenize  # , __version__
# import quntoken
import argparse
import sys

FORMATS = {'json', 'raw', 'tsv', 'xml', 'spl'}
MODES = {'sentence', 'token'}


def get_args():
    """Handling of commandline arguments.
    """
    pars = argparse.ArgumentParser(description=__doc__)
    pars.add_argument(
        '-f',
        '--form',
        help='Valid formats: json, tsv, xml and spl (sentence per line, ignores mode). Default format: tsv.',
        default='tsv',
        choices=sorted(FORMATS)
    )
    pars.add_argument(
        '-m',
        '--mode',
        help='Modes: sentence or token (does not apply for form=spl). Default: token',
        default='token',
        choices=sorted(MODES)
    )
    conll_text_arg = \
        pars.add_argument(
            '-c',
            '--conll-text',
            help='Add CoNLL text metafield to contain the detokenized sentence '
                 '(only for mode == token and format == tsv). Default: False',
            dest='w_conll_text_meta_field',
            default=False,
            action='store_true'
        )
    pars.add_argument(
        '-w',
        '--word-break',
        help='Eliminate word break from end of lines.',
        action='store_true'
    )
    pars.add_argument(
        '-v',
        '--version',
        action='version',
        version=__version__
    )
    res = vars(pars.parse_args())
    if res['w_conll_text_meta_field'] and (res['mode'] != 'token' or res['form'] != 'tsv'):
        raise argparse.ArgumentError(conll_text_arg, 'can only be set if mode == token and form == tsv !')

    return res


def main():
    """Command line entry point.
    """
    for line in tokenize(inp=sys.stdin, **get_args()):
        print(line, end='', file=sys.stdout)


if __name__ == '__main__':
    main()
