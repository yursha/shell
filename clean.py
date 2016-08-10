#!/usr/bin/env python
import os
from subprocess import call

home = os.path.realpath('.')


dirs = []
dirs.append('./lib/tilde/doc')
dirs.append('./lib/tilde')
dirs.append('./lib/sh')
dirs.append('./lib/glob/doc')
dirs.append('./lib/glob')
dirs.append('./lib/malloc')
dirs.append('./builtins')
dirs.append('.')

for dir in dirs:
    os.chdir(dir)
    call(["make", "clean"])
    os.chdir(home)

