//include filestream
#include <fstream>
#include <iostream>
using namespace std;

int mainy() {
    ifstream input;
    input.open("readme.txt");
    string line;
    while(getline(input, line)){
        cout << line << endl;
    }
    return 0;
}
