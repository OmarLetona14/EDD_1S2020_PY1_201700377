#ifndef COLAFICHA_H
#define COLAFICHA_H
#include "Ficha.h"

class ColaFicha
{
    public:
        ColaFicha();
        void push(Ficha);
        NodeFicha *primero;
        NodeFicha *ultimo;

    protected:

    private:
};

#endif // COLAFICHA_H
