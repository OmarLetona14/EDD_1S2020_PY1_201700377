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
#include "ColaFicha.h"
#include "DoubleCircularListDiccionario.h"
#include "SimplyLinkedListCoordenada.h"
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

void MenuJuego::mostrarMenu(int dimension, DoubleCircularListDiccionario *diccionario, SimplyLinkedListCoordenada *coordenadas){
    this->_diccionario = diccionario;
    this->_coordenadas = coordenadas;
    do{
        std::vector<Matrix> matrix;
        this->dime_tablero = dimension;
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
            cola_jugadores = new QueueJugador();
            randomQueue = new GenerateRandom();
            colaFichas = randomQueue->fillQueue();
            escogerJugador();
            system("pause");
            cambioTurno(tablero);
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

void MenuJuego::llenarTablero(Matrix *&matriz, int d){
    for(int x = 0;x<d;x++){
        for(int y =0; y<d; y++){
            matriz->insert(x, y, nullptr);
        }
    }

}

void MenuJuego::cambioTurno(Matrix *&matriz){
    system("TASKKILL /F /IM Microsoft.Photos.exe");
    int op,dimension_x=0,dimension_y=0;;
    do{
        system("cls");
        Jugador *jugador_turno = cola_jugadores->devolverUltimo();
        cola_jugadores->pop();
        cout<< "Turno del jugador : " + jugador_turno->getNombreJugador()<<endl;
        if(matriz!=nullptr && matriz->getNodeSize()>0){
             matriz->createImage(matriz);
        }
        std::string nombre_doc = "Fichas" + jugador_turno->getNombreJugador() + ".dot";
        jugador_turno->fichas->createDOT(nombre_doc, jugador_turno->getNombreJugador());
        do{
            ColaFicha *fichas_turno = new ColaFicha();
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
                char letra;
                cout<< "Introzca la posicion en Y: "<<endl;
                cin>>dimension_y;
                cout<< "Introduzca la posicion en X: "<<endl;
                cin>>dimension_x;
                cout<<"Introduzca la letra: "<<endl;
                cin>>letra;
                introducirLetra(matriz,dimension_x,dimension_y,jugador_turno, letra, fichas_turno);
                system("TASKKILL /F /IM Microsoft.Photos.exe");
                tablero->createImage(tablero);
                jugador_turno->getFichas()->createDOT(nombre_doc, jugador_turno->getNombreJugador());
                break;
            case 2:
                if(jugador_turno!=nullptr){
                    jugador_turno->getFichas()->createDOT(nombre_doc, jugador_turno->getNombreJugador());
                }
                break;
            case 3:
                cout<< "El punteo del jugador es: " + std::to_string(jugador_turno->getPuntaje())<<endl;
                break;
            case 4:
                tablero->createImage(tablero);
                break;
            }
        }while(op!=5);
        cola_jugadores->push(jugador_turno);
        cambioTurno(matriz);
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


void MenuJuego::introducirLetra(Matrix *&matriz, int x, int y, Jugador *&jugador, char l, ColaFicha *&cola){
    try{
        if(x<dime_tablero && y<dime_tablero){
          Ficha *nueva_ficha = jugador->getFichas()->getFicha(l);
            if(nueva_ficha!=nullptr){
                isTriple(x,y,nueva_ficha);
                isDouble(x,y,nueva_ficha);
                matriz->insert(x,y,nueva_ficha);
                cola->push(nueva_ficha);
                jugador->getFichas()->eliminarNodo(nueva_ficha);
            }else {
                cout<<"La letra que intenta introducir no se encuentra en sus letras disponibles"<<endl;
                return;
            }
        }else{
            cout<<"La coordenada que intenta introducir no es valida"<<endl;
        }

    }catch(exception e){
        cout<<"Ocurrio un error al intentar introducir la ficha"<<endl;
    }
}

void MenuJuego::isTriple(int x, int y, Ficha *&ficha){
    if(_coordenadas->isTriple(x,y)){
        ficha->setTriple(true);
    }
}

void MenuJuego::isDouble(int x, int y, Ficha *&ficha){
    if(_coordenadas->isDouble(x,y)){
        ficha->setDoble(true);
    }
}
