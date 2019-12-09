/*
 * File: airportcodes.cpp
 * ----------------------
 * Looks up a three letter airpord code in a map object
 */


#include <iostream>
#include <fstream>
#include <string>
#include "error.h"
#include "map.h"
#include "strlib.h"
using namespace std;



void readCodeFile(string filename, Map<string, string> & map){
    ifstream infile;
    infile.open(filename.c_str());
    if(infile.fail()) error("Can't read the data file");
    while(true){
        string line;
        getline(infile, line);
        if(infile.fail()) break;
        if(line.length() < 4 || line[3] != '='){
            error("Illegal data line: " + line);
        }
        string code = toUpperCase(line.substr(0, 3));
        map.put(code, line.substr((4)));
    }
    infile.close();
}

void runAirportLookUp(){
    Map<string, string> airportCodes;
    readCodeFile("airportcodes.txt", airportCodes);
    while(true) {
        string line;
        cout << "Airport Code: ";
        getline(cin, line);
        if(line == "") break;
        string code = toUpperCase(line);
        if(airportCodes.containsKey(code)){
            cout << code << " is in " << airportCodes.get(code) << endl;
        } else {
            cout << "There is no such airport code " << endl;
        }
    }
}
