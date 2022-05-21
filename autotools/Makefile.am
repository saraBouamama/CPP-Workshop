bin_PROGRAMS = hello

hello_SOURCES = main.cc

WARN_CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++20

HELLO_CXXFLAGS =$(WARN_CXXFLAGS)

SUBDIRS = libhello/

noinst_LIBRARIES = libhello/libhello.a

libhello_libhello_a_SOURCES = libhello/hello.hh libhello/hello.cc

hello_LDADD = libhello/libhello.a

