#include <iostream>
#include <iomanip>
#include "fib.h"
using namespace std;

int fact(int n);
void fibby();
bool isPalindrome(string str);
bool isSubstringPalindrome(string str, int p1, int p2);

int main(){
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

