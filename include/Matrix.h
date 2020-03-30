#ifndef MATRIX_H
#define MATRIX_H

#include "LateralList.h"
#include "HeaderList.h"
#include <string>
#include "Ficha.h"
#include "CreateFile.h"
#include <iostream>
using namespace std;
class Matrix {
public:
    CreateFile *creator;
    HeaderList header;
    LateralList lateral;
    Matrix();
    void insert(int, int, Ficha*);
    int MaximunHeader();
    int MaximunLateral();
    Ficha* ExistFicha(int, int);
    void createImage(Matrix*, std::string);
};

#endif /* MATRIX_H */

