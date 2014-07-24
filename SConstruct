# -*- mode: python -*-
import os

# Project structure
inc_dir  = 'inc'
src_dir  = 'src'
test_dir = 'test'

# External libraries
libs = Split("""
boost_regex
boost_program_options
""")

# Compilation settings
comp = 'g++'
flgs = '-Wall -pedantic -g'

# Environments
Decider('make')
default = Environment()
default.Append(CC      = comp)
default.Append(CCFLAGS = flgs)
default.Append(LIBS    = libs)
default.Append(CPPPATH = inc_dir)

# Sources
src_ext = '*.cpp'
src_common = [f for f in
              Glob(os.path.join(src_dir, src_ext))]

# Builds
main = default.Program('main', ['main.cpp'] + src_common)

Default(None)
print "BUILD_TARGETS is", map(str, BUILD_TARGETS)
