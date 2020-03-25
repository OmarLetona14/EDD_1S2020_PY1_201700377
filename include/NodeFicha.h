#ifndef NODEFICHA_H
#define NODEFICHA_H
#include "Ficha.h"

class NodeFicha
{
    public:
        NodeFicha(Ficha*);
        NodeFicha *siguiente;
        Ficha *ficha;

    protected:

    private:
};

#endif // NODEFICHA_H
