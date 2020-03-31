#include "ReadArchive.h"
#include <string>
#include "json.hpp"
#include <fstream>      // std::ifstream
#include <typeinfo>
#include <iostream>
#include "DoubleCircularListDiccionario.h"
using json = nlohmann::json;
using namespace std;

ReadArchive::ReadArchive(DoubleCircularListDiccionario* _diccionario)
{
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
        dimension =  j.at("dimension").get<int>();
    }catch(exception e){
        cout<< "Ocurrio un error al leer el archivo"<<endl;
    }

}

int ReadArchive::getDimension(){
    return this->dimension;
}
