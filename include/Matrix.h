#ifndef MATRIX_H
#define MATRIX_H

#include "LateralList.h"
#include "HeaderList.h"
#include <string>

class Matrix {
public:
    HeaderList header;
    LateralList lateral;
    Matrix();
    void insert(int, int, std::string);
    int MaximunHeader();
    int MaximunLateral();
    std::string ExistColor(int, int);

};

#endif /* MATRIX_H */

