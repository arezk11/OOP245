/*
*****************************************************************************
                        Workshop 3 - Part 1
Full Name  : Ali Rezk
Student ID#: 105593222
Email      : arezk1@myseneca.ca
Section    : ZRA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.

Prof.Aras helped correcting:
bool isVaild : fixed the if statment 
Thank you so much Sir
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include "cstring.h"
#include "Item.h"
#include <cstring>
using namespace std;
namespace sdds {

    //set the name of the item
    void Item::setName(const char* name) 
    {
        strncpy(m_itemName, name, 20);// Copy 20 characters from name to m_itemName
        m_itemName[20] = '\0';
    }
   
    //set the item to an empty state
    void Item::setEmpty() 
    {
        m_itemName[0] = '\0';
        m_price = 0.0;
        m_taxed = true;
    }

    //set the details of the item
    void Item::set(const char* name, double price, bool taxed) 
    {
        if (name && price >= 0)//check if the name is not null and the price is not negative
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
        else
        {
            setEmpty();
        }
    }
   

    double Item::price() const 
    {
        return m_price;
    }

    double Item::tax() const
    {
        double result = 0.0;

        if (m_taxed) //check if the item is taxed
        {
            result = (m_price * 0.13);// cal the tax amount as 13% of the item price
        }

        return result;
    }

    

    bool Item::isValid() const
    {
        bool ok = false;

        // Check if the name is not empty and the price is greater than 0
        if (m_itemName && (m_itemName[0] != '\0' && m_price >= 0))
        {
            ok = true;
        }

        return ok;
    }

    void Item::display()const {
        if (isValid()) {
            cout << "| ";
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.width(20);
            cout.fill('.');
            cout << m_itemName;
            cout.fill(' ');
            cout << " | ";
            cout.width(7);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout.unsetf(ios::left);
            cout.setf(ios::right);
            cout << m_price;
            cout << " | " << (m_taxed ? "Yes |" : "No  |") << endl;
            cout.unsetf(ios::right);
        }
        else 
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
}
