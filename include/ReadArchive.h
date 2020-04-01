#ifndef READARCHIVE_H
#define READARCHIVE_H

#include <string>
#include "json.hpp"
#include <fstream>      // std::ifstream
#include <typeinfo>
#include "DoubleCircularListDiccionario.h"
#include "SimplyLinkedListCoordenada.h"
class ReadArchive
{
    public:
        SimplyLinkedListCoordenada *coordenadas;
        ReadArchive(DoubleCircularListDiccionario*);
        void readJSON(std::string);
        DoubleCircularListDiccionario* diccionario;
        int dimension;
        int getDimension();
        SimplyLinkedListCoordenada *getCoordenadas();
        DoubleCircularListDiccionario *getDiccionario();
    protected:

    private:
};

#endif // READARCHIVE_H
