#include <iostream>
#include "vector.h"
#include <fstream>
#include "filelib.h"
#include "reversefile.h"
using namespace std;

void printFileLines();
void showLetters();

int main() {
   printFileLines();
   showLetters();
   return 0;
}

void printFileLines(){
    ifstream infile;
    Vector<string> lines;
    promptUserForFile(infile, "Input file: ");
    readWholeFile(infile, lines);
    for(int i = lines.size() - 1; i >= 0; i--){
        cout << lines[i] << endl;
    }
    infile.close();
}

void showLetters() {
    ifstream infile;
    promptUserForFile(infile, "Input Letter file: ");
    countLetters(infile);
    cout << endl << endl;
}
