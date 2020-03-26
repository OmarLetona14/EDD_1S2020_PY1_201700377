#ifndef COLAFICHA_H
#define COLAFICHA_H
#include "Ficha.h"
#include "NodeFicha.h"
class ColaFicha
{
    public:
        int size;
        ColaFicha();
        void push(Ficha*);
        void pop();
        void desplegarCola();
        NodeFicha *primero;
        NodeFicha *ultimo;
        int getSize();
    protected:

    private:
};

#endif // COLAFICHA_H
