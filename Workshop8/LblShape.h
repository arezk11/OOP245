#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

namespace sdds {
    class LblShape : public Shape
    {
        char* m_label;
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        LblShape(const LblShape& other) = delete;
        LblShape& operator=(const LblShape& other) = delete;
         virtual ~LblShape();
         void getSpecs(std::istream& is) ;
    };
}

#endif // SDDS_LBLSHAPE_H
