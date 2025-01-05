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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds {


    //Line class inherits from LblShape
    class Line : public LblShape
    {
        //private member variable to store the length of the line
        int m_length;

    public:
       
        Line();

        //constructor with arguments to set the label and length of the line
        Line(const char* label, int length);

        //override the draw function to draw the line with the label to ostream
        void draw(std::ostream& os) const;

        //override the getSpecs function to read line specifications from istream
        void getSpecs(std::istream& is);
    };
}

#endif // SDDS_LINE_H
