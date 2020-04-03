#include "DoubleCircularListDiccionario.h"
#include <iostream>
#include "NodeDiccionario.h"
#include "CreateFile.h"
#include <fstream>
#include <string.h>
using namespace std;

DoubleCircularListDiccionario::DoubleCircularListDiccionario()
{
    this->size =0;
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
    size++;
}

int DoubleCircularListDiccionario::getSize(){
    return this->size;
}

void DoubleCircularListDiccionario::desplegarLista(){
    NodeDiccionario* aux = primero;
    if(primero!=NULL){
        do{
            aux = aux->siguiente;
            cout<< aux->word <<endl;
        }while(aux!=primero);
    }
}

bool DoubleCircularListDiccionario::exists(std::string palabra_buscar){
    NodeDiccionario *aux = primero;
    if(primero!=nullptr){
        do{
            if(aux->word == palabra_buscar){
                return true;
            }
            aux = aux->siguiente;
        }
        while(aux!=primero);
    }
    return false;
}

void DoubleCircularListDiccionario::createDOT(std::string filename){
    creator = new CreateFile();
    std::string contenido;
    ofstream fs(filename);
    NodeDiccionario* aux = primero;
    contenido += "digraph Diccionario {";
    contenido += "node [ fontsize = 16 shape = record] ";
    do{
        std::string cont = "";
        cont += " \" " + aux->word + "\" [ label = \" "+ aux->word + "\" shape = record ];";
        cont +=  " \" " + aux->word + "\"" + " -> " +" \" " + aux->siguiente->word + "\"";
        cont +=  " \" " + aux->word + "\"" + " -> " +" \" " + aux->anterior->word + "\"";
        contenido.append(cont);
        aux = aux->siguiente;
    }while(aux!=primero);
    contenido += "}";
    fs << contenido;
    fs.close();
    creator->create(filename, "diccionario.png");

}

bool DoubleCircularListDiccionario::perteneceDiccionario(std::string palabra){
    NodeDiccionario *aux = primero;
    if(primero!=nullptr){
        do{
            if(aux->word==palabra){
                return true;
            }
            aux = aux->siguiente;
        }while(aux!=primero);
    }
    return false;
}

bool DoubleCircularListDiccionario::subCadenaDiccionario(std::string palabra, std::string subcadena){
    if(strstr(palabra.c_str(), subcadena.c_str())){
        return true;
    }return false;
}
