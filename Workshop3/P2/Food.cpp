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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Food.h"

using namespace std;
namespace sdds
{
	//set the name of the food
	void Food::setName(const char* name)
	{
		
		strncpy(m_fName, name, 30);// Copy 30 characters from name to m_fName
		m_fName[30] = '\0';
	}

	//set the food to empty state
	void Food::setEmpty()
	{
		m_fName[0] = '\0'; 
		m_calNum = 0;
		m_when = 0;
	}

	
     //set the details of the food
	void Food::set(const char* name, int calorie, int time)
	{
		if (calorie >= 0 && name != nullptr)
		{
			setName(name);
			m_calNum = calorie;
			m_when = time;
		}
		else
		{
			setEmpty();
		}
	}

	// return calories number
	int Food::CalorieNum() const
	{
		return m_calNum;
	}

	//return the code
	int Food::when() const
	{
		return m_when;
	}

	// check if the foods are valid
	bool Food::isValid() const
	{
		bool ok = false;
	
		if ((m_calNum >= 0 && m_calNum <= 3000) && (m_fName[0] != '\0') && (m_when > 0 && m_when <= 4))
		{
			ok = true;
			return ok;
		}

		return ok;
	}

	



	void Food::display() const
	{

		if (isValid())
		{
			const char* mealTime;

			cout << "| ";
			cout.setf(ios::left);
			cout.width(30);
			cout.fill('.');
			cout << m_fName << " | ";
			cout.fill(' ');
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.width(4);
			cout << m_calNum << " | ";

			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(10);


			switch (m_when) 
			{
			case 1:
				mealTime = "Breakfast";
				break;
			case 2:
				mealTime = "Lunch";
				break;
			case 3:
				mealTime = "Dinner";
				break;
			case 4:
				mealTime = "Snack";
				break;
			default:
				mealTime = "Unknown";
			}
			cout << left << mealTime << " |" << endl;
			
		}
		else
		{
			
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" <<endl;
		}

	}

}