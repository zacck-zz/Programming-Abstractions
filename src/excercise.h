#ifndef EXCERCISE_H
#define EXCERCISE_H

/*
 * Function: endsWith
 * usage bool endsW = endsWith(string a, string b)
 * -----------------------------------------------
 * Returns true if a ends with b and false otherwise
 */
#include <string>

bool myEndsWith(std::string a, std::string b);

bool myEndsWith(std::string a, char c);

std::string myTrim(std::string a);

std::string mySubStr(std::string s, int pos, int length = -1);

std::string capitalize(std::string word);

int scrabbleScore(std::string word);

std::string acronym(std::string sentence);

std::string removeCharacters(std::string word, std::string characters);

void removeCharactersInPlace(std::string &word, std::string characters);

std::string removeDoubledLetters(std::string word);

std::string replaceAll(std::string s, char c, char r);

bool isSentencePalindrome(std::string s);

std::string createRegularPlural(std::string word);

std::string createOrdinalNumber(int n);

std::string addCommas(std::string digits);

#endif // EXCERCISE_H
