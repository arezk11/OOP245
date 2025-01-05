/*
Final Project Milestone 5.6
Module: Book
Filename: Book.cpp
Version 6.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <cstring>
#include <iostream>
#include <iomanip>

namespace sdds {
    void Book::setEmpty()
    {

        m_author = nullptr;

    }

    Book::Book() : Publication()
    {
        setEmpty();
    }

    Book::~Book()
    {
        delete[] m_author;
    }

    char Book::type() const
    {
        return 'B';
    }

    Book::Book(const Book& src) : Publication(src)
    {
        if (m_author)
        {
            delete[] m_author;
            setEmpty();

        }

        m_author = new char[strlen(src.m_author) + 1];
        strcpy(m_author, src.m_author);
    }

    Book& Book::operator=(const Book& src)
    {
        Publication::operator=(src);

        if (m_author)
        {
            delete[] m_author;
            setEmpty();

        }
        if (this != &src)
        {
            Publication::operator=(src); //base class assignment operator
            delete[] m_author;

            //copy the author name from the source object
            if (src.m_author)
            {
                m_author = new char[strlen(src.m_author) + 1];
                strcpy(m_author, src.m_author);
            }
            else
            {
                setEmpty();
            }
        }


        return *this;
    }



    std::ostream& Book::write(std::ostream& os) const
    {
        //base class write method
        Publication::write(os);
        if (conIO(os))
        {
            char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
            std::strncpy(author, m_author, SDDS_AUTHOR_WIDTH);
            os << " ";
            os << std::setw(SDDS_AUTHOR_WIDTH);
            os << std::left << std::setfill(' ') << author << " |";
        }

        else
        {
            os << "\t" << m_author;
        }


        return os;
    }


    std::istream& Book::read(std::istream& is)
    {

        char t_name[SDDS_LIBRARY_CAPACITY] = { 0 };

        //read from the Publication class 
        Publication::read(is);

        //delete the memory for the author name    
        if (m_author)
        {
            setEmpty();
        }
        else if (conIO(is))
        {
            is.ignore();
            std::cout << "Author: ";
        }
        else
        {
            is.ignore(1000, '\t');
        }

        is.get(t_name, SDDS_LIBRARY_CAPACITY);

        if (is)
        {
            m_author = new char[strlen(t_name) + 1];
            strcpy(m_author, t_name);
        }

        return is;
    }




    void Book::set(int member_id)
    {
        //base class set method
        Publication::set(member_id);
        Publication::resetDate();
    }

    Book::operator bool() const
    {
        return m_author && Publication::operator bool();
    }
}


