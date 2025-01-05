/*
Final Project Milestone 5.6
Module: LibApp
Filename: LibApp.h
Version 6.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef LIBAPP_H
#define LIBAPP_H

#include <iostream>
#include "Menu.h"
#include "Lib.h"
#include "Streamable.h"
#include "Publication.h"
#include "Book.h"
namespace sdds {

    class LibApp {
        //bool to keep track of the changes made to the application data
        bool m_changed;

        //the main menu of the application
        Menu m_mainMenu;
        //the menu for handling exit options
        Menu m_exitMenu;

        char m_filename[256];

        Publication* m_PPA[SDDS_LIBRARY_CAPACITY]; // Publication pointers array
        int m_NOLP; // Number of loaded Publications
        int m_LLRN; // Last Library Reference Number

        Menu m_publicationType;
      

        //display a confirmation menu 
        bool confirm(const char* message);

        //load data
        void load();

        //save data
        void save();

        //search for a publication
        int search(int s);

        //return a publication
        void returnPub();

        //add a new publication to the library with confirmation
        void newPublication();

        // remove a publication from the library with confirmation
        void removePublication();

        //check out a publication from the library with confirmation
        void checkOutPub();

    public:
        //constructor

        LibApp(const char* fileName);

        //destructor
        ~LibApp();

        //start the main application and handle user interactions
        void run();


        Publication* getPub(int libRef);
    };

}
#endif // LIBAPP_H