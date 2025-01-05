/*
Final Project Milestone 5.6
Module: Publication
Filename: Publication.h
Version 7.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

namespace sdds {
    class Publication : public Streamable {
    private:

        //dynamic C-string to hold the title
        char* m_title;

        //4 characters + null terminator
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

        //set the publication attributes to default
        void setEmpty();

    public:
        Publication();
        ~Publication();

        //copy constructor
        Publication(const Publication& src);

        //copy assignment operator
        Publication& operator=(const Publication& src);


        //returns the character 'P' to identify this object as a "Publication object"
        virtual char type() const;

        //returns true if the publication is checked out (membership is non-zero)
        bool onLoan() const;

        //returns the date attribute
        Date checkoutDate() const;

        //returns true if the argument title appears anywhere in the title of the publication. 
        //Otherwise, it returns false
        bool operator==(const char* title) const;

        //returns the title attribute
        operator const char* () const;

        //returns the libRef attribute.
        int getRef() const;

        // Streamable interface methods:

        //write the publication object to the output stream
        std::ostream& write(std::ostream& os) const;

        //read the publication object from the input stream
        std::istream& read(std::istream& is);

        //determine if the input/output stream is for console IO
        bool conIO(std::ios& io) const;

        //convert the publication object to a boolean value
        operator bool() const;

        //set the membership attribute
        virtual void set(int member_id);

        //set the libRef attribute
        void setRef(int value);

        //reset the date attribute to default
        void resetDate();



    };
}

#endif //SDDS_PUBLICATION_H
