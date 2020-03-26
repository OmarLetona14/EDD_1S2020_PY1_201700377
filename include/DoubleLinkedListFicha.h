#ifndef DOUBLELINKEDLISTFICHA_H
#define DOUBLELINKEDLISTFICHA_H
#include "Ficha.h"
#include "NodeFicha.h"
class DoubleLinkedListFicha
{
    public:
        int size;
        DoubleLinkedListFicha();
        NodeFicha *primero;
        NodeFicha *ultimo;
        void insertar(Ficha*);
        NodeFicha* buscarNodo(Ficha*,int);
    protected:

    private:
};

#endif // DOUBLELINKEDLISTFICHA_H
