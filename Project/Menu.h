/*
Final Project Milestone 5.6
Module: Menu
Filename: Menu.h
Version 7.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {
    const unsigned int  MAX_MENU_ITEMS = 20;
    int getValidNum(int min, int max, const char* message = "Invalid Selection, try again: ");
    class MenuItem {

        //holds only one Cstring of characters for the content of the menu item dynamically.
        //The length of the content is unknown. 
        char* menuContent{};

        MenuItem();
        MenuItem(const char* content);
        ~MenuItem();
        void setEmpty();

        //no copying
        MenuItem(const MenuItem& mItem) = delete;

        void operator=(const MenuItem& src) = delete;

        operator bool() const;

        // return the address of the content Cstring.
        operator const char* () const;

        std::ostream& display(std::ostream& os = std::cout);

        friend class Menu;
    };

    class Menu {

        MenuItem m_menuTitle{};
        MenuItem* m_menuItems[MAX_MENU_ITEMS]{};
        unsigned int m_pointers = 0;

    public:
        Menu();
        Menu(const char* title);
        ~Menu();

        // displays the menu 
        int run();

        //2 displays the menu 
        int operator~();

        // no copying
        Menu(const Menu& M) = delete;
        void operator=(const Menu& src) = delete;

        // display the menu title
        std::ostream& displayMenuTitle(std::ostream& os);

        // display the Menu content 
        std::ostream& displayMenu(std::ostream& os = std::cout);

        // return the number of MenuItems
        operator int();

        // add a MenuItem to the Menu.
        Menu& operator<<(const char* stuff);
        //2 return the number of MenuItems
        operator unsigned int();

        operator bool();


        const char* operator[](unsigned int index) const;
    };

    std::ostream& operator<<(std::ostream& os, Menu& menu);
}

#endif