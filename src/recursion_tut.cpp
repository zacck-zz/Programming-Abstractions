#include <iostream>
#include <iomanip>
#include "fib.h"
#include "binarysearch.h"
#include "vector.h"
using namespace std;

int fact(int n);
void fibby();
bool isPalindrome(string str);
bool isSubstringPalindrome(string str, int p1, int p2);
bool isEven(unsigned int n);
bool isOdd(unsigned int n);


int main(){

    cout << "Determining if a  number is odd through mutual recursion" << endl;

    unsigned int n = 1856;

    if(isEven(n)) {
        cout << n << " is even";
    } else {
        cout << n  << " is odd";
    }


    Vector<string> vec {"Zacck", "Carla", "Rose", "Vanessa", "Janet", "Christa", "Charlie", "Vian", "David"};

    // sort the vector
    vec.sort();


    cout << "Running binary search" << endl << "Rose is in position: " << findInSortedVector("Rose", vec) << endl << endl;

    fibby();

    if(isPalindrome("eye")) {
        cout << "eye is a palindrome" << endl;
    }

    if(!isPalindrome("beste")){
        cout << "Beste is not a palindrome" << endl;
    }

    cout << endl << endl << endl;
    cout << fact(5) << endl;
    return 0;
}


void fibby(){
    cout << "This program lists the fibonacci sequence"<< endl;

    for(int i = 0; i <= 20; i++){
        if(i < 10) cout << " ";
        cout << "fib("<< i << ")";
        cout << " = " << setw(4) << fib(i) << endl;
    }
}

int fact(int n) {
    if(n == 0) {
        return 1;
    } else {
        int result = n * fact(n - 1);
        cout << "Result of " << n <<   " is currently: " << result << endl;
        return result;
    }
}

/*
 * Function: isPalindrome
 * Usage: if (isPalindrome(str)) ...
 * ---------------------------------
 * Returns true if str is a palindrome, which is a string that read the same backwards
 * as forwards.
 */
bool isPalindrome(string str) {
    return isSubstringPalindrome(str, 0, str.length() - 1);
}


/*
 * Function: isSubstringPalindrome
 * Usage: if(isSubstringPalindrome(str, p1, p2)) ....
 * --------------------------------------------------
 * Returns true if the characters in str from p1 to p2 inclusive form
 * a palindrome. This implementation uses the recursive insight that all
 * strings of length 0 or 1 are palindromes (the simple case) and that
 * longer strings are palindromes only if their first and last characters
 * match and the remainig substring is a palindrome.
 */
bool isSubstringPalindrome(string str, int p1, int p2) {
    if (p1 >= p2){
        return true;
    } else {
        return str[p1] == str[p2] && isSubstringPalindrome(str, p1 + 1, p2 -1);
    }
}


/* Mutual Recursion */

/*
 * Function: isOdd
 * Usage: if(isOdd(n)) ....
 * ------------------------
 * Returns true of the unsigned number n is odd. A number is off if it is not even.
 */
bool isOdd(unsigned int n) {
    return !isEven(n);
}


/*
 * Function: isEven
 * Usage: if (isEven(n))....
 * -------------------------
 * Returns true if the unsigned number n is even. A number is
 * even either (1) if it is zero or (2) if its predecessor is odd.
 */
bool isEven(unsigned int n) {
    if(n == 0) {
        return true;
    } else {
        return isOdd(n - 1);
    }
}

