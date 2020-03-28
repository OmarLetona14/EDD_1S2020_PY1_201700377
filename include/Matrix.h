#ifndef MATRIX_H
#define MATRIX_H

#include "LateralList.h"
#include "HeaderList.h"
#include <string>
#include "Ficha.h"

class Matrix {
public:
    HeaderList header;
    LateralList lateral;
    Matrix();
    void insert(int, int, Ficha*);
    int MaximunHeader();
    int MaximunLateral();
    Ficha* ExistFicha(int, int);

};

#endif /* MATRIX_H */

