# from quntoken.quntoken import tokenize
from quntoken import tokenize
import argparse
import sys

FORMATS = {'json', 'raw', 'tsv', 'xml'}
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
        help= 'Valid formats: json, tsv and xml. Default format: tsv.',
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
    res = vars(pars.parse_args())
    return res


def main():
    """Command line entry point.
    """
    args = get_args()
    form = args['form']
    mode = args['mode']
    word_break = args['word_break']
    cmd = ['preproc', 'snt', 'sntcorr', 'sntcorr']
    if mode == 'token':
        cmd.append('token')
    if word_break:
        cmd.insert(1, 'hyphen')
    if form != 'raw':
        cmd.append('conv{0}'.format(form))
    for line in tokenize(cmd, sys.stdin):
        print(line, end='', file=sys.stdout)


if __name__ == '__main__':
    main()

