#ifndef COLAFICHA_H
#define COLAFICHA_H
#include "Ficha.h"
#include "NodeFicha.h"
#include "CreateFile.h"
#include <iostream>
using namespace std;
class ColaFicha
{
    public:
        Ficha* devolverUltima();
        CreateFile* creator;
        int size;
        ColaFicha();
        void push(Ficha*);
        void pop();
        void desplegarCola();
        void generateDOT(std::string);
        NodeFicha *primero;
        NodeFicha *ultimo;
        int getSize();
    protected:

    private:
};

#endif // COLAFICHA_H
