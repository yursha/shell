#!/usr/bin/env python
import os
from subprocess import call

home = os.path.realpath('.')


dirs = []
dirs.append('./examples/loadables/perl')
dirs.append('./examples/loadables')
dirs.append('./tests/cracauer-testsuite')
dirs.append('./lib/termcap')
dirs.append('./lib/tilde/doc')
dirs.append('./lib/tilde')
dirs.append('./lib/readline/examples')
dirs.append('./lib/readline/doc')
dirs.append('./lib/readline')
dirs.append('./lib/sh')
dirs.append('./lib/glob/doc')
dirs.append('./lib/glob')
dirs.append('./lib/malloc')
dirs.append('./support')
dirs.append('./builtins')
dirs.append('.')

for dir in dirs:
    os.chdir(dir)
    call(["make", "clean"])
    os.chdir(home)

