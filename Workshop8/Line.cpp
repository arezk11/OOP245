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
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {
    Line::Line() : LblShape(), m_length(0) {}

    Line::Line(const char* label, int length) : LblShape(label), m_length(0)
    {
        //check if the length is valid (greater than 0)
        if (length > 0)
        {
            //set the length of the member variable to the valid value
            m_length = length;
        }
    }

    void Line::draw(std::ostream& os) const
    {
        //check if the label is not empty and the length is greater than 0
        if (label() != nullptr && m_length > 0)
        {
            //print the label on a new line
            os << label() << endl;

            //draw the line using = repeated by the m_length times
            for (int i = 0; i < m_length; i++)
            {
                os << "=";
            }

        }
    }

    void Line::getSpecs(std::istream& is)
    {
        //call the getSpecs function of the base class LblShape to read the label from the input stream
        LblShape::getSpecs(is);

        //read the length of the Line from the input stream
        is >> m_length;

        //ignore any extra characters up to and including the newline character ('\n')
        is.ignore();
    }
}
