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
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace sdds
{
    Rectangle::Rectangle(const char* label, int w, int h) : LblShape(label)
    {
        int rqWidth = 0;
        const char* lbl = LblShape::label();
        while (lbl[rqWidth])
            rqWidth++;

        rqWidth += 2;

        //check if the provided width (w) and height (h) meet the conditions to create a rectangle
        //rectangle should have a width greater than the required width (rqWidth) and a height greater than 3
        if (w > rqWidth && h > 3)
        {
            //set the member variables m_width and m_height to the provided width and height
            m_width = w;
            m_height = h;
        }
    }

    void Rectangle::getSpecs(std::istream& is)
    {
        //call the getSpecs function of the base class LblShape to read the label from the input stream
        LblShape::getSpecs(is);

        //read the width and height of the Rectangle from the input stream
        char separator;
        is >> m_width >> separator >> m_height;

        //ignore any extra characters up to and including the newline character 
        is.ignore(1000, '\n');
    }

    void Rectangle::draw(std::ostream& ostr) const
    {
        //check if the width (m_width) and height (m_height) of the Rectangle are valid (greater than 0)
        if (m_width > 0 && m_height > 0)
        {
            //draw the label and rectangle following the provided format
            //draw first line of the rectangle
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+' << endl;

            //draw the label line of the rectangle
            ostr << '|';
            ostr.width(m_width - 2);
            ostr.fill(' ');
            ostr << left << LblShape::label() << '|' << endl;

            //draw the middle lines of the rectangle
            for (unsigned int i = 0; i < (m_height - 3); i++)
            {
                ostr << '|';
                ostr.width(m_width - 2);
                ostr.fill(' ');
                ostr << ' ' << '|' << endl;
            }

            //draw the last line of the rectangle
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+';
        }
    }
}
