#ifndef MENUJUEGO_H
#define MENUJUEGO_H
#include "ColaFicha.h"
#include "GenerateRandom.h"
#include "MenuPrincipal.h"
class MenuJuego
{
    public:
        GenerateRandom *randomQueue;
        ColaFicha *colaFichas;
        MenuJuego();
        void mostrarMenu();
        int opcion;
    protected:

    private:
};

#endif // MENUJUEGO_H
