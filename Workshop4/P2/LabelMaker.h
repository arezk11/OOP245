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

#ifndef SDDS_LABELMAKER_H__
#define SDDS_LABELMAKER_H__

#include "Label.h"

namespace sdds {
    class LabelMaker 
    {
        Label* m_labels;
        int m_noOfLabels;
        void setToDefault();

    public:
        //constructor
        LabelMaker(int noOfLabels);

        //read labels from the user
        void readLabels();

        //print the labels
        void printLabels() const;

        //destructor
        ~LabelMaker();
    
    };
}

#endif //SDDS_LABELMAKER_H__
