#include "langtonAnt.h"

LangtonAnt::LangtonAnt(int currX, int currY):
    currentX(currX),
    currentY(currY),
    direction(up)
{}

void LangtonAnt::doStep(bool isWhite)
{
    if (isWhite)
    {
        rotateRight();
    }
    else
    {
        rotateLeft();
    }

    followDir();
}

void LangtonAnt::rotateLeft()
{
    switch ( direction ) {
      case up :
        direction = lef;
        break;
      case righ :
        direction = up;
        break;
      case down :
        direction = righ;
        break;
    case lef :
        direction = down;
    }
}

void LangtonAnt::rotateRight()
{
    switch ( direction ) {
      case up :
        direction = righ;
        break;
      case righ :
        direction = down;
        break;
      case down :
        direction = lef;
        break;
    case lef :
        direction = up;
    }
}

void LangtonAnt::followDir()
{
    switch ( direction ) {
      case up :
        currentY = byMod((currentY - 1), gridHeight);
        break;
      case righ :
        currentX = byMod((currentX + 1), gridWidth);
        break;
      case down :
        currentY = byMod((currentY + 1), gridHeight);
        break;
    case lef :
        currentX = byMod((currentX - 1), gridWidth);
    }
}

int LangtonAnt::byMod(int value, int modValue)
{
    if (value >= modValue)
    {
        return (value - modValue);
    }
    if (value < 0)
    {
        return (value + modValue);
    }
    return value;
}

