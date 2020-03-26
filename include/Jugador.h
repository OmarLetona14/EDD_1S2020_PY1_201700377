#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include "ColaFicha.h"
using namespace std;
class Jugador
{
    public:
        Jugador();
        std::string nombre_jugador;
        int puntaje;
        ColaFicha* fichas;

    protected:

    private:
};

#endif // JUGADOR_H
