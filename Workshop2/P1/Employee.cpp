#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include "cstring.h"
#include "Employee.h"
#include "File.h"
#include <cstring>

using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // loads a employee structue with its values from the file
    bool load(Employee& emp)
    {
        bool ok = false;
        char name[128];
        

        if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
        {
            emp.m_name = new char[strlen(name) + 1];
            strcpy(emp.m_name, name);
            ok = true;
        }
        return ok;
    }

    // allocates the dyanmic array of employees and loads all the file
    // recoreds into the array
    bool load() 
    {
        bool ok = false;
        int i = 0;
        int readComplete = 0;
        if (openFile(DATAFILE)) 
        {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            
            for (i = 0; i < noOfEmployees; i++)
            {
 
                if (load(employees[i]))
                {
                    readComplete++;
                }
            }

            if (readComplete == noOfEmployees) 
            {
               
                ok = true;
            }
            if (!ok)
            { 
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }

            closeFile();
        }
        else 
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // TODO: Declare the prototype for the display function that
    // displays a employee record on the screen:
    void display(const Employee& emp)
    {
        cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
    }

    // TODO: Declare the prototype for the display function that 
    // first sorts the employees then displays all the employees on the screen
    void display() 
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
      
        sort();
        
        for (int i = 0; i < noOfEmployees; i++) 
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // TODO: Declare the prototype for the deallocateMemory function that
   // first will deallocate all the names in the employee elements
   // then it will deallocate the employee array 
    void deallocateMemory() 
    {
        for (int i = 0; i < noOfEmployees; i++) 
        {
            delete[] employees[i].m_name;
        }
        delete[] employees;
    }

}
