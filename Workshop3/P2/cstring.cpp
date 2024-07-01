
#include "cstring.h"

namespace sdds 
{
    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src)
    {
        while (*src)
        {
            *des++ = *src++;
        }
        *des = '\0';
    }

    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        while (*src && i < len)
        {
            *des++ = *src++;
            i++;
        }
        if (i < len)
        {
            *des = '\0';
        }
    }

    // Compares two C-strings 
   // returns 0 if thare the same
   // return > 0 if s1 > s2
   // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2)
    {

        while (*s1 || *s2)
        {
            if (*s1 != *s2)
            {
                if (*s1 > *s2)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            s1++;
            s2++;
        }
        if (*s1 == *s2)
        {
            return 0;
        }
            return 0;
    }

    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0;

        while ((*s1 && *s2) && i < len)
        {
            if (*s1 != *s2)
            {
                if (*s1 > *s2)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            s1++;
            s2++;
            i++;
        }

        if (i == len)
        {
            return 0;
        }
            return 0;
    }
    
    // returns the lenght of the C-string in characters
    int strLen(const char* s)
    {
        int len = 0;
        while (*s)
        {
            len++;
            s++;
        }
        return len;
    }
    
    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2)
    {
       
       
        while (*str1)
        {
            const char* p1 = str1;
            const char* p2 = str2;

            while (*p1 == *p2)
            {
                p1++;
                p2++;
            }

            if (*p2 == '\0')
            {
                return str1;
            }

            str1++;
        }
        if (*str2 == '\0')
        {
            return str1;
        }

        return nullptr;
    }

    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src) 
    {
        
        while (*des)
        {
            des++;
        }
        
        while (*src != '\0')
        {
            *des = *src;
            des++;
            src++;
        }

        *des = '\0';
    }

}

