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
bool isvalid :changing from && to ||
void init :added a for loop for (int i = 0; i < noOfItems; i++)
                                        line 145

Thank You so much Sir
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include "cstring.h"
#include "Bill.h"
#include <cstring>
using namespace std;
namespace sdds {

        //sets the member variables to empty values.
        void Bill::setEmpty()
        {
            m_title[0] = '\0';
            m_items = nullptr;
            m_noOfItems = 0;
            m_itemsAdded = 0;
        }

        //checks if the bill is valid.
        bool Bill::isValid() const 
        {
            bool ok = true;
            if (!m_title || m_title[0] == '\0' || !m_items  ) // check if m_title is null or m_title is an empty string
            {
                ok = false;
            }

            for (int i = 0; m_items && i < m_noOfItems; i++)
            {
               if (!m_items[i].isValid()) // check if the item at index i is valid
               {
                   ok = false;
               }
            }
            
            return ok;
        }
        
	    
        //calculates the total tax of all items in the bill
        double Bill::totalTax() const 
        {
            double taxSum = 0.0;
            for (int i = 0; i < m_noOfItems; i++) 
            {
                taxSum += m_items[i].tax();//add tax of each item to taxSum
            }
            return taxSum;
        }
       
        //calculates the total price of all items in the bill
        double Bill::totalPrice() const 
        {
            double priceSum = 0.0;
            for (int i = 0; i < m_noOfItems; i++)
            {
                priceSum += m_items[i].price();//add the prices to priceSum
            }
            return priceSum;
        }
       

        //displays the title of the bill
        void Bill::Title() const
        {
            cout << "+--------------------------------------+" << endl;
            if (isValid())// check if the bill is valid
            {
                cout << "| ";
                cout.width(37);
                cout.fill(' ');
                cout << left << m_title << "|" << endl;
            }
            else
            {
                cout << "| Invalid Bill                         |" << endl;
            }
            cout << "+----------------------+---------+-----+" << endl;
            cout << "| Item Name            | Price   + Tax |" << endl;
            cout << "+----------------------+---------+-----+" << endl;
        }


        //displays the footer of the bill
        void Bill::footer() const
        {
          

            cout << "+----------------------+---------+-----+" << endl;

            if (isValid()) 
            {
                cout << "|                Total Tax: ";
                cout.width(10);
                cout.setf(ios::right);
                cout.precision(2);
                cout.setf(ios::fixed);
                cout << totalTax() << " |" << endl;

                cout << "|              Total Price: ";
                cout.width(10);
                cout << totalPrice() << " |" << endl;

                cout << "|          Total After Tax: ";
                cout.width(10);
                cout << totalTax() + totalPrice() << " |" << endl;
            }
            else 
            {
                cout << "| Invalid Bill                         |" << endl;
            }

            cout << "+--------------------------------------+" << endl;
        }
       
        

        //initializes the bill with a title and the number of items
        void Bill::init(const char* title, int noOfItems)
        {
            if (title && noOfItems > 0)
            {
                strncpy(m_title, title, 36);// copies 36 characters from title to m_title
                m_title[36] = '\0';

                m_items = new Item[noOfItems];// dynamically allocate an array of Item objects
                for (int i = 0; i < noOfItems; i++)//In the loop initializes the m_items array, we need to iterate up to noOfItems  which represents the total number
                                                   //of items specified during initialization not m_noOfItems which only indicates the number of items added
                {
                    m_items[i].setEmpty();
                }
                m_noOfItems = noOfItems;
                m_itemsAdded = 0;
            }
            else 
            {
                setEmpty();
            }
        }
        

        
        //adds an item to the bill
        bool Bill::add(const char* item_name, double price, bool taxed)
        {
            if (m_itemsAdded < m_noOfItems) 
            {
                m_items[m_itemsAdded].set(item_name, price, taxed);// set the item in the m_items array
                m_itemsAdded++;
                return true;
            }
            return false;
        }
        
       
        void Bill::display() const
        {
            Title();

            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].display();// displays each item
                
            
            }

            
            footer();
        }

        void Bill::deallocate()
        {
            delete[] m_items;
            m_items = nullptr;
        }
    
       
    


}