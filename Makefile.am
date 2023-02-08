# Makefile.am

lib_LIBRARIES       = libmycode.a
libmycode_a_SOURCES = src/rewards.c

# Tell automake to build the testrunner on "make check"
check_PROGRAMS  = testrunner
# Tell automake to run the testrunner on "make check"
TESTS=$(check_PROGRAMS)
AUTOMAKE_OPTIONS = foreign subdir-objects
# docsdir = /docs
# dist_docs_DATA = README
AM_CPPFLAGS = $(all_includes) -I src/
# List all your test source code here
testrunner_SOURCES = UnitTests/test_rewards.c
# Compile only test code with -g and the NovaProva flags
testrunner_CFLAGS= -g $(NOVAPROVA_CFLAGS)
# Link testrunner with the Code Under Test and the NovaProva library
testrunner_LDADD= libmycode.a $(NOVAPROVA_LIBS)