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

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds
{
    //Rectangle class inherits from LblShape
    class Rectangle : public LblShape
    {
        //private member variables for width and height of the rectangle
        unsigned int m_width{ 0 };
        unsigned int m_height{ 0 };

    public:
        //default constructor for Rectangle
        Rectangle() {}

        //constructor with arguments to set the label, width, and height of the rectangle
        Rectangle(const char* label, int w, int h);

        //vrtual destructor for Rectangle
        virtual ~Rectangle() {}

        //override the getSpecs function to read rectangle specifications from istream
        void getSpecs(std::istream& istr);

        //override the draw function to draw the rectangle with the label to ostream
        void draw(std::ostream& ostr) const;
    };
}

#endif // SDDS_RECTANGLE_H_
