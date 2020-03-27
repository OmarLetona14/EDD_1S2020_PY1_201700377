#include "MenuJuego.h"
#include <iostream>
#include "GenerateRandom.h"
#include "TreeABB.h"
#include "NodeABB.h"
#include "Jugador.h"
using namespace std;

MenuJuego::MenuJuego()
{
    this->jugadores = new TreeABB();
    this->colaFichas = new ColaFicha();
}

void MenuJuego::mostrarMenu(){
    do{
        cout<<" BIENVENIDO AL JUEGO " <<endl;
        cout<<" 1. Nuevo Juego " <<endl;
        cout<<" 2. Mostrar mayores puntajes" <<endl;
        cout<<" 3. Introducir nuevo jugador" <<endl;
        cout<<" 4. Regresar al menu principal" <<endl;
        cin>>opcion;
        switch(opcion){
        case 1:
            randomQueue = new GenerateRandom();
            colaFichas = randomQueue->fillQueue();
            colaFichas->desplegarCola();
            colaFichas->generateDOT("fichas.dot");
            break;
        case 2:
            break;
        case 3:
            insertarJugador();
            break;
        case 4:
            break;
        }
        system("cls");
    }while(opcion!=4);


}

void MenuJuego::insertarJugador(){
    try{
        root= nullptr;
        std::string nombre ="";
        cout<<"Inserte el nombre del juego "<<endl;
        cin>>nombre;
        int primera_letra = (int)nombre[0];
        cout<<std::to_string(primera_letra);
        Jugador *jugador = new Jugador(primera_letra,nombre);
        jugadores->insert(root, jugador);
        delete jugador;
    }catch(exception e){
        cout<<"Ocurrio un error al intentar ingresar el jugador"<<endl;
    }

}

TreeABB* MenuJuego::getJugadores(){
    return this->jugadores;
}

ColaFicha* MenuJuego::getColaFichas(){
    return this->colaFichas;
}

NodeABB* MenuJuego::getRoot(){
    return this->root;
}
