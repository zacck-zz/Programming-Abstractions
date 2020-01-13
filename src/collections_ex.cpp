/*
 * File: collections_ex.cpp
 * -----------------------
 * Contains a few exercises from the collections chapter
 */
#include "vector.h"
#include "collections_ex.h"
#include <math.h>
#include <string>

double mean(Vector<double> & data){
    double total = 0;

    //accumulate the total
    for(auto item : data) {
        total += item;
    }

    // calculate mean
    double mean = total / data.size();

    return mean;
}


double stddev(Vector<double> & data){
    // find the mean
    double deviation;
    double m = mean(data);

    double sqdifftotal = 0;

    //acculate the differences from mean
    for(auto item : data ){
        double meandiff = m - item;
        sqdifftotal += meandiff * meandiff;
    }

    // find deviation
    sqdifftotal = sqdifftotal / data.size();

    deviation = sqrt(sqdifftotal);

    return deviation;
}

void printHistogram(Vector<double> & data){
    Vector<int> itemnums(11, 0);

    // populate ranges
    for(auto item : data){
        if(item < 10) {
            itemnums[0]++;
        } else if(item >= 10 && item < 20){
            itemnums[1]++;
        } else if(item >= 20 && item < 30){
            itemnums[2]++;
        } else if(item >= 30 && item < 40){
            itemnums[3]++;
        } else if(item >= 40 && item < 50){
            itemnums[4]++;
        } else if(item >= 50 && item < 60){
            itemnums[5]++;
        } else if(item >= 60 && item < 70){
            itemnums[6]++;
        } else if(item >= 70 && item < 80){
            itemnums[7]++;
        } else if(item >= 80 && item < 90){
            itemnums[8]++;
        } else if(item >= 90 && item < 100){
            itemnums[9]++;
        } else {
            itemnums[10]++;
        }
    }

    for(int i = 0; i < 11; i++){
        std::string pos = std::to_string(i) + "0s";

        std::cout << pos << ": ";

        int elements = itemnums[i];

        if(elements > 0){
            for(int n = 0; n < elements; n++){
                std::cout << "*";
            }
        }

        std::cout << std::endl;
    }

}
