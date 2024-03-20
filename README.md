Nicolas Corfmat<br>
CruzID: ncorfmat<br>
Assignment: pa1

```
DESCRIPTION
``` 
This program lexicographically sorts lines of text from an input text file.

```
FILES
```
+ `List.h` Header file containing the interface for the List ADT.
+ `List.c` C file containing the List ADT.
+ `ListTest.c` C file containing code for testing the List ADT functions.
+ `Lex.c` Contains the main() function that implements the sorting algorithm.
+ `Makefile` Supports the compilation of all the .c programs in the pa1 directory.
+ `README.md` Contains information regarding the files in the pa1 directory and how to run them.

```
BUILD
``` 
To build, run `make` on the terminal command line within the pa1 assignment directory. This creates the **'Lex'**, **'List'**, and **'ListTest'**  executable files which can then be run.
```
CLEAN
```
Running `make clean` will remove all the executable (.o) files from the pa1 assignment directory as well as other compiler-generated files.
```
RUNNING
```
To sort the input text file, run `./lex` followed by a space separated **input** and **output** text file.
