#include "ColaFicha.h"
#include "Ficha.h"
ColaFicha::ColaFicha()
{
    this->size = 0;
    this->primero =NULL;
    this->ultimo = NULL;
}

void ColaFicha::push(Ficha *ficha){
    NodeFicha *nuevo = new NodeFicha(ficha);
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

void ColaFicha::desplegarCola(){
    NodeFicha *aux = primero;
    if(primero!=NULL){
        while(aux!=NULL){
            cout<< aux->ficha->getLetra();
            aux = aux->siguiente;
        }
    }else{
        cout<<"Cola se encuentra vacia"<<endl;
    }
}

void ColaFicha::pop(){
    NodeFicha *aux = primero;
    if(getSize()==1){
        ultimo = NULL;
        primero = NULL;
    }else{
        primero = primero->siguiente;
    }
    cout<<"Pop realizado con exito"<<endl;
    delete aux;
}


int ColaFicha::getSize(){
    return this->size;
}
