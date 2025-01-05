/*
*****************************************************************************
                        Workshop 4 - Part 1
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
#define PI 3.14159
#include <iostream>
#include <iomanip>
#include <cstring>
//#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;

namespace sdds {
    void Canister::setToDefault() 
    {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    void Canister::setName(const char* Cstr)
    {
        if (Cstr != nullptr && Cstr[0] != '\0')
        {
            delete[] m_contentName;
            m_contentName = new char[strlen(Cstr) + 1];
            strcpy(m_contentName, Cstr);
        }
        else 
        {
            m_contentName = nullptr;
        }
    }
    //check if the Canister is empty
    bool Canister::isEmpty() const 
    {
        return m_contentVolume < 0.00001;
    }

    //check if two Canisters have the same content
    bool Canister::hasSameContent(const Canister& C) const 
    {
        return strcmp(m_contentName, C.m_contentName) == 0;
    }

    Canister::Canister()
    {
        setToDefault();
    }

    Canister::Canister(const char* contentName) 
    {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char* contentName)
    {
        setToDefault();

        //check if the provided height and diameter are in the valid range
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0)
        {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0;
            setName(contentName);
        }
        else 
        {
            m_usable = false;//canister is not usable
        }
    }

    //destructor
    Canister::~Canister() 
    {
        delete[] m_contentName;
    }

    Canister& Canister::setContent(const char* contentName)
    {
        if (contentName == nullptr) 
        {
            m_usable = false;
        }
        else if (isEmpty())
        {
            setName(contentName);
        }
        else if (!hasSameContent(Canister(contentName))) 
        {
            m_usable = false;
        }
        return *this;
    }

    
    
    Canister& Canister::pour(double quantity)
    {
        if (m_usable && quantity > 0 && quantity + m_contentVolume <= capacity()) 
        {
            m_contentVolume += quantity;//pour the liquid to the canister
        }
        else 
        {
            m_usable = false;
        }
        return *this;
    }


  
    //pour from onr canister to another
    Canister& Canister::pour(Canister& C)
    {
        setContent(C.m_contentName);//set the content of 'this' canister to the other canister

        if (C.volume() <= (this->capacity() - this->volume()))
        {
            pour(C.m_contentVolume);//pour everything out from the canister
            C.m_contentVolume = 0.0;
        }
        else
        { 
            //reduce the volume of the canister by the remaining capacity of 'this' canister
            C.m_contentVolume -= (this->capacity() - this->volume()); 
            //set the volume of 'this' canister to its capacity
            this->m_contentVolume = capacity();
        }

        return *this;
    }


    double Canister::volume() const
    {
        return m_contentVolume;
    }

   
    ostream& Canister::display() const
    {
        cout.precision(1);
        cout << fixed;
        cout << setw(7) << capacity() << "cc ("<< m_height << "x" << m_diameter << ") Canister";

        if (!m_usable) 
        {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) 
        {
            cout << " of " << setw(7) << m_contentVolume << "cc   " << m_contentName;
        }

        return cout;
    }
    

    double Canister::capacity() const
    {
        //cal and return the capacity
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

 
    void Canister::clear()
    {
        //emptying the canister
        delete[] m_contentName;
        m_contentName = nullptr;  
        m_contentVolume = 0.0;
        m_usable = true; 
    }

 
}
