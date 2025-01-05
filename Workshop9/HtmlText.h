/*
*****************************************************************************
                        Workshop 9 - Part 1
Full Name  : Ali Rezk
Student ID#: 105593222
Email      : arezk1@myseneca.ca
Section    : ZRA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__

#include "Text.h"

namespace sdds {
    class HtmlText : public Text {
        char* m_title{ nullptr };

    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        //rule of three: 
        HtmlText(const HtmlText& src);
        HtmlText& operator=(const HtmlText& src);
        ~HtmlText();

        void write(std::ostream& os) const;
    };
}
#endif // !SDDS_HTMLTEXT_H__