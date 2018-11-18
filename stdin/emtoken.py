#! /usr/bin/env python3


import subprocess
import sys


def main():
    p1 = subprocess.Popen('sed "s/b/a/"', shell=True, stdin=sys.stdin, stdout=subprocess.PIPE)
    p2 = subprocess.Popen('grep a', shell=True, stdin=p1.stdout, stdout=subprocess.PIPE)
    p1.stdout.close()
    output = p2.communicate()[0]
    output = output.decode(encoding='utf-8')
    print(output)


if __name__ == '__main__':
    main()

