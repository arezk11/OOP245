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
#include <cstring>
#include "Label.h"
using namespace std;

namespace sdds {

    void Label::setToDefault()
    {
        m_frame = nullptr;
        m_content = nullptr;
        m_length = 0;
    }

    void Label::setFrame(const char* frameArg) 
    {
        delete[] m_frame; //delete the existing memory allocation if anything is there

        if (frameArg != nullptr) 
        {
            
            m_length = strlen(frameArg);

            //allocate new memory for the frame and copy the input
            m_frame = new char[m_length + 1];
            strcpy(m_frame, frameArg);
        }
    }

    void Label::setContent(const char* contentArg)
    {
        delete[] m_content;
        
        m_length = strlen(contentArg);

        //allocate new memory for the content and copy the input
        m_content = new char[m_length + 1];
        strcpy(m_content, contentArg);
    }

    Label::Label()
    {
        setToDefault();
        
        //default frame
        setFrame("+-+|+-+|");
    }


    Label::Label(const char* frameArg)
    {
        setToDefault();
        setFrame(frameArg);
    }

    Label::Label(const char* frameArg, const char* contentArg)
    {
        setToDefault();
        setFrame(frameArg);
        setContent(contentArg);
    }

    Label::~Label()
    {
        delete[] m_frame;
        delete[] m_content;

    }

    void Label::readLabel()
    {
        //read a line of input from the user and set it as the content
        char temp[71];
        cout << "> ";
        cin.getline(temp, 71);
        setContent(temp);


    }

    std::ostream& Label::printLabel() const 
    {
        if (m_frame != nullptr && m_content != nullptr)
        {

            int contLen = strlen(m_content);
            int frameLen = strlen(m_frame);
            //calculate the spacing
            int leftSpace = (frameLen - contLen - 2) / 2;
            int rightSpace = frameLen - contLen - 2 - leftSpace;


            //print top frame line
            cout << m_frame[0];
            for (int i = 0; i < contLen + 2; i++)
            {
                cout << m_frame[1];
            }
            cout << m_frame[2] << endl;


            //print empty line
            cout << m_frame[7];
            for (int i = 0; i < contLen + 2; i++)
            {
                cout << ' ';
            }
            cout << m_frame[3] << endl;


            //print content line
            cout << m_frame[7] << ' ';
            for (int i = 0; i < leftSpace; i++)
            {
                cout << ' ';
            }
            cout << m_content;
            for (int i = 0; i < rightSpace; i++)
            {
                cout << ' ';
            }
            cout << ' ' << m_frame[3] << endl;


            //print empty line
            cout << m_frame[7];
            for (int i = 0; i < contLen + 2; i++) 
            {
                cout << ' ';
            }
            cout << m_frame[3] << endl;

            //print bottom frame line
            cout << m_frame[6];
            for (int i = 0; i < contLen + 2; i++)
            {
                cout << m_frame[5];
            }
            cout << m_frame[4];
        }

        return cout;
    }
}
