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

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds {
    class Text {
        //Hold the name of the file dynamically
        char* m_filename{ nullptr };


        char* m_content{ nullptr };
        int getFileLength() const;
        void clear();
    protected:
        // provides read-only access to the content of the text for the derived classes of Text.
        const char& operator[](int index) const;

    public:
        Text(const char* filename = nullptr);
        void read();
        virtual void write(std::ostream& os) const;
        
        //rule of three here
        Text(const Text& src);
        Text& operator=(const Text& src);
        virtual ~Text();

    };
    // prototype of insertion overload into ostream goes here
    std::ostream& operator<< (std::ostream& os, const Text& src);
}
#endif // !SDDS_PERSON_H__