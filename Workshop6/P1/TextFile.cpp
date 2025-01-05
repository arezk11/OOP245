/*
*****************************************************************************
                        Workshop 6 - Part 1
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
#include <string>
#include "TextFile.h"
#include <cstring>

using namespace std;

namespace sdds
{
    
    Line::operator const char* () const
    {
        return (const char*)m_value;
    }

    Line::~Line()
    {
        delete[] m_value;
        m_value = nullptr;
    }

    Line& Line::operator=(const char* lineValue)
    {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }

    unsigned TextFile::lines() const
    {
        return m_noOfLines;
    }

    const char* TextFile::name() const
    {
        return m_filename;
    }
    void TextFile::setEmpty()
    {
        
            delete[] m_textLines;
            m_textLines = nullptr;
      
            delete[] m_filename;
            m_filename = nullptr;
      
            m_noOfLines = 0;
    }
    void TextFile::setFilename(const char* fname, bool isCopy)
    {
        if (!isCopy)
        {
            //dynamically allocate m_filename and copy fname directly
            m_filename = new char[strlen(fname) + 1];
            
            //copy fname to m_filename
            strcpy(m_filename, fname);
        }
        else 
        {

            //dynamically allocate m_filename and prepend "C_" to the fname argument
            m_filename = new char[strlen(fname) + 3 + 1]; //add space for C_ and the null terminator

            //copy C_ to the beginning of m_filename
            strcpy(m_filename, "C_");

            //concatenate fname to m_filename, appending it after "C_"
            strcat(m_filename, fname);

        }
    }
    void TextFile::setNoOfLines()
    {
        ifstream inputFile(m_filename);

        string line;

        m_noOfLines = 0;

        if (inputFile.is_open())
        {
            //read each line 
            while (getline(inputFile, line)) 
            {
                m_noOfLines++;
            }
        }
        else
        {
            //handel the error if the file failed to open 
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText()
    {
        if (m_filename != nullptr) {
            
            //delete m_textLines before loading to prevent memory leaks
            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }
            

            //allocate memory for m_textLines based on the number of lines 
            m_textLines = new Line[m_noOfLines];

            
            ifstream file(m_filename);
            string line;

            int counter = 0;

            if (file.is_open()) {
                //read each line from the file and store it in m_textLines
                while (getline(file, line))
                {
                    //allocate memory for the line and copy the content
                    m_textLines[counter].m_value = new char[strlen(line.c_str()) + 1];

                    strcpy(m_textLines[counter].m_value, line.c_str());
                    counter++;
                }
            }

            // make sure to update the value of m_noOfline to the actual number of lines read
            m_noOfLines = counter;
        }
    }
   

    void TextFile::saveAs(const char* fileName) const
    {
        
        ofstream outputFile(fileName);

        
        if (outputFile.is_open())
        {
            //write each line from m_textLines to the output file
            for (unsigned i = 0; i < m_noOfLines; i++) 
            {
                //write each line followed by a new line character
                outputFile << m_textLines[i].m_value << '\n';
            }

            //close the file
            outputFile.close();
        }
    }

    TextFile::TextFile(unsigned pageSize)
    {
        //set the page size
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize)
    {
         m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
        //set the page size
        m_pageSize = pageSize;

        if (filename != nullptr) 
        {
            //allocate memory for the filename and copy it
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);

            setNoOfLines();
            loadText();
        }
    }

    

    TextFile::TextFile(const TextFile& src)
    {
        // Copy the number of lines and page size from the source file
        m_noOfLines = src.m_noOfLines;
        m_pageSize = src.m_pageSize;

        //check if the source file has valid lines
        if (src.m_textLines && src.m_noOfLines > 0) 
        {
            //set the filename as a copy of the source filename
            setFilename(src.m_filename, true);
            //allocate memory for the lines
            m_textLines = new Line[m_noOfLines];

            //copy each line from the source to the current file
            for (unsigned i = 0; i < m_noOfLines; i++) 
            {
                m_textLines[i].m_value = new char[strlen(src.m_textLines[i].m_value) + 1];
                strcpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
            }

            saveAs(m_filename);

        }
    }

    TextFile& TextFile::operator=(const TextFile& rhs)
    {
        //check for selfassignment
        if (this != &rhs) 
        {
            //deallocate the dynamic array of text
            delete[] m_textLines;
            m_textLines = nullptr;
            

            
            if (rhs.m_textLines && rhs.m_noOfLines > 0) 
            {
                m_noOfLines = rhs.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                unsigned i = 0;

                while (i < m_noOfLines) 
                {
                    m_textLines[i].m_value = new char[strlen(rhs.m_textLines[i].m_value) + 1];

                    //copy the text from rhs to the current object
                    strcpy(m_textLines[i].m_value, rhs.m_textLines[i].m_value);
                    i++;
                }

                saveAs(m_filename);
            }
            else
            {
                setEmpty();
            }
        }

        return *this;
    }

    std::ostream& TextFile::view(std::ostream& ostr) const
    {
        if (m_filename != nullptr )
        {
            ostr << m_filename << '\n';
            
            //underline
            ostr.fill('=');
            ostr.width(strlen(m_filename));
            ostr << '=' << endl;

            for (unsigned i = 0; i < m_noOfLines; ++i)
            {
                //print each line 
                ostr << (*this)[i] << '\n';

                if ((i + 1) % m_pageSize == 0 )
                {
                    ostr << "Hit ENTER to continue...";

                    cin.ignore(1000, '\n');
                }

            }
        }

        return ostr;
    }

    

    std::istream& TextFile::getFile(std::istream& istr) 
    {
        std::string filename;

        //read the filename from the input stream
        std::getline(istr, filename); 

        setFilename(filename.c_str());

        setNoOfLines();

        loadText();

        return istr;
    }
    



    const char* TextFile::operator[](unsigned index) const 
    {
        if (m_noOfLines != 0) 
        {
            index %= m_noOfLines; //to make sure index is within the range of lines
        
        }
        
        return m_textLines[index];
    }
    TextFile::operator bool() const 
    {
        return (m_noOfLines > 0); 
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
    {
        text.view(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text)
    {
        text.getFile(istr);
        return istr;
    }

    TextFile::~TextFile()
    {
        for (unsigned i = 0; i < m_noOfLines; i++)
        {
            delete[] m_textLines[i].m_value;
            m_textLines[i].m_value = nullptr;
        }
        delete[] m_textLines;
        m_textLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }



}