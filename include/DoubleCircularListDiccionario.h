#ifndef DOUBLECIRCULARLISTDICCIONARIO_H
#define DOUBLECIRCULARLISTDICCIONARIO_H
#include "NodeDiccionario.h"
#include <iostream>
using namespace std;

class DoubleCircularListDiccionario
{
    public:
        DoubleCircularListDiccionario();
        void insertarNodo(std::string);
        void desplegarLista();
        NodeDiccionario* ultimo;
        NodeDiccionario* primero;

    protected:

    private:
};

#endif // DOUBLECIRCULARLISTDICCIONARIO_H
