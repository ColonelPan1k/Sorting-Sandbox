# Sorting-Sandbox

This is a project made out of my own desire to get better at sorting algorithms.  I thought it would be fun to make a tool to compare different sorting algorithms
and provide a nice command line interface to play around with everything.  It's also a good excuse to play around a bit with a few things I've wanted to try out
a bit more, namely `getopt()` and some `fork()/exec()/wait()` type stuff.  This will be a more robust version of my previous Timer project.  That was more of a 
quick learning experiment with a fun bogosort on the side, whereas this might actually be a bit useful to someone.

# Usage

The planned usage will follow the form of `Sort [algorithm 1] [algorithm 2] [size of array]` which will generate an array with the given number of elements, then
perform both sorting algorithms on the same generated array.  It will then output information about each sorting algorithm and how well each performed on the array.
