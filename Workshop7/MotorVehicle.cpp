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
#include "MotorVehicle.h"
#include <iostream>
#include <cstring>
using namespace std;


namespace sdds {

    MotorVehicle::MotorVehicle(const char* licensePlate, int year) : m_year(year) 
    {
        strncpy(m_lPlate, licensePlate, 8);
        m_lPlate[8] = '\0';
        strcpy(m_address, "Factory");
    }

  
    void MotorVehicle::moveTo(const char* address)
    {
        if (strcmp(m_address, address) != 0)
        {
            //print the license plate and current address and new address
            cout << "|";
            cout.width(8);
            cout << m_lPlate << "| |";

            cout.width(20);
            cout << m_address << " ---> ";

            cout.width(20);
            cout << left << address << "|" << right << endl;

            strcpy(m_address, address);
        }
    }



    std::ostream& MotorVehicle::write(std::ostream& os) const 
    {
        //write the year and license plate and current address to the output stream
        os << "| " << m_year << " | " << m_lPlate << " | " << m_address;

        return os;
    }

    std::istream& MotorVehicle::read(std::istream& in) 
    {
        cout << "Built year: ";
        in >> m_year;
        cout << "License plate: ";
        in.ignore();
        in.getline(m_lPlate, 9, '\n');
        cout << "Current location: ";
        in.getline(m_address, 64, '\n');
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
        return vehicle.write(os);
    }

    std::istream& operator>>(std::istream& is, MotorVehicle& vehicle) {
        return vehicle.read(is);
    }

}
