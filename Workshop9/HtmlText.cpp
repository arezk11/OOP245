/*
*****************************************************************************
                        Workshop 9 - Part 1
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
#include "HtmlText.h"
#include <cstring>

namespace sdds {

    //constructor
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename)
    {
        //allocate memory for m_title
        if (title)
        {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    //copy constructor :rule of three
    HtmlText::HtmlText(const HtmlText& src) : Text(src), m_title(nullptr)
    {
        if (src.m_title)
        {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
        }
    }

    //copy assignment operator :rule of three
    HtmlText& HtmlText::operator=(const HtmlText& src)
    {
        if (this != &src)
        {
            //use the base class assignment operator 
            Text::operator=(src);
            m_title = src.m_title;
        }
        return *this;
    }


    //destructor
    HtmlText::~HtmlText()
    {
        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }
    }

    // Text::write override for HtmlText
    void HtmlText::write(std::ostream& os) const
    {
        bool multipleSpaces = false;
        char temp; 

        os << "<html><head><title>";
        if (m_title != nullptr)
        {
            os << m_title;
        }
        else
        {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";

        //write h1 tag if m_title is not null
        if (m_title)
        {
            int index = 0;
            os << "<h1>" << m_title << "</h1>\n";

            //loop through the characters of the text content
            while (Text::operator[](index) != '\0')
            {
                temp = Text::operator[](index);
                //convert special characters and handle multiple spaces
                switch (temp)
                {
                default:
                    os << temp;
                    multipleSpaces = false;
                    break;

                case ' ':
                    if (multipleSpaces) os << "&nbsp;";
                    else
                    {
                        os << temp;
                        multipleSpaces = true;
                    }
                    break;

                case '<':
                    os << "&lt;";
                    multipleSpaces = false;
                    break;

                case '>':
                    os << "&gt;";
                    multipleSpaces = false;
                    break;

                case '\n':
                    os << "<br />\n";
                    multipleSpaces = false;
                    break;
                }

                index++;
            }
        }

        //footer
        os << "</body>\n</html>";
    }
} 
