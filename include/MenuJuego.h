#ifndef MENUJUEGO_H
#define MENUJUEGO_H
#include "ColaFicha.h"
#include "GenerateRandom.h"
#include "MenuPrincipal.h"
#include "TreeABB.h"
#include "NodeABB.h"
#include "Jugador.h"
#include "QueueJugador.h"
#include "Matrix.h"
#include "NodeMatrix.h"
#include "SimplyLinkedListCoordenada.h"
#include "DoubleCircularListDiccionario.h"
#include "DoubleLinkedListFicha.h"
#include <iostream>
using namespace std;
class MenuJuego
{
    public:
        void obtenerMejores();
        DoubleCircularListDiccionario *comprobadas;
        DoubleCircularListDiccionario *palabras_matrix;
        int punteo_jugador;
        DoubleCircularListDiccionario *_diccionario;
        SimplyLinkedListCoordenada *_coordenadas;
        int dime_tablero;
        void introducirLetra(Matrix*&, int, int, Jugador*&,char);
        void llenarTablero(Matrix*&,int);
        Matrix *tablero;
        QueueJugador *cola_jugadores;
        NodeABB *raiz;
        ColaFicha* getColaFichas();
        GenerateRandom *randomQueue;
        ColaFicha *colaFichas;
        MenuJuego();
        void mostrarMenu(int, DoubleCircularListDiccionario*, SimplyLinkedListCoordenada* );
        int opcion;
        void nuevoJugador(std::string);
        void insertarJugador();
        TreeABB* jugadores;
        TreeABB* getJugadores();
        NodeABB* getRoot();
        void escogerJugador();
        void llenarFichasJugador(Jugador*&);
        void cambioTurno(Matrix*&);
        void isDouble(int, int, Ficha*&);
        void isTriple(int, int, Ficha*&);
        void reemplazarTodas(Jugador*&);
        void reemplazarUna(Jugador*&, Ficha*);
        void menuReemplazo(Jugador*&);
        int verificar(char*,char*);
        bool comprobarPalabra(DoubleCircularListDiccionario*, std::string);
        DoubleCircularListDiccionario *realizarRecorrido(Matrix*);
        ColaFicha *fichas_introducidas;
        void terminarTurno();
    protected:

    private:
};

#endif // MENUJUEGO_H
