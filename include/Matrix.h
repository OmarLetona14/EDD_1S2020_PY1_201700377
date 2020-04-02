#ifndef MATRIX_H
#define MATRIX_H
#include <algorithm>
#include "LateralList.h"
#include "HeaderList.h"
#include <string>
#include "Ficha.h"
#include "CreateFile.h"
#include <iostream>
using namespace std;
class Matrix {
public:
    int nodeSize;
    std::string ExistsFicha(int, int);
    CreateFile *creator;
    HeaderList header;
    LateralList lateral;
    Matrix();
    void insert(int, int, Ficha*);
    int MaximunHeader();
    int MaximunLateral();
    Ficha* getFicha(int, int);
    void createImage(Matrix*);
    int getNodeSize();
    void eliminarNodo(Ficha*&, Matrix*&);
};

#endif /* MATRIX_H */

