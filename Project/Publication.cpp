/*
Final Project Milestone 5.6
Module: Publication
Filename: Publication.cpp
Version 7.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

namespace sdds {

	void Publication::setEmpty()
	{
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}
	//default constructor
	Publication::Publication()
	{
		setEmpty();
	}

	//destructor
	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	//copy constructor
	Publication::Publication(const Publication& src)
	{
		*this = src;
	}

	//copy assignment operator
	Publication& Publication::operator=(const Publication& publication)
	{

		if (this != &publication)
		{
			set(publication.m_membership);
			setRef(publication.m_libRef);
			strcpy(m_shelfId, publication.m_shelfId);
			m_date = publication.m_date;

			delete[] m_title;

			//allocate memory for the new title
			if (publication.m_title)
			{
				m_title = new char[strlen(publication.m_title) + 1];
				strcpy(m_title, publication.m_title);
			}
			else
			{
				m_title = nullptr;
			}
		}
		return *this;
	}


	//set the membership
	void Publication::set(int member_id)
	{
		m_membership = member_id;
	}

	//to set the library reference
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	//to reset the date attribute
	void Publication::resetDate()
	{
		m_date = Date();
	}

	//to return the type of the object ('P' for Publication)
	char Publication::type() const
	{
		return 'P';
	}

	//to check if the publication is on loan (membership is non-zero)
	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}

	//to get the checkout date
	Date Publication::checkoutDate() const
	{
		return m_date;
	}


	//conversion operator overload to return the title attribute as a const char*
	Publication::operator const char* () const
	{
		return m_title;
	}

	//to get the library reference
	int Publication::getRef() const
	{
		return m_libRef;
	}

	//operator overload to check if the title matches a given string
	bool Publication::operator==(const char* title) const
	{
		bool result = false;
		if (m_title && title)
		{

			result = strstr(m_title, title) != nullptr;

			return result;
		}
		return result;
	}

	bool Publication::conIO(std::ios& io) const
	{
		return (&io == &std::cout || &io == &std::cin);
	}

	//conversion operator overload to check if the object is in a valid state
	Publication::operator bool() const
	{

		return m_title && m_shelfId[0];
	}

	//to read from an istream object
	std::istream& Publication::read(std::istream& is)
	{
		// Temp variables
		char tempTitle[SDDS_LIBRARY_CAPACITY + 1]{};
		char tempShelf[SDDS_SHELF_ID_LEN + 1]{};
		int tempLibRef = -1;
		int tempMembership = 0;
		Date tempDate;

		//clear the memory if it is allocated and set it to empty
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		setEmpty();


		if (conIO(is))
		{
			std::cout << "Shelf No: ";
			is.getline(tempShelf, SDDS_SHELF_ID_LEN + 1);

			std::cout << "Title: ";
			is.getline(tempTitle, SDDS_LIBRARY_CAPACITY + 1);

			std::cout << "Date: ";
			is >> tempDate;

			//check if shelfId has the correct length
			if (strlen(tempShelf) != SDDS_SHELF_ID_LEN)
			{
				is.setstate(std::ios::failbit);
			}
		}

		else
		{
			is >> tempLibRef;
			is.ignore();
			is.getline(tempShelf, SDDS_SHELF_ID_LEN + 1, '\t');
			is.getline(tempTitle, SDDS_LIBRARY_CAPACITY + 1, '\t');
			is >> tempMembership;
			is.ignore();
			is >> tempDate;
		}
		//check if date is valid
		if (!tempDate)
		{
			is.setstate(std::ios::failbit);
		}

		//if everything is valid copy the temporary data to the object
		if (is)
		{
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
			strcpy(m_shelfId, tempShelf);
			m_membership = tempMembership;
			m_date = tempDate;
			m_libRef = tempLibRef;
		}


		return is;
	}

	//to write to an ostream object
	std::ostream& Publication::write(std::ostream& os) const
	{
		//new title variable to fit in TITLE_WIDTH
		string n_title = m_title;
		n_title = n_title.substr(0, SDDS_TITLE_WIDTH);


		if (!conIO(os))
		{
			os << type(); 
			os << "\t" << m_libRef << "\t";
			os << m_shelfId << "\t" << m_title << "\t";
			os << m_membership;
			os << "\t" << m_date;
		}
		else
		{
			os << "| " << m_shelfId << " | ";
			os << std::setw(30);
			os << std::left;
			os << std::setfill('.');
			//the new title variable
			os << n_title << " | ";
			(m_membership != 0) ? os << m_membership : os << " N/A ";
			os << " | " << m_date << " |";
		}

		return os;

	}




}
