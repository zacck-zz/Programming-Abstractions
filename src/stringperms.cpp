/*
 * File: stringperms
 * -----------------
 * Generates all permutations of an input string
 */
#include <iostream>
#include "set.h"
using namespace  std;

/*
 * Function: generatePermutations
 * Usage: Set<string> permutations = generatPermutations(str);
 * -----------------------------------------------------------
 * Returns a set consisting og all permutations of the specified
 * string. This implementation uses the recursive insight that
 * you can generate all permutations of a string  by selectimg
 * each character in turn, generating all permutations of the string
 * without the character, and then concatenating the selected
 * character on the front of each generated permutation
 */
Set<string> generatePermutations(string str) {
    Set<string> result;
    if(str  == "") {
        result += "";
    } else {
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            string rest = str.substr(0, i) + str.substr(i + 1);
            for(auto s : generatePermutations(rest)) {
                result += ch + s;
            }
        }
    }
    return result;
}
