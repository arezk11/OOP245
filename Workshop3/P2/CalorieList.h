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
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_

#include "Food.h"

namespace sdds
{
	class CalorieList
	{
		
		Food* m_items;       
		int m_noOfFood;   
		int m_foodAdded; 

	   //calculate and return the totoal calories
		int totalCal() const;

		//dispaly the title
		void title() const;

		//display the footer 
		void footer() const;

		//set to empty
		void setEmpty();

		//check if the food is vaild
		bool isValid() const;

	public:
		void init(int size);

		//add food to calList
		bool add(const char* item_name, int calories, int when);

		//display the table
		void display()const;

		//deallocxcate the dynamic memory
		void deallocate();
	};
}

#endif // !SDDS_TRANSCRIPT_H