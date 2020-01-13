/*
 * File: pigenglish.cpp
 * -------------------
 * Finds all english words that remain english when you convert
 * them to pig latin. Ignores words without vowels
 */

#include <iostream>
#include <string>
#include <cctype>
#include "lexicon.h"
#include "piglatintranslator.h"
using namespace std;


void printPigEnglishWords(){
    cout << "Finds an English word that remains words"
         << " When translated to pig latin " << endl;
    Lexicon english("EnglishWords.dat");
    for(auto s : english){
        string pig = wordToPigLatin(s);
        if(pig != s && english.contains(pig)){
            cout << s << " -> " << pig << endl;
        }
    }
}
