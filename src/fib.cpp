/*
 * File: fib.cpp
 * ----------------
 * Lists the terms of the fibonacci sequence from MIN_INDEX to MAX_INDEX
 */

#include <iostream>
#include <iomanip>
using namespace std;


/* Constants */

const int MIN_INDEX = 0;
const int MAX_INDEX = 20;


/*
 * Function: fib
 * Usage: int f = fib(n);
 * ----------------------
 * Returns the nth term in a Fibonacci sequence using the following recursicce formulation
 *
 *      fib(0) = 0
 *      fib(1) = 1
 *      fib(n) = fib(n - 1) + fib(n - 2)
 */

int fib(int n) {
    if(n < 2) {
        return n;
    } else {
        return fib(n -1) + fib(n -2);
    }
}



