#ifndef MENUJUEGO_H
#define MENUJUEGO_H
#include "ColaFicha.h"
#include "GenerateRandom.h"
#include "MenuPrincipal.h"
#include "TreeABB.h"
#include "NodeABB.h"
#include <iostream>
using namespace std;
class MenuJuego
{
    public:
        TreeABB *arbol_jugadores;
        GenerateRandom *randomQueue;
        ColaFicha *colaFichas;
        MenuJuego();
        void mostrarMenu();
        int opcion;
        void nuevoJugador(std::string);
    protected:

    private:
};

#endif // MENUJUEGO_H
