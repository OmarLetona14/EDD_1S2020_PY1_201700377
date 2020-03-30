#include "MenuJuego.h"
#include <iostream>
#include "GenerateRandom.h"
#include "TreeABB.h"
#include "NodeABB.h"
#include "Jugador.h"
#include "QueueJugador.h"
using namespace std;

MenuJuego::MenuJuego()
{
    this->jugadores = new TreeABB();
    this->colaFichas = new ColaFicha();
    this->raiz = nullptr;
}

void MenuJuego::escogerJugador(){
    do{
        if(randomQueue!=nullptr){
            NodeABB *nodo_vacio = nullptr;
            int id_jugador = 1 + randomQueue->generateR(jugadores->getSize());
            Jugador *jugador_escogido = jugadores->searchPlayerByID(id_jugador, raiz, nodo_vacio)->getData();
            if(jugador_escogido!=nullptr){
                if(!cola_jugadores->exists(jugador_escogido)){
                    cout<< "Jugador escogido: "+ jugador_escogido->getNombreJugador() + "\n";
                    cola_jugadores->push(jugador_escogido);
                }
            }
            delete nodo_vacio;
        }
    }while(cola_jugadores->getSize()<=1);
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
            cola_jugadores = new QueueJugador();
            randomQueue = new GenerateRandom();
            colaFichas = randomQueue->fillQueue();
            escogerJugador();
            system("pause");
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
        std::string nombre ="";
        cout<<"Inserte el nombre del juego "<<endl;
        cin>>nombre;
        int primera_letra = tolower(nombre[0]);
        Jugador *jugador = new Jugador(jugadores->getSize() + 1,nombre, primera_letra);
        jugadores->insert(raiz, jugador);
        cout<< "Jugador insertado exitosamente"<<endl;
    }catch(exception e){
        cout<<"Ocurrio un error al intentar ingresar el jugador"<<endl;
    }

}

void MenuJuego::llenarFichasJugador(Jugador *&jugador){
    for(int i= 0; i<7;i++){
        jugador->getFichas()->insertar(colaFichas->devolverUltima());
        colaFichas->pop();
    }
}

void MenuJuego::cambioTurno(){
    system("TASKKILL /F /IM Microsoft.Photos.exe");
}

TreeABB* MenuJuego::getJugadores(){
    return this->jugadores;
}

ColaFicha* MenuJuego::getColaFichas(){
    return this->colaFichas;
}

NodeABB* MenuJuego::getRoot(){
    return this->raiz;
}
