/*
 * File: tokenizer.cpp
 * -------------------
 * This file implements the Tokenizer class. Most ot the methods are straightforward
 * enough to require no addional documentation.
 */

#include <cctype>
#include <string>
#include "tokenizer.h"
using namespace std;

Tokenizer::Tokenizer() {
    /*Empty*/
}

Tokenizer::Tokenizer(string str){
    setInput(str);
}

void Tokenizer::setInput(std::string str){
    buffer = str;
    cp = 0;
}

bool Tokenizer::hasMoreTokens(){
    if(ignoreWhitespaceFlag) skipWhitespace();
    return cp < buffer.length();
}

/*
 * Implementation notes: nextToken
 * -------------------------------
 * This method starts by looking at the character at current character indicated by the index cp.
 * If that index is past the end of the string, nextToken returns the empty string. If that character is
 * alphanumeric nextToken scans ahead until it finds the end of that word;  if not,
 * nextToken returns than character as a one character string.
 */

string Tokenizer::nextToken(){
    // are we including whitespace
    if(ignoreWhitespaceFlag) skipWhitespace();
    //process words
    if(cp >= buffer.length()) {
        // if at end of buffer return an empty space
        return "";
    } else if (isalnum(buffer[cp])) {
        // start from current postion and build a word
        int start = cp;
        while(cp < buffer.length() && isalnum(buffer[cp])) {
            cp++;
        }
        return buffer.substr(start, cp - start);
    } else {
        return string(1, buffer[cp++]);
    }
}


void Tokenizer::ignoreWhitespace(){
    ignoreWhitespaceFlag = true;
}


/*
 * Implementation notes: skipWhitespace
 * ------------------------------------
 * This method is private and is not exported. It
 * does, however, need to be declared in the private section of the
 * class, which is contained in header interface, this method is called from
 * both hasMoreTokens and nextToken.
 */

void Tokenizer::skipWhitespace(){
    while(cp < buffer.length() && isspace(buffer[cp])){
        cp++;
    }
}
