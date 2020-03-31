#include "QueueJugador.h"
#include "Jugador.h"
#include "NodeJugador.h"
QueueJugador::QueueJugador()
{
    this->size = 0;
    this->primero =0;
    this->ultimo = 0;
}


void QueueJugador::push(Jugador *jugador){
    NodeJugador *nuevo = new NodeJugador(jugador);
    if(primero==NULL){
        primero = nuevo;
        primero->siguiente =NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente =nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }
    size++;
}

void QueueJugador::desplegarCola(){
    NodeJugador *aux = primero;
    if(primero!=NULL){
        while(aux!=NULL){
            cout<< aux->jugador->getNombreJugador();
            aux = aux->siguiente;
        }
    }else{
        cout<<"Cola se encuentra vacia"<<endl;
    }
    delete aux;
}

void QueueJugador::pop(){
    NodeJugador *aux = primero;
    if(getSize()==1){
        ultimo = NULL;
        primero = NULL;
    }else{
        primero = primero->siguiente;
    }
    delete aux;
}

Jugador* QueueJugador::devolverUltimo(){
    if(primero!=nullptr){
        return primero->jugador;
    }return nullptr;
}

int QueueJugador::getSize(){
    return this->size;
}

bool QueueJugador::exists(Jugador* jugador){
    NodeJugador * aux = primero;
    if(aux!=nullptr){
        while(aux!=nullptr){
            if(aux->jugador == jugador){
                return true;
            }
            aux = aux->siguiente;
        }
    }else {
        return false;
    }
    return false;
}
