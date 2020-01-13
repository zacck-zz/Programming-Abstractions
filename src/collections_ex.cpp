/*
 * File: collections_ex.cpp
 * -----------------------
 * Contains a few exercises from the collections chapter
 */
#include "vector.h"
#include "collections_ex.h"

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
