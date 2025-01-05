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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"
using namespace std;
namespace sdds {
    Mark::Mark()
    {
        m_mark = 0;
    }

    Mark::Mark(int value)
    {
        if (value < 0 || value > 100)
        {
            m_mark = -1;
        }
        else
        {
            m_mark = value;
        }
    }


    //conversion operator to int
    Mark::operator int() const
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
           return m_mark;
        }
        return 0;
    }


    //conversion operator to double
    Mark::operator double() const 
    {


        double GPA = 0.0;

        //to determine the grade based on the value of m_mark
        if (m_mark >= 80) 
        {
            GPA = 4.0;
        }
        else if (m_mark >= 70) 
        {
            GPA = 3.0;
        }
        else if (m_mark >= 60)
        {
            GPA = 2.0;
        }
        else if (m_mark >= 50) 
        {
            GPA = 1.0;
        }
        else
        {
            GPA = 0.0;
        }
        return GPA;
    
    
    }

    //conversion operator to char
    Mark::operator char() const 
    {
        char grade;
        if (m_mark >= 80 && m_mark <= 100) 
        {
            grade= 'A';
        }
        else if (m_mark >= 70) 
        {
            grade= 'B';
        }
        else if (m_mark >= 60)
        {
            grade= 'C';
        }
        else if (m_mark >= 50) 
        {
            grade= 'D';
        }
        else if (m_mark > 0)
        {
            grade= 'F';
        }
        else 
        {
            grade= 'X';
        }

        return grade;
    }
   


    //addition assignment operator
    Mark& Mark::operator+=(int num) 
    {
        if (m_mark >= 0 && m_mark <= 100) 
        {
            m_mark += num;

            if (m_mark >= 100)
            {
                //if mark exceeds 100 after adding reset it to 0
                m_mark = 0;
            }
        }
        else 
        {
            //if mark is not within the valid range reset to 0
            m_mark = 0;

        }

        return *this;
    }

    //binary helper operator (+=) to add the mark to an integer
    int operator+=(int& total, const Mark& mark) 
    {

        total += int(mark);

        return total;
    }

}