#ifndef LANGTONANT_H
#define LANGTONANT_H

#include "grid.h"

/**
 * @file langtonAnt.h
 *
 * @section DESCRIPTION
 *
 * This file contains a definition of the enum Direction,
 * which contains all possible directions of the ant and class LangtonAnt.
 */

enum Direction
{
    up = 0,
    righ,
    down,
    lef
};

/// @class LangtonAnt
/// Object of this class is defined with two initial coordinates and
/// modifies them according to the true parameter received by method doStep(bool).
class LangtonAnt
{
public:
    /// Initial start coordinates.
    LangtonAnt(int currX, int currY);
    /// This method call method rotateLeft() if parameter isWhite - false,
    /// and rotateRight() otherwise. And call followDir().
    void doStep(bool isWhite);
    int currentX;
    int currentY;
private:
    /// Change the parameter direction like a rotate 90 degrees to the left.
    void rotateLeft();
    /// Change the parameter direction like a rotate 90 degrees to the right.
    void rotateRight();
    /// Pulls in the current direction of the 1 cell.Is that our scene torus-shaped.
    void followDir();
    /// Return a non-negative number of modulus modValue.
    int byMod(int value, int modValue);
    /// @param direction - current direction of the ant.
    Direction direction;
};

#endif // LANGTONANT_H
