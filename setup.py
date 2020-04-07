import setuptools
from quntoken.version import __version__

with open('README.md') as fh:
    long_description = fh.read()

setuptools.setup(
    name='quntoken',
    version=__version__,
    author='mittelholcz',
    description='Hungarian tokenizer based on quex and huntoken.',
    long_description=long_description,
    long_description_content_type='text/markdown',
    url='https://github.com/dlt-rilmta/quntoken',
    packages=['quntoken'],
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',
        'Operating System :: POSIX :: Linux',
    ],
    python_requires='>=3.6',
    include_package_data=True,
    entry_points={
        "console_scripts": [
            "quntoken=quntoken.__main__:main",
        ]
    },
)
