#include <iostream>
#include <fstream>
#include "precisionexample.h"
#include "showfilecontents.h"


/* Prototypes */
void runPrecision();
void runFileReader();

int main() {
    std::cout << "Precision Examples" << std::endl;
    runPrecision();
    std::cout << std::endl << std::endl;
    runFileReader();
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
    promptForFile(infile, "Input file: ");
    while(true){
        int ch = infile.get();
        if(ch == EOF) break;
        std::cout.put(ch);
    }
    infile.close();
}
