#ifndef MENUJUEGO_H
#define MENUJUEGO_H
#include "ColaFicha.h"
#include "GenerateRandom.h"
#include "MenuPrincipal.h"
#include "TreeABB.h"
#include "NodeABB.h"
#include "Jugador.h"
#include "QueueJugador.h"
#include <iostream>
using namespace std;
class MenuJuego
{
    public:
        QueueJugador *cola_jugadores;
        NodeABB *raiz;
        ColaFicha* getColaFichas();
        GenerateRandom *randomQueue;
        ColaFicha *colaFichas;
        MenuJuego();
        void mostrarMenu();
        int opcion;
        void nuevoJugador(std::string);
        void insertarJugador();
        TreeABB* jugadores;
        TreeABB* getJugadores();
        NodeABB* getRoot();
        void escogerJugador();
        void llenarFichasJugador(Jugador*&);
        void cambioTurno();
    protected:

    private:
};

#endif // MENUJUEGO_H
