#include <iostream>
#include "directiony.h"

using namespace std;


void cycleDirs();

int main(){
    cout << "Working with Classes" << endl;

    cycleDirs();
    return 0;
}


void cycleDirs(){
    for(Directiony d = NORTH; d <= WEST; d++) {
        cout << d << endl;
    }
}
