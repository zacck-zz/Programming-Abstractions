#include "vector.h"
using namespace std;

int binarySearch(string key, Vector<string> & vec, int p1, int p2);

/*
 * Function findInSortedVector
 * Usage: int index = findInSortedVector(key, vec)
 * -----------------------------------------------
 * Searches for the specified key in the Vector<String> vec, whch must be sorted
 * in lexicographic (character code) order. If the key is found, the function returns
 * the index in the vector at which the key appears.(If the key appears more than once
 * in the vector, any of the matching indices may be returned). If the key does not
 * exist  in the vector, the function returns -1. This implementation is simply a wrapper
 * function; all of the real work is done by the more general binarySearch function.
 */
int findInSortedVector(string key, Vector<string> & vec) {
    return binarySearch(key, vec, 0, vec.size() - 1);
}

/*
 * Function: binarySearch
 * Usage: int index = binarySearch(key, vec, p1, p2);
 * --------------------------------------------------
 * Searches for the specified key in the Vector<string> vec, looking
 * only at the indices between p1 and p2, inclusive. The function returns
 * the index of a matching element or -1 if no match is found.
 */
int binarySearch(string key, Vector<string> & vec, int p1, int p2) {
    if(p1 > p2) return -1;
    int mid = (p1 + p2) / 2;
    if (key == vec[mid]) return mid;
    if (key < vec[mid]) {
        return binarySearch(key, vec, p1, mid - 1);
    } else {
        return binarySearch(key, vec, mid + 1, p2);
    }
}
