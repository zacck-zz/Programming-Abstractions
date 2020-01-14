/*
 * File: Pointy.h
 * --------------
 * This interface exports the Point class, which represents a point on a two dimensional integer grid
 */

#ifndef POINTY_H
#define POINTY_H

#include <string>
class Pointy{
public:
/*
 * Constructor: Pointy
 * Usage: Pointy origin;
 *        Pointy pt(xc, yc);
 * -------------------------
 * Crearws a Pointy object. The default constructor sets the coordinatwe to 0;
 * the second form sets the coordinate to xc and yc
 */
    Pointy();
    Pointy(int xc, int yc);

/*
 * Methods: getX, getY
 * Usage : int x = pt.getX();
 *         int y = pt.getY();
 * --------------------------
 * These methods returns the x and y coordinates of a point
 */

    int getX();
    int getY();

/*
 * Method: toString
 * Usage: string str = pt.toString();
 * ----------------------------------
 * Returns a string represantation of the Pointy in the form of "(x,y)".
 */
    std::string toString();

/*
 * Method: <<
 * Usage ostream = << pt
 */
    std::ostream & operator<<(std::ostream & os);

private:
    int x;  // the x coordinate
    int y;  // the y coordinate
};


#endif // POINTY_H
