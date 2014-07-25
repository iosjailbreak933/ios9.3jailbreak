# -*- mode: python -*-
import re
from os import listdir
from os.path import join, splitext

### File extensions
cpp = r".*\.[Cc]([Pp]?)\1"
hpp = r".*\.[Hh]([Pp]?)\1"

### Helper functions
def options(*lst):
    return ' ' + ' '.join(lst) + ' '

def getMatchingFiles(regex, d='.'):
    return [join(d, x) for x in listdir(d) if re.match(regex, x)]

def makeTargets(name, env=None, **kw):
    exc = join(dir_build, name)
    src = [splitext(name)[0] + '.cpp']

    if not env: env = DefaultEnvironment()
    for target,action in kw.items():
        env.AlwaysBuild(env.Alias(target, [], action))
    env.Program(exc, src + src_common)
    Alias(name, exc)

### Project structure
dir_inc   = 'inc'
dir_src   = 'src'
dir_test  = 'tests'
dir_build = 'build'

### Targets
Decider('make')

compiler   = 'g++'
src_common = getMatchingFiles(cpp, dir_src)

# default
flg_default = options('-Wall', '-pedantic', '-g')
lib_default = Split("""
""")
default = Environment(
    CC      = compiler,
    CCFLAGS = flg_default,
    LIBS    = lib_default,
    CPPPATH = dir_inc)

makeTargets('main', default)

# test
flg_test = options('-D_REENTRANT', '-fPIC')
lib_test = Split("""
pthread
dl
""")
tests = default.Clone()
tests.Append(CCFLAGS = flg_test)
tests.Append(LIBS    = lib_test)

testgen = 'tools/fructose_gen.py %s > %s' % (
    ' '.join(getMatchingFiles(hpp, dir_test)),
    '$TARGETS')
makeTargets('test', tests,
            testfile = tests.Command('test.cpp', [], testgen))

###
Default()
print "BUILD_TARGETS is", map(str, BUILD_TARGETS)
