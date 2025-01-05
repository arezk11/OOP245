/*
Final Project Milestone 5.6
Module: Menu
Filename: Menu.cpp
Version 7.0
Author	Ali Rezk
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace sdds {

    MenuItem::~MenuItem()
    {
        delete[] menuContent;
    }

    void MenuItem::setEmpty()
    {
        menuContent = nullptr;
    }

    MenuItem::MenuItem()
    {
        setEmpty();
    }

    MenuItem::MenuItem(const char* content)
    {
        if (!content || !content[0])
        {
            setEmpty();
        }
        else
        {
            menuContent = new char[strlen(content) + 1];
            strcpy(menuContent, content);
        }
    }

    MenuItem::operator bool() const
    {
        return (menuContent && menuContent[0]);
    };

    MenuItem::operator const char* () const
    {
        return menuContent;
    }

    //display the MenuItem on ostream
    std::ostream& MenuItem::display(std::ostream& os)
    {
        if (*this)
        {
            os << menuContent;
        }

        return os;
    }

    Menu::Menu()
    {
        m_pointers = 0;
    };

    Menu::operator int()
    {
        return m_pointers;
    }

    Menu::operator unsigned int()
    {
        return m_pointers;
    }

    Menu::operator bool()
    {
        return (m_pointers > 0);
    }

    std::ostream& operator<<(std::ostream& os, Menu& menu)
    {
        return (menu.displayMenuTitle(os));
    }

    Menu::Menu(const char* title) : m_menuTitle(title) {}

    Menu::~Menu()
    {

        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete m_menuItems[i];
        }
    }

    std::ostream& Menu::displayMenuTitle(std::ostream& os)
    {
        m_menuTitle.display();
        os << ":" << endl;
        return os;
    }

    int getValidNum(int min, int max,const char* message) {
        int selection;
        bool isValid = false;

        while (isValid == false)
        {
            std::cin >> selection;

            if (std::cin && selection >= min && selection <= max)
            {
                isValid = true;
            }
            else
            {
                cout << message;
                cin.clear();
                cin.ignore(1000, '\n');
                isValid = false;
            }
        }
        return selection;
    }

    //display the menu
    std::ostream& Menu::displayMenu(std::ostream& os)
    {
        if (m_menuTitle)
        {
            m_menuTitle.display();
            os << std::endl;
        }

        for (unsigned int i = 0; i < m_pointers; i++)
        {
            os.width(2);
            os.setf(std::ios::right);
            os.fill(' ');
            os << i + 1 << "- ";
            os.unsetf(std::ios::right);
            m_menuItems[i]->display(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";

        return os;
    }
    //displays the menu 
    int Menu::run() {
        int userSelection;
        displayMenu();
        userSelection = getValidNum(0, m_pointers);

        return userSelection;
    }

    //display the menu but in a different way
    int Menu::operator~()
    {
        return run();
    }

    //add menuItem to menu.
    Menu& Menu::operator<<(const char* stuff)
    {
        // if (m_pointers < MAX_MENU_ITEMS) 
         //{
        MenuItem* newMenuItem = new MenuItem(stuff);
        m_menuItems[m_pointers++] = newMenuItem;
        //}

        return *this;
    }

    const char* Menu::operator[](unsigned int index) const {
        index %= m_pointers;
        return m_menuItems[index]->menuContent;
    }

} // namespace sdds
