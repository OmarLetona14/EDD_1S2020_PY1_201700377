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
    this->palabras_matrix = new DoubleCircularListDiccionario();
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
    this->comprobadas = new DoubleCircularListDiccionario();
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
            if(jugadores!=nullptr && jugadores->getSize()>1){
                cout<<"Creando nuevo tablero..."<<endl;
                tablero = new Matrix();
                this->comprobadas = new DoubleCircularListDiccionario();
                cola_jugadores = new QueueJugador();
                randomQueue = new GenerateRandom();
                colaFichas = randomQueue->fillQueue();
                escogerJugador();
                system("pause");
                cambioTurno(tablero);
            }else {
                cout<<"Debe ingresar al menos dos jugadores para poder jugar! "<<endl;
            }
            break;
        case 2:
            if(jugadores!=nullptr && jugadores->getSize()>0){
                obtenerMejores();
            }
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

void MenuJuego::obtenerMejores(){
    system("cls");
    cout<< "Mejores puntajes del juego "<<endl;
    jugadores->obtainBest(raiz);
    NodeScore *aux = jugadores->getMejores()->primero;
    while(aux!=nullptr){
        if(aux->score!=nullptr){
            cout<< "Jugador: " + aux->score->getNombreJugador() + " Puntaje: "+
            std::to_string(aux->score->getPuntaje()) <<endl;
        }
        aux = aux->siguiente;
    }
    jugadores->getMejores()->createDOT("");
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

    int op,dimension_x=0,dimension_y=0;

        NodeDiccionario *auxDiccionario;
        this->fichas_introducidas = new ColaFicha();
        system("TASKKILL /F /IM Microsoft.Photos.exe");
        system("cls");
        Jugador *jugador_turno = cola_jugadores->devolverUltimo();
        cola_jugadores->pop();
        cout<< "Turno del jugador : " + jugador_turno->getNombreJugador()<<endl;
        cout<< "Puntuacion: " + std::to_string(jugador_turno->getPuntaje()) <<endl;
        if(matriz!=nullptr && matriz->getNodeSize()>0){
             matriz->createImage(matriz);
        }
        std::string nombre_doc = "Fichas" + jugador_turno->getNombreJugador() + ".dot";
        jugador_turno->fichas->createDOT(nombre_doc, jugador_turno->getNombreJugador());
        do{
            cout<< "Elija la opcion que desea realizar: "<<endl;
            cout<< "1. Introducir nueva letra"<<endl;
            cout<< "2. Intercambiar fichas "<<endl;
            cout<< "3. Mostrar fichas disponibles"<<endl;
            cout<< "4. Mostrar punteo"<<endl;
            cout<< "5. Imprimir tablero"<<endl;
            cout<< "6. Terminar turno"<<endl;
            cout<< "7. Salir del juego"<<endl;
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
                introducirLetra(matriz,dimension_x,dimension_y,jugador_turno, letra);
                system("TASKKILL /F /IM Microsoft.Photos.exe");
                tablero->createImage(tablero);
                jugador_turno->getFichas()->createDOT(nombre_doc, jugador_turno->getNombreJugador());
                break;
            case 2:
                menuReemplazo(jugador_turno);

                break;
            case 3:
                if(jugador_turno!=nullptr){
                    jugador_turno->getFichas()->createDOT(nombre_doc, jugador_turno->getNombreJugador());
                }
                break;
            case 4:
                cout<< "El punteo del jugador es: " + std::to_string(jugador_turno->getPuntaje())<<endl;
                break;
            case 5:
                tablero->createImage(tablero);
                break;
            case 6:
                palabras_matrix = realizarRecorrido(matriz);
                if(palabras_matrix->getSize()>0 && !comprobadas->exists(palabras_matrix->ultimo->word)){
                    cout<<"Se reconocio la palabra: " + palabras_matrix->primero->word<<endl;
                    int puntuacion = 0;
                    NodeFicha *aux = fichas_introducidas->primero;
                    while(aux!=nullptr){
                        if(aux->ficha !=nullptr){
                            if(aux->ficha->getDoble() ==true){
                                 puntuacion+=aux->ficha->getPuntaje()*2;
                            }else if(aux->ficha->getTriple() ==true){
                                 puntuacion+=aux->ficha->getPuntaje()*3;
                            }else{
                                 puntuacion+=aux->ficha->getPuntaje();
                            }
                        }
                        aux = aux->siguiente;
                    }
                    jugador_turno->setPuntaje(puntuacion);
                    cout<< "Puntuacion del jugador " + jugador_turno->getNombreJugador()
                    + ": " + std::to_string(jugador_turno->getPuntaje())<<endl;
                    int llenado = 7- jugador_turno->getFichas()->getSize();
                    for(int i = 0; i<llenado;i++){
                        jugador_turno->getFichas()->insertar(colaFichas->devolverUltima());
                        colaFichas->pop();
                    }
                    if(palabras_matrix->primero !=nullptr){
                        auxDiccionario = palabras_matrix->primero;
                        do{
                            if(!comprobadas->exists(auxDiccionario->word)){
                                comprobadas->insertarNodo(auxDiccionario->word);
                            }
                            auxDiccionario = auxDiccionario->siguiente;
                        }while(auxDiccionario!=palabras_matrix->primero);
                    }
                }else{
                    cout<< "No se encontro ninguna palabra valida! "<<endl;
                    NodeFicha *auxFicha = fichas_introducidas->primero;
                    while(auxFicha!=nullptr){
                         jugador_turno->getFichas()->insertar(auxFicha->ficha);
                         auxFicha = auxFicha->siguiente;
                    }
                }
                system("pause");
                break;
                case 7:
                system("TASKKILL /F /IM Microsoft.Photos.exe");
                jugador_turno->getPuntajes()->insertar(new Score(jugador_turno->getNombreJugador(), jugador_turno->getPuntaje()));
                cola_jugadores->devolverUltimo()->getPuntajes()->insertar(new Score(cola_jugadores->devolverUltimo()->getNombreJugador(),
                                                                                    cola_jugadores->devolverUltimo()->getPuntaje()));
                cout<<"* * * * * *     JUEGO TERMINADO! * * * * *     "<<endl;
                if(jugador_turno->getPuntaje()>cola_jugadores->devolverUltimo()->getPuntaje()){
                    cout<< "El ganador es: " + jugador_turno->getNombreJugador()<<endl;
                }else if(jugador_turno->getPuntaje()<cola_jugadores->devolverUltimo()->getPuntaje()){
                    cout<<"El ganador es: " + cola_jugadores->devolverUltimo()->getNombreJugador()<<endl;
                }else{
                    cout<< "Ha sido un empate! "<<endl;
                }
                system("pause");
                break;
                break;
            }
        }while(op!=6 && op!=7);
        if(op!=7){
            cola_jugadores->push(jugador_turno);
            cambioTurno(matriz);
        }
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


void MenuJuego::introducirLetra(Matrix *&matriz, int x, int y, Jugador *&jugador, char l){
    try{
        if(x<dime_tablero && y<dime_tablero){
          Ficha *nueva_ficha = jugador->getFichas()->getFicha(l);
            if(nueva_ficha!=nullptr){
                isTriple(x,y,nueva_ficha);
                isDouble(x,y,nueva_ficha);
                matriz->insert(x,y,nueva_ficha);
                fichas_introducidas->push(nueva_ficha);
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

void MenuJuego::isDouble(int  x, int y, Ficha *&ficha){
    if(_coordenadas->isDouble(x,y)){
        ficha->setDoble(true);
    }
}


void MenuJuego::reemplazarTodas(Jugador *&jugador){
    try{
        jugador->setFichas(new DoubleLinkedListFicha());
        for(int i=0; i<7;i++){
            jugador->getFichas()->insertar(colaFichas->devolverUltima());
            colaFichas->pop();
        }
    }catch(exception e){
        cout<<"Ocurrio un error al intentar reemplazar las fichas"<<endl;
    }

}

void MenuJuego::reemplazarUna(Jugador*& j, Ficha* f){
    try{
        j->getFichas()->insertar(colaFichas->devolverUltima());
        j->getFichas()->eliminarNodo(f);
        colaFichas->pop();
        colaFichas->push(f);
    }catch(exception e){
        cout<<"Ocurrio un problema al intentar reemplazar la ficha "<<endl;
    }
}

void MenuJuego::menuReemplazo(Jugador*& jugador_turno){
    int op;
    do{
    char le;
    cout<< "Elija una opcion: "<<endl;
                cout<< "1. Reemplazar todas"<<endl;
                cout<< "2. Reemplazar una"<<endl;
                cout<< "3. Salir"<<endl;
                cin>>op;
                switch(op){
                case 1:
                    reemplazarTodas(jugador_turno);
                    break;
                case 2:
                    cout<<"Escriba la palabra que desea reemplazar"<<endl;
                    cin>> le;
                    Ficha *ficha_reem = jugador_turno->getFichas()->getFicha(le);
                    if(ficha_reem!=nullptr){
                        reemplazarUna(jugador_turno, ficha_reem);
                    }else{
                        cout<<"La ficha que intenta reemplazar no se encuentra dentro de sus fichas disponibles"<<endl;
                    }

                    break;
                }
                system("pause");
                system("cls");
                system("TASKKILL /F /IM Microsoft.Photos.exe");
                jugador_turno->getFichas()->createDOT("Fichas" + jugador_turno->getNombreJugador(), jugador_turno->getNombreJugador());
                if(tablero->getNodeSize()>0){
                    tablero->createImage(tablero);
                }

    }while(op!=3);
}



DoubleCircularListDiccionario* MenuJuego::realizarRecorrido(Matrix* t_b){
    DoubleCircularListDiccionario *palabras_dicc = new DoubleCircularListDiccionario();
    //Recorrido de las columnas
    NodeHeader *auxHeader = t_b->header.first;
    while(auxHeader!=nullptr){
        NodeMatrix *auxMatrix = auxHeader->column.first;
        std::string palabra;
        while(auxMatrix!=nullptr){
            if(auxMatrix->getFicha()!=nullptr){
                palabra+= auxMatrix->getFicha()->getLetra();
                NodeDiccionario *auxDiccionario = _diccionario->primero;
                do{
                        if(_diccionario->subCadenaDiccionario(auxDiccionario->word, palabra)
                            && !comprobadas->perteneceDiccionario(palabra) && _diccionario->perteneceDiccionario(palabra)){
                            palabras_dicc->insertarNodo(palabra);
                        }
                    auxDiccionario = auxDiccionario->siguiente;
                }while(auxDiccionario!=_diccionario->primero);
            }
            auxMatrix = auxMatrix->getDown();
        }
        auxHeader = auxHeader->getNext();
    }
    //Recorrido por filas
    NodeLateral *auxLateral = t_b->lateral.first;
    while(auxLateral!=nullptr){
        NodeMatrix * auxMatrix = auxLateral->row.first;
        std::string palabra;
        while(auxMatrix!=nullptr){
            if(auxMatrix->getFicha()!=nullptr){
                 palabra += auxMatrix->getFicha()->getLetra();
                NodeDiccionario *auxDiccionario = _diccionario->primero;
                do{
                        if(_diccionario->subCadenaDiccionario(auxDiccionario->word, palabra)
                            && !comprobadas->perteneceDiccionario(palabra) && _diccionario->perteneceDiccionario(palabra)){
                            palabras_dicc->insertarNodo(palabra);
                        }
                    auxDiccionario = auxDiccionario->siguiente;
                }while(auxDiccionario!=_diccionario->primero);
            }
            auxMatrix=auxMatrix->getNext();
        }
        auxLateral = auxLateral->getDown();
    }
    return palabras_dicc;
}

bool MenuJuego::comprobarPalabra(DoubleCircularListDiccionario *diccionario, std::string subcadena){
    NodeDiccionario *aux = diccionario->primero;
    do{
        int n = subcadena.length();
        char char_array[n+1];
        strcpy(char_array, subcadena.c_str());

        if(strstr(aux->word.c_str(), subcadena.c_str())){

            return true;
        }
        aux = aux->siguiente;
    }while(aux!=diccionario->primero);
    return false;
}
