#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    bool read(char* name)
    {
        if (fscanf(fptr, "%[^\n]\n", name) == 1)
        {
            return true;
        }
        return false;
    }
    bool read(int& employeeNumber)
    {
        if (fscanf(fptr, "%d,", &employeeNumber) == 1)
        {
            return true;
        }
        return false;
    }
    bool read(double& salary)
    {
        if (fscanf(fptr, "%lf,", &salary) == 1) 
        {
            return true;
        }
        return false;
    }
    
}