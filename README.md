# Producer - Consumer multithread problem

This project was created using the STL of C++ and CMake, coded in windows using VSCode, the codebase was written in order to be multiplatform.

## Problem description
Is desired to write a program which could parse a serie of input strings composed of digits and whitspaces into sorted vectors, and after that, write the results into an ouptut file.

Those operations must be running in a max of __4 threads simultaneously__

### Game conditions
Take three parameters as follows:

* An input file in which there could be not more than 10k lines, and each of those could have maximum 100 characters limited to digits and whitespaces.
* An output file in which we gonna write the result of each sort operation.
* The algorithm to be used this could be _'bubble'_ or _'merge'_.

### Remarks
* When a whitespace is found parcing the string the thread must sleep for a second and don't put this character into the data vector.
* __The output file is shared by all the threads!.__
* The results are supposed to be written asap and one by one.

## Involved Algorithms
The algorithms involved in the solution of this challenge were both selected by it's easy of implementation having in count that the strings to be sorted are short.

### Bubble sort
Basic sorting algorithm with complexity of O(n^2) in the worst case.

### Merge sort
Sorting algorithm which implements the strategy know as divide and conquer, this algorithm is supposed to be stable with complexity of O(n * logn).

## How to
### Compile
As this project was created using CMake, you should have a build folder in which the CMakeFiles gonna be written, so when you're located in this folder you could run the command *CMake <path_to_source>*, and then *CMake --build .* this second command gonna do a call to the identified compiler, which gonna generate the executable file.

### Execute
The execution of this project depends on the existence of an input file with contains all the lines to be sorted, and should be called like:

* Windows: in windows could be executed from command line
![Execution command](https://github.com/JJimenez94/Smartmatic_MultiThread/blob/master/command.png)

* Linux: in Linux this could be executed with the command **"./ProducerConsumer "/path/to/the/input/file" "/path/to/the/output/file" "merge""**

**Remember:** the user executing the program should have access to both paths.

An example of input file is:\
![Input](https://github.com/JJimenez94/Smartmatic_MultiThread/blob/master/example_input.png) 

And the example of output file is:\
![Output](https://github.com/JJimenez94/Smartmatic_MultiThread/blob/master/example_output.png) 

As you can see the results are written in different orders this happens because the operations of sorting are executed in blocks of four lines (the number of max running threads) and some operations could take more execution time than others, so, the write operations aren't necessarily in the same order as were dispatched.
