#include <iostream>
#include "vector.h"
#include <fstream>
#include "filelib.h"
#include "reversefile.h"
#include "stack_calculator.h"
#include "stack.h"
#include "strlib.h"
#include "checkoutline.h"
#include "airportcodes.h"
using namespace std;

void printFileLines();
void showLetters();
void runCalculator();
void runQueueSim();

int main() {
   runAirportLookUp();
   runQueueSim();
   runCalculator();
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


void runCalculator(){
    cout << "RPN Calculator Simulation  (type H for help)" << endl;
    Stack<double> operandStack;
    while(true) {
        cout  <<  "> ";
        string line;
        getline(cin, line);
        if(line.length() == 0 ) line = "Q";
        char ch = toupper(line[0]);
        if(ch == 'Q'){
            break;
        } else if(ch == 'C') {
            operandStack.clear();
        } else if(ch == 'H') {
            helpCommand();
        } else if(isdigit(ch)){
            operandStack.push(stringToReal(line));
        } else {
            applyOperator(ch, operandStack);
        }
    }

}

void runQueueSim(){
    int nServed;
    int totalWait;
    int totalLength;
    runSimulation(nServed, totalWait, totalLength);
    printReport(nServed, totalWait, totalLength);
}
