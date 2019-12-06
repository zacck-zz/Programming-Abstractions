/*
 * File: ReverseFile.cpp
 * --------------------------------------
 * This program displays the line sof an input file in reverse order
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "vector.h"
using namespace  std;

static const int COLUMNS = 7;

/*
 * Function : readEntireFile
 * Usage: readEntireFile(is, line)
 * ------------------------------
 * Reads the entire contents of a the specified input stream into the string
 * vector lines. The client is responsible for opening and closing the stream.
 */


void readWholeFile(istream  & is, Vector<string> & lines){
    while(true){
        string line;
        getline(is, line);
        if(is.fail()) break;
        lines.add(line);
    }
}


/*
 * Function: countLetters
 * usage: countLetters(is)
 * ------------------------
 * Counts the frequency of letters in a data file
 */
void countLetters(istream & is) {
   Vector<int> letterCounts(26);
   while(true){
       int ch = is.get();
       if(ch == EOF) break;
       if(isalpha(ch)){
           letterCounts[toupper(ch) - 'A']++;
       }
   }
   for(char ch = 'A'; ch <= 'Z'; ch++){
       cout << setw(COLUMNS) << letterCounts[ch - 'A'] << " " << ch << endl;
   }
}
