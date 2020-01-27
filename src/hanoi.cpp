/*
 * File: hanoi.cpp
 * ---------------
 * This program solves the Tower of Hanoi Puzzle
 */
#include <iostream>
using namespace  std;

/*
 * Function: moveSingleDisk
 * Usage: moveSingleDisk(int n, char c, char a, char b);
 * ----------------------------------------------------
 * Utility function to log out currenly moving disks
 */
void moveSingleDisk(char start, char finish) {
    cout << start << " -> " << finish << endl;
}

/*
 * Function: moveTower
 * Usage: moveTower(height, start, finish, temp);
 * ----------------------------------------------
 * Recursive function to move the towers of hanoi
 */
void moveTower(int n, char start, char finish, char tmp) {
    if(n == 1) {
        moveSingleDisk(start, finish);
    } else {
        moveTower(n - 1, start, tmp, finish);
        moveSingleDisk(start, finish);
        moveTower(n - 1, tmp, finish, start);
    }
}
