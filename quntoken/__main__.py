try:
    from quntoken.version import __version__
except ModuleNotFoundError:
    from version import __version__
from quntoken import tokenize #, __version__
# import quntoken
import argparse
import sys

FORMATS = {'json', 'raw', 'tsv', 'xml', 'spl'}
MODES = {'sentence', 'token'}


def check_format(form):
    """Check format argument.
    """
    if form not in FORMATS:
        raise argparse.ArgumentError
    return form


def check_mode(mode):
    """Check mode argument.
    """
    if mode not in MODES:
        raise argparse.ArgumentError
    return mode


def get_args():
    """Handling of commandline arguments.
    """
    pars = argparse.ArgumentParser(description=__doc__)
    pars.add_argument(
        '-f',
        '--form',
        help= 'Valid formats: json, tsv, xml and spl (sentence per line). Default format: tsv.',
        default='tsv',
        type=check_format
    )
    pars.add_argument(
        '-m',
        '--mode',
        help= 'Modes: sentence and token. Default: token',
        default='token',
        type=check_mode
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
    return res


def main():
    """Command line entry point.
    """
    for line in tokenize(inp=sys.stdin, **get_args()):
        print(line, end='', file=sys.stdout)


if __name__ == '__main__':
    main()

