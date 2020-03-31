#ifndef READARCHIVE_H
#define READARCHIVE_H

#include <string>
#include "json.hpp"
#include <fstream>      // std::ifstream
#include <typeinfo>
#include "DoubleCircularListDiccionario.h"
class ReadArchive
{
    public:
        ReadArchive(DoubleCircularListDiccionario*);
        void readJSON(std::string);
        DoubleCircularListDiccionario* diccionario;
        int dimension;
        int getDimension();
    protected:

    private:
};

#endif // READARCHIVE_H
