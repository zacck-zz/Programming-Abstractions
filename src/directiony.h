/*
 * File: direction.h
 * -------------------
 * This interface exports an enumerated type called Direction whose elements
 * are the four compass points: NORTH, EAST, SOUTH and WEST.
 */

#ifndef _directiony_h
#define _directiony_h

#include <string>

/*
 * Type: Direction
 * --------------------
 * This enumerated type is used to represent the four compass directions.
 */

enum Directiony { NORTH, EAST, SOUTH, WEST };

/*
 * Function: leftFrom 
 * Usage: Direction newDir = leftFrom(dir);
 * ----------------------------------------
 * Returns the direcion to the left of the argument.
 * For example leftFrom(WEST) returns SOUTH.
 */

Directiony leftFrom(Directiony dir);


/*
 * Function: rightFrom
 * Usage: Direction newDir = rightFrom(dir);
 * -----------------------------------------
 * Returns the direction that is to the right of the argument 
 * For example rightFrom(NORTH) returns EAST.
 */

Directiony rightFrom(Directiony dir);

/*
 * Function: directionToString
 * Usage string str = directionToString(dir);
 * -------------------------------------------
 * Returns the name of the direction as a string.
 */

std::string directionToString(Directiony dir);


/*
 * Function: <<
 * ------------
 * Overloaded insertion operator for the direction enum
 */
std::ostream & operator<<(std::ostream & os, Directiony dir);


/*
 * Function: ++
 * ------------
 * Overloaded increment operator for the direction enum
 * Notice we don't need parameter name if we wont use that value
 */
Directiony operator++(Directiony & dir, int);

#endif
