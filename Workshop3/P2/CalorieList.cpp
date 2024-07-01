/*
*****************************************************************************
						Workshop 3 - Part 2
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
#include <iostream>
#include "CalorieList.h"
using namespace std;
namespace sdds
{
	// seting the object to a empty state
	void CalorieList::setEmpty()
	{
		m_items = nullptr;

	}

	// check if the foods are valid
	bool CalorieList::isValid() const
	{
		bool ok = true;
		if (m_items == nullptr)
		{
			ok = false;
			return ok;
		}

		for (int i = 0; i < m_noOfFood; i++)
		{
			if (!m_items[i].isValid())
			{
				ok = false;
				return ok;
			}
		}

		return ok;
	}

	//cal and return the total calories
	int CalorieList::totalCal() const
	{
		int totCalories = 0;

		for (int i = 0; i < m_noOfFood; i++)
		{
			
			if (m_items[i].isValid())
			{
				totCalories += m_items[i].CalorieNum();
			}
		}

		return totCalories;
	}

	void CalorieList::title() const
	{

		cout << "+----------------------------------------------------+" << endl;

		
		if (isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}

		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}

		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer() const
	{

		cout << "+--------------------------------+------+------------+" << endl;

		if (isValid())
		{
			cout.setf(ios::right);
			cout << "|    Total Calories for today:  ";
			cout.width(7);
			cout << totalCal() << " | ";
			cout.width(12);
			cout << " |" << endl;
			cout.unsetf(ios::right);
		}
		
		else
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}

		cout << "+----------------------------------------------------+" << endl;
	}

	

	void CalorieList::init(int size)
	{
		
		if (size > 0)
		{
			m_noOfFood = size;
			m_foodAdded = 0;
          
		   // allocating dynamic memory
		   m_items = new Food[m_noOfFood];

			
			for (int i = 0; i < m_noOfFood; i++)// initialize each food item in the array.
			{
				m_items[i].setEmpty();
			}
		}
		else
		{
			setEmpty();
		}
	}


	bool CalorieList::add(const char* item_name, int calories, int when)
	{
		bool ok = false;
		if (m_foodAdded < m_noOfFood)
		{
			m_items[m_foodAdded].set(item_name, calories, when);// set the items in the m_items array
			m_foodAdded++;

			ok = true;
			return ok;
		}

		return ok;
	}

	
	void CalorieList::display()const
	{
		title();

		for (int i = 0; i < m_noOfFood; i++)
		{

			m_items[i].display();
		
		}

		footer();
	}

	void CalorieList::deallocate()
	{

		delete[] m_items;
		m_items = nullptr;
	}
}