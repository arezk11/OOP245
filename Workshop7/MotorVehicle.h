/*
*****************************************************************************
                        Workshop 7 - Part 1
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

#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <iostream>
#include <iomanip>

namespace sdds {

    class MotorVehicle {

    protected:

        //store the address of the vehicle
        char m_address[64];

        //store the year the vehicle was built
        int m_year;     

        //store the license plate number
        char m_lPlate[9];      
    public:
        //constructor to initialize the object
        MotorVehicle(const char* licensePlate, int year); 

        //to update the vehicle's address
        void moveTo(const char* address);

       //to write the vehicle's information to an output stream
        std::ostream& write(std::ostream& os) const;   

       //to read the vehicle's information from an input stream
        std::istream& read(std::istream& in);        

    };
    //to write the vehicle's information to an output stream
    std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
   //to read the vehicle's information from an input stream
    std::istream& operator>>(std::istream& is, MotorVehicle& vehicle);         
    

}

#endif // MOTORVEHICLE_H
