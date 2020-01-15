/*
 * File: direction.h
 * -------------------
 * This interface exports an enumerated type called Direction whose elements
 * are the four compass points: NORTH, EAST, SOUTH and WEST.
 */

#ifndef _direction_h
#define _direction_h

#include <string>

/*
 * Type: Direction
 * --------------------
 * This enumerated type is used to represent the four compass directions.
 */

enum Direction { NORTH, EAST, SOUTH, WEST };

/*
 * Function: leftFrom 
 * Usage: Direction newDir = leftFrom(dir);
 * ----------------------------------------
 * Returns the direcion to the left of the argument.
 * For example leftFrom(WEST) returns SOUTH.
 */

Direction leftFrom(Direction dir);


/*
 * Function: rightFrom
 * Usage: Direction newDir = rightFrom(dir);
 * -----------------------------------------
 * Returns the direction that is to the right of the argument 
 * For example rightFrom(NORTH) returns EAST.
 */

Direction rightFrom(Direction dir);

/*
 * Function: directionToString
 * Usage string str = directionToString(dir);
 * -------------------------------------------
 * Returns the name of the direction as a string.
 */

std::string directionToString(Direction dir);

#endif
