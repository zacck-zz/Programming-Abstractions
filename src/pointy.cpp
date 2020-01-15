/*
 * File: pointy.cpp
 * ------------
 * Implementation for the pointy class
 */
#include <string>
#include "strlib.h"
#include "pointy.h"

using namespace std;


/*
 * Constructors
 * ------------
 * The constructors initialize the instance variables x and y. In the second
 * form of the constructor, the parameter names are xc and yc to avoid the problem
 * of shadowing the instance variables.
 */
Pointy::Pointy() {
    x = 0;
    y = 0;
}

Pointy::Pointy(int xc, int yc) {
    x = xc;
    y = yc;
}


/*
 * Getters
 * --------
 * The getters return the value of the corresponding instance variable.
 * No setters are provided to ensure than Pointy objects are immutable.
 */
int Pointy::getX() {
    return x;
}

int Pointy::getY() {
    return y;
}


/*
 * toString
 * --------
 * The implementation of toString uses the integerToString function
 * from the strlib.h interface.
 */
string Pointy::toString() {
    return "(" + integerToString(x) + "," + integerToString(y) + ")";
}

/*
 * Overloaded <<
 * -------------
 * Input operator overloaded to enable printing of the Pointy instance
 */
ostream & operator<<(ostream & os, Pointy pt) {
    return os << pt.toString();
}

/*
 * Overlloaded ==
 * ---------------
 * Equality operator to check that two pointy points are equal
 */
bool operator==(Pointy p1, Pointy p2){
    return p1.x == p2.x && p1.y == p2.y;
}

