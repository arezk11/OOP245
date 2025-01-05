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
#include "LblShape.h"

using namespace std;
namespace sdds { 


    //sets m_label to nullptr
    LblShape::LblShape() : m_label(nullptr)
    {
      
    }

    //constructor with one argument
    LblShape::LblShape(const char* label) : m_label(nullptr)
    {
       
        
        if (label != nullptr && label[0] != '\0')
        {
            //allocate dynamic memory for m_label to store the label
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }

    const char* LblShape::label() const
    {
        return m_label;
    }

    void LblShape::getSpecs(std::istream& is)
    {
        //read the label from istream up to the ',' character and store it in the local variable 'label'
        char label[1000];
        is.get(label, 1000, ',');
        is.ignore();

        //deallocate old m_label to avoid memory leaks
        delete[] m_label;
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
        m_label = nullptr;
    }
}
