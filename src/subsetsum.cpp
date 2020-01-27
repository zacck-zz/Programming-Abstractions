#include "set.h"

bool subSetSumExists(Set<int> & set, int target) {
    if(set.isEmpty()) {
        return target == 0;
    } else {
        int element = set.first();
        Set<int> rest = set - element;
        return subSetSumExists(rest, target) || subSetSumExists(rest, target - element);
    }
}
