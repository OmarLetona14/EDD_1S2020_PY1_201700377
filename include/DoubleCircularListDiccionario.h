#ifndef DOUBLECIRCULARLISTDICCIONARIO_H
#define DOUBLECIRCULARLISTDICCIONARIO_H
#include "NodeDiccionario.h"
#include "CreateFile.h"
#include <iostream>
using namespace std;

class DoubleCircularListDiccionario
{
    public:
        int size;
        int getSize();
        DoubleCircularListDiccionario();
        void insertarNodo(std::string);
        void desplegarLista();
        NodeDiccionario* ultimo;
        NodeDiccionario* primero;
        void createDOT(std::string);
        CreateFile *creator;
        bool perteneceDiccionario(std::string);
    protected:

    private:
};

#endif // DOUBLECIRCULARLISTDICCIONARIO_H
