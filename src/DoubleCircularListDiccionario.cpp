#include "DoubleCircularListDiccionario.h"
#include <iostream>
#include "NodeDiccionario.h"
using namespace std;

DoubleCircularListDiccionario::DoubleCircularListDiccionario()
{
    this->ultimo = NULL;
    this->primero = NULL;
}
void DoubleCircularListDiccionario::insertarNodo(std::string palabra){
    NodeDiccionario* nuevo_nodo = new NodeDiccionario(palabra);
    if(primero==NULL){
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
        primero->siguiente = primero;
        primero->anterior = ultimo;
    }else{
        ultimo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = ultimo;
        nuevo_nodo->siguiente = primero;
        ultimo = nuevo_nodo;
        primero->anterior = ultimo;
    }
    cout<< "Nodo ingresador correctamente" <<endl;
}

void DoubleCircularListDiccionario::desplegarLista(){
    NodeDiccionario* aux = primero;
    if(primero!=NULL){
        do{
            aux = aux->siguiente;
            cout<< aux->word <<endl;
        }while(aux!=primero);
    }else{
        cout<<"La lista se encuentra vacia";
    }
}
