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

#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"
#include <iostream>
#include <cstring>
using namespace std;


namespace sdds {

    Truck::Truck(const char* licensePlate, int year, double capacity, const char* address)
    : MotorVehicle(licensePlate, year)
    {
        //initialize the maximum capacity of the truck
        m_capacity = capacity;

        //initialize the current cargo of the truck to 0
        m_cargo = 0.0;  

        //move the truck to the given address
        moveTo(address);            
    
       
    }


  
    bool Truck::addCargo(double cargo)
    {
        bool isValid = false;

        
        if (cargo > 0 && (m_cargo != m_capacity))
        {
            //add the new cargo to the current cargo
            m_cargo += cargo;

            isValid = true;

            //if the current cargo exceeds the maximum capacity 
            if (m_cargo > m_capacity) 
            {
                m_cargo = m_capacity;//limit it to the maximum
            }
        }
        return isValid;
    }

   



    bool Truck::unloadCargo() 
    {
        bool isValid = false;
        if (m_cargo > 0.0) 
        {
            //set the current cargo to 0 to unload it
            m_cargo = 0.0;

            isValid = true;                 

            return isValid;
        }
        return isValid;

    }
   
    std::ostream& Truck::write(std::ostream& os) const 
    {
        MotorVehicle::write(os);

        os << " | " << m_cargo << "/" << m_capacity;
        return os;
    }

  


    std::istream& Truck::read(std::istream& in) 
    {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> m_capacity;
        cout << "Cargo: ";
        in >> m_cargo;
        return in;
    }
   

    std::ostream& operator<<(std::ostream& os, const Truck& truck)
    {
        return truck.write(os);
    }

    std::istream& operator>>(std::istream& is, Truck& truck) 
    {
        return truck.read(is);
    }

}
