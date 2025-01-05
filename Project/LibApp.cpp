/*
Final Project Milestone 5.6
Module: LibApp
Filename: LibApp.cpp
Version 6.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {

	LibApp::LibApp(const char* filename) : m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_publicationType("Choose the type of publication:")
	{
		//setting the filename attribute to the incoming argument
		if (filename)
		{
			strcpy(m_filename, filename);
		}

		m_changed = false;

		//setting the NOLP to 0
		m_NOLP = 0;

		//populating main menu items using the operator overload in the Menu class
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		///populating exit menu items using the operator overload in the Menu class
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		//populating publication type menu items using operator overload in menu class
		m_publicationType << "Book";
		m_publicationType << "Publication";

		load();
	}
	LibApp::~LibApp()
	{
		for (int i = 0; i < m_NOLP; i++)
		{
			delete m_PPA[i];
		}
	}

	//initialize it with the message argument
	bool LibApp::confirm(const char* message)
	{
		Menu confirmMenu(message);
		confirmMenu << "Yes";

		int input = confirmMenu.run();

		return (input == 1);
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
		ifstream inputfile(m_filename);

		char type;
		int i;

		//iterating over the file
		for (i = 0; inputfile && i < SDDS_LIBRARY_CAPACITY; i++)
		{
			//reading the first character to determine the type of publication
			inputfile >> type;


			inputfile.ignore();
		

			if (inputfile) {
				if (type == 'P')
				{
					m_PPA[i] = new Publication;
				}
				else if (type == 'B') 
				{

					m_PPA[i] = new Book;
				}

				//extract the object from the file stream
				inputfile >> *m_PPA[i];
				m_NOLP++;

				//set the LLRN to the reference number of the last publication read
				m_LLRN = m_PPA[i]->getRef();

			}
		}
	};




	void LibApp::save() {
	   cout << "Saving Data" << endl;

		ofstream outputFile(m_filename);
		int i;

		for (i = 0; i < m_NOLP; i++) 
		{
			if (m_PPA[i]->getRef() != 0)
			{
				outputFile << *m_PPA[i] <<endl;
			}
		}

		outputFile.close();
	}

	
	int LibApp::search(int s) 
	{

		char title[256],t_char;
		int s_typ = 0, i;
		int libRef = 0;
		//a selector to hold the found matches
		PublicationSelector p_selector("Select one of the following found matches:", 15);

		//get the publication selected type
		s_typ = m_publicationType.run();
		if (s_typ == 1) 
		{
			t_char = 'B';
		}
		else if (s_typ == 2) 
		{
			t_char = 'P';
		}

		//get the title for searching the PPA
		cin.ignore(1000, '\n');
		cout << "Publication Title: ";
		cin.getline(title, 256);

		//search for matches based on the search type
		
		//search types: s = 1 (all publications), s = 2 (on loan publications), s = 3 (available publications (not on loan) )
		if (s == 1) 
		{
			//loop through all publications
			for (i = 0; i < m_NOLP; i++) 
			{
				// Check if the publication matches the given title, type, and has a valid library reference
				if (m_PPA[i]->operator==(title) && t_char == m_PPA[i]->type() && m_PPA[i]->getRef() != 0) 
				{
					//put the matched publication into the publicationSelector
					p_selector << m_PPA[i];
				}
			}
		}
		else if (s == 2) 
		{
			//loop through all publications
			for (i = 0; i < m_NOLP; i++) 
			{
				//check if the publication matches the given title, type, is on loan, and has a valid library reference
				if (m_PPA[i]->operator==(title) && m_PPA[i]->onLoan() && t_char == m_PPA[i]->type() && m_PPA[i]->getRef() != 0)
				{
					//put the matched publication into the publicationSelector
					p_selector << m_PPA[i];
				}
			}
		}
		else if (s == 3) 
		{
			//loop through all publications
			for (i = 0; i < m_NOLP; i++) 
			{
				//check if the publication matches the given title, type, is not on loan , and has a valid library reference
				if (m_PPA[i]->operator==(title) && !m_PPA[i]->onLoan() && t_char == m_PPA[i]->type() && m_PPA[i]->getRef() != 0)
				{
					//put the matched publication into the publicationSelector
					p_selector << m_PPA[i];
				}
			}
		}

		//if matches are found in the selector
		if (p_selector) 
		{
			//sort them
			p_selector.sort();
			libRef = p_selector.run();

			if (libRef > 0)
			{
				cout << *getPub(libRef) << endl;
			}
			else 
			{
				cout << "Aborted!" << endl;
			}
		}
		else 
		{
			cout << "No matches found!" << endl;
		}

		return libRef;
	}

	void LibApp::returnPub()
	{
		bool fail = false;
		cout << "Return publication to the library" << endl;

		//search publicaion on loan
		int libRef = search(2);
		if (!(libRef > 0))
		{
			fail = true;
		}
		

		if (!fail)
		{
			bool sure = confirm("Return Publication?");
			if (sure) 
			{
				int loanedDays = Date() - getPub(libRef)->checkoutDate();

				//a 50 cents per day penalty will be calculated for the number of days exceeded
				if (loanedDays > SDDS_MAX_LOAN_DAYS)
				{
					double penalty = (loanedDays - SDDS_MAX_LOAN_DAYS) * 0.5;

					cout << fixed << setprecision(2);
					cout << "Please pay $" << penalty << " penalty for being " << (loanedDays - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
				}

				//set the membership number of the publication to 0 (zero)
				getPub(libRef)->set(0);

				//set the "changed" flag to true
				m_changed = true;
			}

			cout << "Publication returned" << endl;
		}
		cout << endl;
	}	
        void LibApp::newPublication() 
	{

		bool fail = false;

		//checking if the library is at its maximum capacity
		if (m_NOLP == SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!" << endl;
			fail = true;
		}

		if (!fail)
		{
			cout << "Adding new publication to the library" << endl;

			//get the pub type from the user
			int p_type = m_publicationType.run();

			cin.ignore(1000, '\n');

			//in a publication pointer, instantiate a dynamic "Publication" or "Book" based on the user's choice.
			Publication* userChoice = nullptr;

			if (p_type == 0)
			{
				cout << "Aborted!" << endl;
				fail = true;
			}

			else if (p_type == 1)
			{
				userChoice = new Book;
				cin >> *userChoice;
			}

			else if (p_type == 2) 
			{
				userChoice = new Publication;
				cin >> *userChoice;
			}

			if (cin.fail())
			{
				cin.ignore(1000, '\n');
				cin.clear();
				cout << "Aborted!" << endl;
				exit(0);
			}
			else 
			{
				if (!fail && confirm("Add this publication to the library?")) 
				{
					//check if the publication object is valid
					if (!*userChoice) 
					{
						cout << "Failed to add publication!" << endl;
						delete userChoice;
					}

					else 
					{
						m_LLRN++;
						userChoice->setRef(m_LLRN);

						//adding the publication object address to the end of the PPA
						m_PPA[m_NOLP] = userChoice;

						m_NOLP++;
						m_changed = true;

						cout << "Publication added" << endl;
					}
				}
							}
		}

		cout << endl;
	}


	

	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;

        //search all publications
		int libRef = search(1); 

		if (libRef) 
		{
			if (confirm("Remove this publication from the library?")) 
			{
				//set the library reference of the selected publication to 0 
				getPub(libRef)->setRef(0);

				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}

		cout << endl;
	}
	void LibApp::checkOutPub()
	{
		cout << "Checkout publication from the library" << endl;

		//search for a publication and get its library reference number
		int libRef = search(3); 

		int membership; 
		//check if a match is found
		if (libRef > 0) 
		{
			bool sure = confirm("Check out publication?");

			if (sure) 
			{
				cout << "Enter Membership number: ";

				//get a valid membership number from the user
				membership = getValidNum(10000, 99999, "Invalid membership number, try again: ");

				//set the membership number for the selected publication
				getPub(libRef)->set(membership);

				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
		cout << endl;
	}
	


	void LibApp::run()
	{
		int inputMenu, inputExit;
		do
		{
			inputMenu = m_mainMenu.run();
			//calling the methods based on the user choices 
			switch (inputMenu)
			{
			case 0:
				if (m_changed == true)
				{
					inputExit = m_exitMenu.run();

					switch (inputExit)
					{
					case 0:
						if (confirm("This will discard all the changes are you sure?"))
						{
							m_changed = false;
						}
						break;

					case 1:
						save();
						break;

					case 2:
						inputMenu = 1;
						break;
					}
				}
				cout << endl;
				break;
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			}
		} while (inputMenu != 0); //keep on going until user exit 

		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	Publication* LibApp::getPub(int libRef) 
	{
		Publication* result = nullptr;
		for (int i = 0; i < m_NOLP; i++)
		{
			if (m_PPA[i]->getRef() == libRef) 
			{
				result = m_PPA[i];
			}
		}

		return result;
	}

}