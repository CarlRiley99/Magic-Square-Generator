# Magic-Square-Generator
**NOTE: This was a project for COP 3503 "Programming Fundamentals 2"**

## Problem Description
Write C++ programs that create TEN(10) different N x N magic squares. A square matrix is the
arrangement of the numbers 1,2,..., N<sup> 2 </sup>, in which the sum of rows, columns, and
diagonals are the same. The users will specify the size of the square matrix: N.
The value N must bee an odd number between 3 and 15.

## Hints to find magic squares
1. (Data Structures) You should use arrays to generate and store the integers. You should
practice C++ modeling to create classes and methods to compile the program, then run the
executable code.

2. (Algorithms) Many good heuristics do exist to find a magic square quickly. You should be
able to find them via Google search. However, finding ALL magic squares requires carefuly examination
of all permutation of all these N x N numbers (e.g., 225! for a 15 x 15 matrix). When the
matrix size N is big enough, the computation for ALL magic squares will become intensive.

3. (Computation) You are only required to find TEN(10) magic squares for the full credits since
we just want you to get familiar with C++ programming via this assignment. However, you are
encouraged to explore the computational complexity of finding ALL magic squares, if time allows.

4. There are many ways to model/code in C++. Thus, there may not be a standard solution. You need
to explain well on your modeling and coding with comments in the .h and .cpp file(s).

5. Please do not take user's input *N*, then declare the size of arrays. It is not a good practice
since malicious users may input a very large number (e.g. 1,000,000).

6. Note that squares cannot be hard-coded, but must actually be computed at runtime.

## Example Run
For example, your program is expected to run as the following way (NOTE: only 5 magic squares
is listed on this example):
<pre>
INPUT>> Enter the size of a magic square: 3

OUTPUT>> Magic Square #1 is:
  2   7   6
  9   5   1
  4   3   8
OUTPUT>> Checking the sums of every row:      15  15  15
OUTPUT>> Checking the sums of every column:   15  15  15
OUTPUT>> Checking the sums of every diagonal: 15  15

OUTPUT>> Magic Square #2 is:
  8   3   4
  1   5   9
  6   7   2
OUTPUT>> Checking the sums of every row:      15  15  15
OUTPUT>> Checking the sums of every column:   15  15  15
OUTPUT>> checking the sums of every diagonal: 15  15

OUTPUT>> Magic Square #2 is:
  8   3   4
  1   5   9
  6   7   2
OUTPUT>> Checking the sums of every row:      15  15  15
OUTPUT>> Checking the sums of every column:   15  15  15
OUTPUT>> Checking the sums of every diagonal: 15  15

OUTPUT>> Magic Square #3 is:
  8   1   6
  3   5   7
  4   9   2
OUTPUT>> Checking the sums of every row:      15  15  15
OUTPUT>> Checking the sums of every column:   15  15  15
OUTPUT>> Checking the sums of every diagonal: 15  15

OUTPUT>> Magic Square #4 is:
  2   9   4
  7   5   3
  6   1   8
OUTPUT>> Checking the sums of every row:      15  15  15
OUTPUT>> Checking the sums of every column:   15  15  15
OUTPUT>> Checking the sums of every diagonal: 15  15

