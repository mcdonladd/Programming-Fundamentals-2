Binary Search Tree (BST)

This project implements a Binary Search Tree (BST) data structure in C++.

Installation/Building

To compile and run ensure that you have a C++ compiler installed (e.g. Clang or GCC) that supports the C++11 standard.
To build using the makefile, open a terminal or command prompt and navigate to the project directory:

1. First create a static library running the command 'make BST', which will generate the 'BST.lib' file
2. Compile the test program using the command 'make BTStest', which will generate the executable 'BSTtest'
3. Compile the replace utility program using 'make PartB', which will generate the executable 'replace'

To clean:
4. Run the command 'make clean'
   This will remove the object files:
   'BST.o', 'BSTtest.o' and 'replace.o'
   The library file 'BST.lib'
   And the executables 'BSTtest' and 'replace'

Usage

'BSTtest' is used to test the funcionality of the BST
To run it, execute the following command ./BSTtest

'replace' is a command line application that replaces #define elements in a specified .c file with its corrosponding value, then outputs to a .o file
To run it, execute the following command ./replace [filename.c]

Written by Sam McDonald 40591517
