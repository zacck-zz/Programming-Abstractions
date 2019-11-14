#include <iostream>
#include <fstream>
#include "precisionexample.h"
#include "showfilecontents.h"
#include <string>
/* Prototypes */
void runPrecision();
void runFileReader();
void sumFileNumbers();

int main() {
    std::cout << "Precision Examples" << std::endl;
    runPrecision();
    std::cout << std::endl << std::endl;
    runFileReader();
    std::cout << std::endl << std::endl;
    sumFileNumbers();
    return 0;
}


void runPrecision() {
    std::cout << std::uppercase << std::right;
    std::cout << "Default Format: " << std::endl << std::endl;
    printPrecisionTable();
    std::cout << std::endl << "Fixed Format: " << std::fixed  << std::endl << std::endl;
    printPrecisionTable();
    std::cout << std::endl << "Scientific Format: " << std::scientific << std::endl << std::endl;
    printPrecisionTable();
}


void runFileReader() {
    std::ifstream infile;
    promptForFile(infile, "Input file: \n");
    while(true){
        int ch = infile.get();
        if(ch == EOF) break;
        std::cout.put(ch);
    }
    infile.close();
}

void sumFileNumbers(){
    std::ifstream infile;
    promptForFile(infile, "Input file with numbers \n");
    int total = 0;
    while(true){
        std::string line;
        getline(infile, line);
        if (infile.fail()) break;
        total += stringToInt(line);
    }
    infile.close();
    std::cout << "The sum is " << total  << std::endl;
}
