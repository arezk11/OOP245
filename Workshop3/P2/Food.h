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
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds
{
	class Food
	{

		char m_fName[31]; 
		int m_calNum;       
		int m_when; 

		
	   // Set The m_fName 
		void setName(const char* name);

	public:
		
	   //sets the food to safe empty state
		void setEmpty();

		//set the details of the food
		void set(const char* name, int calorie, int time);

		void display() const;

		// check if the foods are valid
		bool isValid() const;

		// Return m_calNum
		int CalorieNum() const;

		// Return m_when
		int when() const;
	};
}

#endif // !SDDS_TRANSCRIPT_H