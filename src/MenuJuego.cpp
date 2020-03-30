#include "MenuJuego.h"
#include <iostream>
#include "GenerateRandom.h"
#include "TreeABB.h"
#include "NodeABB.h"
#include "Jugador.h"
#include "QueueJugador.h"
#include "Matrix.h"
#include "MenuPrincipal.h"
#include "NodeMatrix.h"
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
                    llenarFichasJugador(jugador_escogido);
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
            cout<<"Creando nuevo tablero..."<<endl;
            tablero = new Matrix();
            llenarTablero(tablero, MenuPrincipal::dimension_tablero);
            cola_jugadores = new QueueJugador();
            randomQueue = new GenerateRandom();
            colaFichas = randomQueue->fillQueue();
            escogerJugador();
            system("pause");
            cambioTurno();
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

void MenuJuego::llenarTablero(Matrix *&matriz, int dimension){


}

void MenuJuego::cambioTurno(){
    int op;
    do{
        system("cls");
        Jugador *jugador_turno = cola_jugadores->devolverUltimo();
        cola_jugadores->pop();
        cout<< "Turno del jugador : " + jugador_turno->getNombreJugador()<<endl;
        system("TASKKILL /F /IM Microsoft.Photos.exe");
        do{
            cout<< "Elija la opcion que desea realizar: "<<endl;
            cout<< "1. Introducir nueva letra"<<endl;
            cout<< "2. Mostrar fichas disponibles"<<endl;
            cout<< "3. Mostrar punteo"<<endl;
            cout<< "4. Imprimir tablero"<<endl;
            cout<< "5. Terminar turno"<<endl;
            cout<< "6. Salir del juego"<<endl;
            cin>>op;
            switch(op){
            case 1:
                int x=0,y=0;
                char letra;
                cout<< "Introzca la posicion en Y: "<<endl;
                cin>>y;
                cout<< "Introduzca la posicion en X: "<<endl;
                cin>>x;
                cout<<"Introduzca la letra: "<<endl;
                cin>>letra;
                break;
            case 2:
                break;
            }
        }while(op!=5);
        cola_jugadores->push(jugador_turno);
        cambioTurno();
    }while(op!=6);

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
