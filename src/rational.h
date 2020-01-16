/*
 * File: rational.h
 * ----------------
 * Defined an interface for the rational class for representing rational numbers
 */

#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <iostream>


/*
 * Class: Rational
 * ---------------
 * The Rational class is used to represent rational numbers, which are defined
 * to be the quotient of two integers
 */
class Rational {
public:
/*
 * Constructor: Rational
 * Usage: Rational zero;
 *        Ratinal num(n)
 *        Rational r(x, y);
 * --------------------------
 * Creates a Rational object. The default constructor creates the rational number 0.
 * The single-argument form creates a rational equal to the specified integer, the two
 * argument form creates a rational number corresponding to the fraction x/y.
 */

    Rational();
    Rational(int n);
    Rational(int x, int y);


/*
 * Method: toString
 * Usage: string s = r.toString()
 * ------------------------------
 * Returns the string represantation of this rational number
 */
    std::string toString();

    friend Rational operator+(Rational r1, Rational r2);
    friend Rational operator-(Rational r1, Rational r2);
    friend Rational operator*(Rational r1, Rational r2);
    friend Rational operator/(Rational r1, Rational r2);

    private:
    /* Instance variables */

    int num; // numerator
    int den; // denominator


};


/*
 * Operator: <<
 * ------------
 * Overloads the << operator so that its is able to display Rational values.
 */
    std::ostream & operator<<(std::ostream & os, Rational rat);


/*
 * Operator: +
 * Usage: r1 + r2
 * --------------
 * Overloads the + operator so that it performs addition on two rational numbers.
 */
    Rational operator+(Rational r1, Rational r2);

/*
 * Operator: -
 * Usage: r1 - r2
 * ---------------
 * Overloads the - operator so that it performs subtraction on two rational numbers
 */
    Rational operator-(Rational r1, Rational r2);

 /*
  * Operator: *
  * Usage: r1 * r2
  * --------------
  */
    Rational operator*(Rational r1, Rational r2);


/*
 * Operator: /
 * Usage: r1 / r2
 * ---------------
 * Overloads the / operatoe so that it performs division on two rational numbers
 */
    Rational operator/(Rational r1, Rational r2);



#endif // RATIONAL_H
