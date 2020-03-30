#ifndef GENERATERANDOM_H
#define GENERATERANDOM_H
#include "ColaFicha.h"
#include "Ficha.h"
class GenerateRandom
{
    public:
        Ficha *ficha;
        ColaFicha *cola;
        GenerateRandom();
        int generateR(int);
        int generateID(int);
        ColaFicha* fillQueue();
    protected:

    private:
};

#endif // GENERATERANDOM_H
