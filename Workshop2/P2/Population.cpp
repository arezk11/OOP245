#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"
//#include "cstring.h"

using namespace std;
namespace sdds 
{

    int noOfPopulation;
    Population* PCpopulations;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPopulation - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (PCpopulations[j].m_pop > PCpopulations[j + 1].m_pop) {
                    temp = PCpopulations[j];
                    PCpopulations[j] = PCpopulations[j + 1];
                    PCpopulations[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& pop) 
    {
        bool ok = false;
        char code[50];

        if (read(code) && read(pop.m_pop)) 
        {
            
            pop.m_code = new char[strlen(code) + 1];
            strcpy(pop.m_code, code);
            
            ok = true;
        }

        return ok;
    }

   

    bool load(const char filename[])
    {
            
        bool ok = false;
        int i = 0;
        int readCompleted = 0;
        
        if (openFile(DATAFILE)) {
            noOfPopulation = noOfRecords();
            PCpopulations = new Population[noOfPopulation];
            readCompleted = 0;
            for (i = 0; i < noOfPopulation; i++)
            {
                // Check if loading data for the current employee is successful and then
                //incremant readCompleted to track the number of successfully loaded employe 
                if (load(PCpopulations[i]))
                {
                    readCompleted++;

                }

            }
            // to check if all employees have successfully been readed
            if (readCompleted == noOfPopulation)
            {
                ok = true;
            }
            // if not then print the error statment 


            if (!ok)
            {


                cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
            }

            closeFile();
        }
        else 
        {
                cout << "Could not open data file: PCpopulations.csv" << endl;
        }
        
                return ok;
    }
           
        

    void display(const Population& pop) 
    {
        cout << pop.m_code << ":  " << pop.m_pop << endl;
    }

    void display() 
    {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();

        for (int i = 0; i < noOfPopulation; ++i)
        {
            cout << i + 1 << "- ";
            display(PCpopulations[i]);
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: ";
        int totalPopulation = 0;
        for (int i = 0; i < noOfPopulation; ++i) {
            totalPopulation += PCpopulations[i].m_pop;
        }
        cout << totalPopulation << endl;
        
    }
    void deallocateMemory() 
    {
        for (int i = 0; i < noOfPopulation; ++i) 
        {
            delete[] PCpopulations[i].m_code;
            PCpopulations[i].m_code = nullptr;
        }

        delete[] PCpopulations;
        PCpopulations = nullptr;
    }
}



