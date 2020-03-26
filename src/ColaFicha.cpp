#include "ColaFicha.h"
#include "Ficha.h"
#include <iostream>
#include <fstream>

using namespace std;

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

void ColaFicha::generateDOT(std::string nombre_documento){
    creator = new CreateFile();
    std::string contenido;
    ofstream fs(nombre_documento);
    NodeFicha* aux = primero;
    contenido += "digraph ColaFichas {";
    contenido += "node [ fontsize = 16 shape = record] \n";
    contenido += "\" cola \" [ \n";
    contenido += "label = \" ";
    do{
        std::string cont = "";
        cont += aux->ficha->letra + " | ";
        contenido.append(cont);
        aux = aux->siguiente;
    }while(aux!=primero);
    contenido += "\"  \n shape= \"record\"  ]; \n";
    contenido += "}";
    fs << contenido;
    fs.close();
    creator->create(nombre_documento, "ColaFichas.png");
}


int ColaFicha::getSize(){
    return this->size;
}
