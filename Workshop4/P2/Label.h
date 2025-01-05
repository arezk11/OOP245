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
#ifndef SDDS_LABEL_H__
#define SDDS_LABEL_H__

#include <iostream>
#include <cstring>
namespace sdds {
    class Label 
    {
        char* m_frame;
        char* m_content;
        int m_length;
        void setToDefault();
        void setFrame(const char* frameArg);
        void setContent(const char* contentArg);

    public:
         //default constructor
        Label();

        //constructor with the frame argument
        Label(const char* frameArg);

        //constructor with frame and content argument
        Label(const char* frameArg, const char* contentArg);

        //destructor
        ~Label();

        void readLabel();
        std::ostream& printLabel() const;
   
    };
}

#endif // SDDS_LABEL_H__
