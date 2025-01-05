/*
*****************************************************************************
                        Workshop 5 - Part 2
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

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_mark;

    public:
        //constructors
        Mark();
        Mark(int value);

        //conversion operators
        //convert the mark to int
        operator int() const;

        //convert the mark to double
        operator double() const;

        //convert the mark to char
        operator char() const;


        //assignment operator (+=) to add the value to the mark
        Mark& operator+=(int num);
    };

    //binary helper operator (+=) to add the mark to an integer
    int operator+=(int& total, const Mark& mark);
}

#endif // SDDS_MARK_H_
