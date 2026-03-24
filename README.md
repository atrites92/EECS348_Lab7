EECS 348: Software Engineering - Spring 2026

Lab #7:  IDE, compiled programs (C++ programming), Git

Objective: Get familiar with IDE and C++ programming and practice Git again. During the C++ programming, you will practice the basic object-oriented programming, including operator overloading.

Due Date: Sunday, Mar 29, 2026, at 11:59 p.m.

What to turn in: A URL to your GitHub repository. Make sure the repository is public. Otherwise, the TAs won't be able to grade it.

Grading

This lab has 40 points.

Programming problem

This lab builds on Lab 5, where you will continue implementing a C++ program to perform various operations on matrices. However, in this lab, you'll leverage additional C++ features, such as classes and function overloading, and operator overloading.

Review the provided source code and implement the required functions to support all matrix operations in the program.

1. Read values from a file into a matrix:
Implement a function to load matrix data from a specified file and store it in a matrix.

Implement a function to display a matrix in a user-friendly format. 

3. Add two matrices with operator overloading and display the result:
Implement operator overloading for + to perform matrix addition, storing the result in a third matrix. Display the resulting matrix.

4. Multiply two matrices using operator overloading and display the result:
Implement operator overloading for * to enable matrix multiplication, storing the result in a third matrix. Display the resulting matrix.

5. Get the sum of matrix diagonal elements:
Implement a function to calculate and display the sum of the main and secondary diagonal elements of the matrix.

6. Swap matrix rows and display the result:
Implement a function that accepts a matrix and two-row indices. If both indices are valid, swap the rows and display the resulting matrix.

Sample Input

4 // The size of the square matrix (N) and the input file should not include this comment

01 02 03 04<br>
05 06 07 08<br>
09 10 11 12<br>
13 14 15 16<br>
13 14 15 16<br>
09 10 11 12<br>
05 06 07 08<br>
01 02 03 04<br>
