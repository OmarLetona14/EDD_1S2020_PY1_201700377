#include "ReadArchive.h"
#include <string>
#include "json.hpp"
#include <fstream>      // std::ifstream
#include <typeinfo>
#include "DoubleCircularListDiccionario.h"
using json = nlohmann::json;

ReadArchive::ReadArchive(DoubleCircularListDiccionario* _diccionario)
{
    this->diccionario = _diccionario;
}
void ReadArchive::readJSON(std::string filename){
    std::ifstream i(filename);
    json j;
    i >> j;
    for(int x = 0; x<j.at("diccionario").size();x++){
        diccionario->insertarNodo(j.at("diccionario")[x].at("palabra"));
    }
    diccionario->desplegarLista();

}
