/*
 * File: Excercise.cpp
 * --------------------
 * This program contains the exercises from the strings chapter of the cpp text
 */
#include<iostream>
#include <cctype>
#include <string>
#include <ctype.h>
#include "excercise.h"
using namespace std;

/* Prototypes */
int findFirstAlNum(string s);
int findLastAlNum(string s);
int letterScore(char c);


/*
 * Function: myEndsWith
 * Usage: bool e = myEndsWith(string a, string b);
 * ---------------------------------------------
 * Checks to see iuf the string a ends with substring b
 */

bool myEndsWith(string a, string b) {
    if(a.length() < b.length()) {
        return false;
    } else {
        int substart = a.length() - b.length();

        string endOfA = a.substr(substart);

        for (int i = 0; i < b.length(); i++) {
            if(b[i] != endOfA[i]) return false;
        }
        return true;
    }
}


bool myEndsWith(string a, char c ) {
    if(a.length() < 1) {
        return false;
    } else {
        char end = a[a.length() - 1];
        if(end != c ) return false;
    }
    return true;
}

/*
 * Function: myTrim
 * Usage string s = myString(string withSpaces);
 * ---------------------------------------------
 * Returns a new string with all leading and trailing spaces removed
 */

string myTrim(string s) {
    int start = findFirstAlNum(s);
    int end = findLastAlNum(s);

    // Compute the lenght by substracting the end index and 1 to make it a valid 0 based index
    return s.substr(start, s.length() - 1 - end);
}

/*
 * Function: findFirstAlNum
 * usage int x = findFirstAlNum(string s);
 * ----------------------------------------
 * Walks a string from the beginning to try and find its first alphanumerical character
 */

int findFirstAlNum(string s) {
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) return i;
    }
    return s.length() - 1 ;
}


/*
 * Function: findLastAlNum
 * usage int y = findFirstAlNum(string s);
 * ---------------------------------------
 * Walks a string from the end to determine its last alphanumeric characters position
 */

int findLastAlNum(string s ) {
    for(int i = s.length() - 1; i == 0; i--) {
        if(isalnum(s[i])) return i;
    }
    return 0;
}


/*
 * Function: mySubStr
 * usage string s = mySubStr(string b, int pos, int len);
 * ---------------------------------------------------------
 * Returns the substring of b starting at position pos and for
 * length len. If len is not provided or greater than the end of b then
 * the rest of the string from pos is returned
 */

string mySubStr(string b, int pos, int len) {
    if(pos > b.length()) {
        string e =  b + " is too short for a substring beginning at " + to_string(len);
        cerr << e << endl;
        return e;
    } else if(len == -1 || len >= b.length() ){
        return b.erase(0, pos + 1);
    } else {
        b.erase(0, pos + 1);
        return b.erase(len);
    }
}


/*
 * Function: capitalize
 * Usage string c = capitalize(string s)
 * -------------------------------------
 * Make the first character in s capitalized and makes the rest of the characters lower case
 */

string capitalize(string s ) {
    string result = "";

    for(int i = 0; i < s.length(); i++) {
        if(i == 0) {
            result += char(toupper(s[i]));
        } else {
            result += char(tolower(s[i]));
        }
    }

    return result;
}


/*
 * Function: scrabbleScore
 * Usage int score = scrabbleScore(string w);
 * ------------------------------------------
 * Walks through a word accumulating the scrabble scores of each letter
 */

int scrabbleScore(string word) {
    int score = 0;
    for (int i = 0; i < word.length(); i++) {
        score += letterScore(word[i]);
    }
    return score;
}

/*
 * Function: letterScore
 * usage int lScore = letterScore(char c);
 * ---------------------------------------
 * Calculates and returns a letter's scrabble score according to the rules in the text
 */

int letterScore(char c) {
    switch (c) {
    case 'A': case 'E': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
        return 1;
    case 'D': case 'G':
        return 2;
    case 'B': case 'C': case 'M': case 'P':
        return 3;
    case 'F': case 'V': case 'W': case  'H': case 'Y':
        return 4;
    case 'K':
        return 5;
    case 'J': case 'X':
        return 8;
    case 'Q': case 'Z':
        return 10;
    default:
        return 0;
    }
}


/*
 * Function: acronym
 * Usage string acro = acronym(string sentence);
 * ---------------------------------------------
 * Uses the rules in the test to build acroymns out of strings
 */

string acronym(string s) {
    string result = "";
    for(int i = 0; i < s.length(); i++) {
        if(i == 0) {
            result += toupper(s[i]);
        } else if (!isalpha(s[i])) {
            result += toupper(s[i + 1]);
        }
    }

    return result;
}


/*
 * Function: removeCharacters
 * Usage string s = removeCharacters(string word, string chars);
 * ------------------------------------------------------------
 * Removed characters in chars from the word
 */

string removeCharacters(string s, string chars) {
    string result = "";

    for(int i = 0; i < s.length(); i++) {
        if(chars.find(s[i]) == string::npos) {
            result += s[i];
        }
    }

    return result;
}

/*
 * Function: removeCharacters in place
 * Usage removeCharactersInPlace(string s, string chars);
 * ------------------------------------------------------
 * Removes characters in place
 */

void removeCharactersInPlace(string &s, string chars) {
    for(int i = 0; i < s.length(); i++) {
        if(chars.find(s[i]) != string::npos) {
            s.erase(i, 1);
        }
    }
}


/*
 * Function: removeDoubledLetter
 * Usage string american = removeDoubledLetter(string s);
 * ------------------------------------------------------
 * Removed doubled letters in a string
 */
string removeDoubledLetters(string s){
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == s[i + 1]){
            s.erase(i, 1);
        }
    }
    return s;
}

/*
 * Function: replaceAll
 * Usage string s = replaceAll(string word, char c, char r)
 * --------------------------------------------------------
 * Replaces all c characters in a string word with and returns the new string
 */

string replaceAll(string s, char c, char r) {
    string sR(1, r);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == c) {
            s.replace(i, 1, sR);
        }
    }

    return s;
}

/*
 * Function: isSentencePalindrome
 * Usage bool y = isSentencePalindrome(str)
 * ----------------------------------------
 * Checks if a sentence is a palindrome
 */

bool isSentencePalindrome(string s) {
    string clean ="";
    for(int i = 0; i < s.length(); i++) {
        if(isalpha(s[i])) clean += tolower(s[i]);
    }

    for(int i = 0; i < clean.length()/2; i++) {
        if(clean[i] != clean[clean.length() - i - 1]) return false;
    }

    return true;
}


/*
 * Function: createRegularPlural
 * Usage string s = createRegularPlural(string word);
 * --------------------------------------------------
 * Uses the rules in the text to build word plurals
 */

string createRegularPlural(string s) {
    string vowels = "aeiou";
    if(myEndsWith(s, "s") || myEndsWith(s, 'x') ||
            myEndsWith(s, 'z') || myEndsWith(s, "ch") || myEndsWith(s, "sh")){
        return s + "es";
    } else if (myEndsWith(s, "y") && vowels.find(s[s.length() - 2]) == string::npos) {
        return s.replace(s.length() -1, 1, "ies" );
    } else {
        return s + "s";
    }
}

/*
 * Function: createOrdinalNumber
 * Usage: string ordinal = createOrdinalNumber(int n);
 * --------------------------------------------------
 * Checks the last digit of a number to determine what suffix to give the number to
 * make it an ordinal number
 */

string createOrdinalNumber(int n) {
    string s = to_string(n);
    if(myEndsWith(s, "11")) {
        return s + "th";
    } else if (myEndsWith(s, '1')) {
        return s + "st";
    } else if (myEndsWith(s, '2')) {
        return s + "nd";
    } else if (myEndsWith(s, '3')) {
        return s + "rd";
    } else {
        return s + "th";
    }
}


/*
 * Function: addCommas
 * Usages string commadNo = addCommas(string digits)
 * -------------------------------------------------
 * Adds commas every three digits from the right of a string
 */

string addCommas(string digits) {
    for(int i = digits.length(); i > 3; i = i - 3 ) {
        digits.insert(i - 3, ",");
    }

    return digits;
}

