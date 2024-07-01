#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr = nullptr;
    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // counts the number of records in the file by scanning the file characters and then
   //incrementing a counter for each newline character scanned and then returns the total count of records.
    int noOfRecords()
    {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) 
        {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    //checks if the file pointer (fptr) is not null and if not it closes the file 
    void closeFile() 
    {
        if (fptr) 
        {
            fclose(fptr);
            fptr = nullptr;
        }

    }

    // reads a line of input from .csv file and stores it in a the char array code
    bool read(char* code) 
    {
        int result = fscanf(fptr, "%[^,],", code);
        if (result == 1)
        {
            return true;
        }
        
        return false;
    }

    // reads an int value from a .csv file and assigns it to the int reference pop
    bool read(int& pop)
    {
        int result = fscanf(fptr, "%d\n,", &pop);
        if (result == 1)
        {
            return true;
        }
       
        return false;
    }

}