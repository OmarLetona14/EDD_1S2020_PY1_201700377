#ifndef DOUBLELINKEDLISTFICHA_H
#define DOUBLELINKEDLISTFICHA_H
#include "Ficha.h"
#include "NodeFicha.h"
#include <iostream>
#include "CreateFile.h"
using namespace std;
class DoubleLinkedListFicha
{
    public:
        int size;
        int getSize();
        void eliminarNodo(Ficha*);
        CreateFile* creator;
        DoubleLinkedListFicha();
        NodeFicha *primero;
        NodeFicha *ultimo;
        void insertar(Ficha*);
        NodeFicha* buscarNodo(Ficha*,int);
        Ficha *getFicha(char);
        void createDOT(std::string,std::string);
    protected:

    private:
};

#endif // DOUBLELINKEDLISTFICHA_H
