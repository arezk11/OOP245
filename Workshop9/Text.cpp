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
#include <fstream>
#include "Text.h"
#include <cstring>

using namespace std;
namespace sdds {

    void Text::clear() 
    {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;
    }

    //returns the length (size) of the text file on the disk.
    int Text::getFileLength() const
    {
        int len = 0;
        ifstream fin(m_filename);

        while (fin) 
        {
            fin.get();
            len += !!fin;
        }

        
        return len;
    }

    const char& Text::operator[](int index) const 
    {
        if (index >= 0 || index < getFileLength())
        {
            return m_content[index];
        }
        
       // The behaviour of the operator is not defined if the index goes out of bounds.
        return m_content[getFileLength()];
    }

    Text::Text(const char* filename) 
    {
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
    }

    // The rule of three
    Text::Text(const Text& src) : m_filename(nullptr), m_content(nullptr)
    {
        if (src.m_filename) 
        {
            m_filename = new char[strlen(src.m_filename) + 1];
            strcpy(m_filename, src.m_filename);
        }

        if (src.m_content)
        {
            m_content = new char[strlen(src.m_content) + 1];
            strcpy(m_content, src.m_content);
        }
    }

  
    // Copy assignment operator
    Text& Text::operator=(const Text& src) 
    { 
        // Self-assignment check
        if (this == &src) 
        {
            return *this;
        }

        //clear existing memory before copying new data
        clear();

        if (src.m_filename) 
        {
            m_filename = new char[strlen(src.m_filename) + 1];
            strcpy(m_filename, src.m_filename);
        }

        if (src.m_content) 
        {
            m_content = new char[strlen(src.m_content) + 1];
            strcpy(m_content, src.m_content);
        }

        return *this;
    }


    Text::~Text()
    {
        clear();
        
    }   

    void Text::read()
    {
        char temp;
        int index = 0;

        // read the file
        ifstream inputFile(m_filename);
        

        // delete the current content of the file
        delete[] m_content;
      

        if (inputFile.is_open())
        {
            //allocates memory to the size of the file on the disk + 1 (for the null byte).
            m_content = new char[getFileLength() + 1];

            //read the contents of the file character by character
            while (inputFile.get(temp))
            {
                m_content[index] = temp;
                index++;
            }

            //terminates it with a null byte at the end.
            m_content[index] = '\0';
        }

        else
        {
            delete[] m_content;
            m_content = nullptr;
        }
    }

    void Text::write(std::ostream& os) const 
    {
        if (m_content) 
        {
           os << m_content;
        } 
    }

    std::ostream& operator<<(std::ostream& os, const Text& src)
    {
        src.write(os);
        return os;
    }
}