#include <iostream>
#include "directiony.h"
#include "rational.h"

using namespace std;


void cycleDirs();
void rationalOps();

int classy(){
    cout << "Working with Classes" << endl;

    rationalOps();

    cout << endl;

    cycleDirs();
    return 0;
}


void cycleDirs(){
    for(Directiony d = NORTH; d <= WEST; d++) {
        cout << d << endl;
    }
}


void rationalOps(){
    Rational r1 = Rational(1, 2);
    Rational r2 = Rational(3, 5);

    cout << r2 <<" + " << r1 << " = "<< (r1 +r2) << endl;
    cout << r1 << " / " << r2 << " = " << (r1 / r2) << endl;
    cout << r1 << " * " << r2 << " = " << (r1 * r2) << endl;
    cout << r1 << " - " << r2 << " = " << (r1 - r2) << endl;

}
