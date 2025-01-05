/*
*****************************************************************************
                        Workshop 8 - Part 1
Full Name  : Ali Rezk
Student ID#: 105593222
Email      : arezk1@myseneca.ca
Section    : ZRA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Shape.h"

using namespace std;

namespace sdds 
{
    std::ostream& operator<<(std::ostream& os, const Shape& shape) 
    {
        shape.draw(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Shape& shape)
    {
        shape.getSpecs(is);
        return is;
    }
}
