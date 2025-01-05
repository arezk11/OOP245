/*
*****************************************************************************
                        Workshop 4 - Part 2
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
#include <iostream>
#include "LabelMaker.h"

using namespace std;

namespace sdds {
    //set to default values
    void LabelMaker::setToDefault() 
    {
        m_labels = nullptr;
        m_noOfLabels = 0;
    }

    //constructor
    LabelMaker::LabelMaker(int noOfLabels) 
    {
        setToDefault();

        if (noOfLabels > 0) 
        {
            
            m_noOfLabels = noOfLabels;
            m_labels = new Label[m_noOfLabels];

        }
    }

    //read labels from the user
    void LabelMaker::readLabels() 
    {
        if (m_labels != nullptr) 
        {
            cout << "Enter " << m_noOfLabels << " labels:" << endl;

            for (int i = 0; i < m_noOfLabels; i++) 
            {
                cout << "Enter label number " << i + 1 << endl;
                m_labels[i].readLabel();

            }
        }
    }

    //print the labels
    void LabelMaker::printLabels() const 
    {
        if (m_labels != nullptr)
        {
            for (int i = 0; i < m_noOfLabels; i++) 
            {
                m_labels[i].printLabel();
                cout << endl;

           
            }
        
        
        }
    }

    //destructor
    LabelMaker::~LabelMaker() 
    {
        delete[] m_labels;
    }
}
