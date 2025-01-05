#include "cstring.h"
namespace sdds {
    void strCpy(char* des, const char* src) {
        while (*src) {
            *des++ = *src++;
        }
        *des = 0;
    }

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

    int strLen(const char* s) 
    {
        int len = 0;
        while (*s)
        {
            len++;
            s++;
        }
        return 0;
    }

  /*  const char* strStr(const char* str1, const char* str2) {
        char* test ;
        return test;
    }*/
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