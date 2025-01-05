/*
*****************************************************************************
                        Workshop 8 - Part 1
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
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

using namespace std;

namespace sdds {

    //Shape class as an abstract class
    class Shape
    {
    public:
        //pure virtual functions for drawing the shape and reading its specifications
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;

        //virtual destructor for proper polymorphic behavior
        virtual ~Shape() {}

      
    }; 
   
     std::ostream& operator<<(std::ostream& os, const Shape& shape);
     std::istream& operator>>(std::istream& is, Shape& shape);
}

#endif // SDDS_SHAPE_H
