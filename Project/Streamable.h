/*
Final Project Milestone 5.6
Module: Streamable
Filename: Streamable.h
Version 7.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

namespace sdds {

    //interface class for objects that can be inserted into or extracted from a stream
    class Streamable
    {
    public:
        //virtual destructor to ensure proper cleanup of derived classes
        virtual ~Streamable() {}

        //pure virtual function to write the object to an ostream
        //it does not modify the object and returns the ostream reference
        virtual std::ostream& write(std::ostream& os) const = 0;

        //pure virtual function to read the object from an istream
        //returns the istream reference after reading
        virtual std::istream& read(std::istream& is) = 0;

        //pure virtual function to check if the ios object is a console IO object or not
        // it does not modify the object and returns a bool value
        virtual bool conIO(std::ios& io) const = 0;

        //bool conversion operator overload
        //returns true if the object is in a valid state, otherwise false
        virtual operator bool() const = 0;
    };


    std::ostream& operator<<(std::ostream& os, const Streamable& streamable);


    std::istream& operator>>(std::istream& is, Streamable& streamable);

}

#endif // SDDS_STREAMABLE_H
