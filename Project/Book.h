/*
Final Project Milestone 5.6
Module: Book
Filename: Book.h
Version 6.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds {
    class Book : public Publication {

        //dynamic cstring to hold the author name
        char* m_author;

        //sets  the m_author to nullptr
        void setEmpty();

    public:

        //default constructor
        Book();

        //copy constructor
        Book(const Book& src);

        //copy assignment operator
        Book& operator=(const Book& src);

        //destructor
        ~Book();

        //overrides
        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);

        virtual void set(int member_id);

        operator bool() const;
    };
}

#endif // SDDS_BOOK_H
