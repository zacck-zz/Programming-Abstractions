/*
 * File: rational.cpp
 * ------------------
 * Implementation for the Rational class
 */

#include <string>
#include <cstdlib>
#include "error.h"
#include "rational.h"
#include "strlib.h"

using namespace  std;
/* Prototypes */

int gcd(int x, int y);

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors  for the Rational Class. THe default constructor creates a Rational with zero
 * value, the one-argument form converts an integer to a Rational, the two argument form allows specifying a
 * fraction. The constructors ensure that the folloing invariants are maintained:
 *
 * 1. The fraction is always reduced to lowest terms.
 * 2. The denominator is always positive
 * 3. Zero is always represented as 0/1
 */

Rational::Rational(){
    num = 0;
    den = 1;
}

Rational::Rational(int n){
    num = n;
    den = 1;
}

Rational::Rational(int x, int y){
    if(y == 0) error("Rational: Division by zero");
    if(x == 0) {
        num = 0;
        den = 1;
    } else {
        //find the gcd
        int g = gcd(abs(x), abs(y));
        //find the numerators simplest form
        num = x / g;
        //find the denominators simplest form
        den = abs(y) / g;
        //if the numerator is less than zero convert it to a positive value
        if (y < 0) num = -num;
    }
}

/*
 * Implementation of toString and the << operator
 */

string Rational::toString(){
    if(den == 1){
        return integerToString(num);
    } else {
        return integerToString(num) + "/" + integerToString(den);
    }
}


ostream & operator<<(ostream & os, Rational rat) {
    return os << rat.toString();
}


/*
 * Implementation notes: arithmetic operators
 * --------------------------------------------
 * The implementation of the operators follows directly from the definitions
 */

Rational operator+(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator-(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator*(Rational r1, Rational r2) {
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator/(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den, r1.den * r2.num);
}


/*
 * Implementation notes: gcd
 * -------------------------
 * This implementation uses Euclid's algorithm to calculate the greatest common divisot.
 */
int gcd(int x, int y) {
    int r = x % y;
    while(r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
