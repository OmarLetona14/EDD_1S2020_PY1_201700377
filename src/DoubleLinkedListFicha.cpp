#include "DoubleLinkedListFicha.h"
#include "NodeFicha.h"
#include "Ficha.h"
DoubleLinkedListFicha::DoubleLinkedListFicha()
{
    this->size = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void DoubleLinkedListFicha::insertar(Ficha* ficha){
    NodeFicha *nuevo = new NodeFicha(ficha);
    if(primero==NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->anterior = NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente =  nuevo;
        nuevo->siguiente = NULL;
        nuevo->anterior = ultimo;
        ultimo =nuevo;
    }
}

NodeFicha* DoubleLinkedListFicha::buscarNodo(Ficha *ficha, int posicion){
    NodeFicha *aux = primero;
    int contador;
    if(aux!=NULL){
       while(aux!=NULL){
            if(aux->ficha == ficha && contador==posicion){
                return aux;
            }else{
            contador++;
            aux = aux->siguiente;
            }
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return NULL;
}
