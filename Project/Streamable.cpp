/*
Final Project Milestone 5.6
Module: Streamable
Filename: Streamable.cpp
Version 7.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Streamable.h"

namespace sdds {


    std::ostream& operator<<(std::ostream& os, const Streamable& streamable)
    {
        //check if the Streamable object is in a valid state before writing to the stream
        if (streamable)
        {
            //call the write method of the Streamable object to write its contents to the ostream
            streamable.write(os);
        }
        return os;
    }


    std::istream& operator>>(std::istream& is, Streamable& streamable)
    {
        //call the read method of the Streamable object to read its contents from the istream
        streamable.read(is);
        return is;
    }

}
