/*
 * File: ShowFileContents.cpp
 * ------------------------------
 * This program displays the contents of a file chosen by the user
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
 * Function: promptForFile
 * Usage: string filename = promptUserForFile(infile, prompt);
 * Asks the user for a name of an input file and opens the reference parameter infile
 * using that name, which is returned as the result of the function. If the requested file does not exist,
 * the user is given addtitional chances to enter a valid file name. The optional prompt
 * argument is used to give the user more information about the desired input file.
 */

std::string promptForFile(std::ifstream & infile, std::string prompt){
    while (true){
        std::cout << prompt << "\n";
        std::string filename;
        getline(std::cin, filename);
        infile.open(filename.c_str());
        if(!infile.fail()) return filename;
        infile.clear();
        std::cout << "Unable to open that file. Try again." << std::endl;
        if (prompt == "" ) prompt = "Input File: ";
    }
}


/*
 * Function stringToInt
 * ----------------------
 * usage: int x = stringToInt(st);
 * Uses the c++ stream libraries to read an integer from a string
 */
int stringToInt(std::string str){
    std::istringstream stream(str);
    int value;
    stream >> value >> std::ws;
    if(stream.fail() || !stream.eof()) {
        std::cout << "stringToInt: Illegal integer format \n" << str << " \n";
    }
    return value;
}

