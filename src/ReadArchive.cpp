#include "ReadArchive.h"
#include <string>
#include "json.hpp"
#include <fstream>      // std::ifstream
#include <typeinfo>
#include <iostream>
#include "DoubleCircularListDiccionario.h"
#include "SimplyLinkedListCoordenada.h"
using json = nlohmann::json;
using namespace std;

ReadArchive::ReadArchive(DoubleCircularListDiccionario* _diccionario)
{
    this->coordenadas = new SimplyLinkedListCoordenada();
    this->diccionario = _diccionario;
    this->dimension = 0;
}
void ReadArchive::readJSON(std::string filename){
    try{
        std::ifstream i(filename);
        json j;
        i >> j;
        for(int x = 0; x<j.at("diccionario").size();x++){
            diccionario->insertarNodo(j.at("diccionario")[x].at("palabra"));
        }
        for(int y = 0; y<j.at("casillas").at("dobles").size(); y++){
            Coordenada *cor = new Coordenada(j.at("casillas").at("dobles")[y].at("x").get<int>(),
                                             j.at("casillas").at("dobles")[y].at("y").get<int>(),
                                            "doble" );
            coordenadas->insertar(cor);
        }
        for(int i= 0; i<j.at("casillas").at("triples").size();i++){
            Coordenada *cor = new Coordenada(j.at("casillas").at("triples")[i].at("x").get<int>(),
                                             j.at("casillas").at("triples")[i].at("y").get<int>(),
                                            "triple" );
            coordenadas->insertar(cor);
        }
        dimension =  j.at("dimension").get<int>();
        cout<< "Archivo cargado correctamente! "<<endl;
    }catch(exception e){
        cout<< "Ocurrio un error al leer el archivo"<<endl;
    }

}

int ReadArchive::getDimension(){
    return this->dimension;
}


DoubleCircularListDiccionario  * ReadArchive::getDiccionario(){
    return this->diccionario;
}

SimplyLinkedListCoordenada * ReadArchive::getCoordenadas(){
    return this->coordenadas;
}
