/*
 * File: collections_ex.cpp
 * -----------------------
 * Contains a few exercises from the collections chapter
 */
#include "vector.h"
#include "collections_ex.h"
#include <math.h>

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
