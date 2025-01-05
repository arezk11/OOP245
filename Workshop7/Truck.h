
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
#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

namespace sdds {

    class Truck : public MotorVehicle
    {
        //store the maximum cargo capacity of the truck
        double m_capacity;

        //store the current cargo of the truck
        double m_cargo;

    public:
        //constructor to initialize the truck with the license plate, year, capacity, and address
        Truck(const char* licensePlate, int year, double capacity, const char* address);
       
        //adds cargo to the truck, returns true if successful, false if otherwise
        bool addCargo(double cargo);
        
        //to unload the cargo from the truck, returns true if successful, false if otherwise
        bool unloadCargo();
        
        //to write the truck information to the output stream
        std::ostream& write(std::ostream& os) const;
        
        //to read the truck information from the input stream
        std::istream& read(std::istream& in);
        
    };
    //to write the truck information to the output stream
    std::ostream& operator<<(std::ostream& os, const Truck& truck);
    
    //to read the truck information from the input stream
    std::istream& operator>>(std::istream& is, Truck& truck);
    
}
#endif // TRUCK_H
