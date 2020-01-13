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
#include "pigenglish.h"
#include "collections_ex.h"
using namespace std;

void printFileLines();
void showLetters();
void runCalculator();
void runQueueSim();
void runExcercises();

int main() {
   runExcercises();
   /* printPigEnglishWords();
   runAirportLookUp();
   runQueueSim();
   runCalculator();
   printFileLines();
   showLetters();
  */
   return 0;
}

void runExcercises(){
    int max = 1000;
    Vector<int> primes = eratosthenePrimes(max);
    for(auto n : primes){
        cout << n << ",";
    }
    cout << endl << "There are " << primes.size() << " primes under " << max << endl;
    cout << endl << endl;


    Vector<double> histNums {100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80};
    printHistogram(histNums);
    cout << endl << endl;


    Vector<double> numbers {5.5, 4, 6,8.8, 9.0, 10.1, 12};
    double stdev = stddev(numbers);
    cout << "Standard Deviation is: " << stdev << endl;
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
