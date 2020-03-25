#include "NodeDiccionario.h"
#include <iostream>
using namespace std;
NodeDiccionario::NodeDiccionario(std::string word)
{
    this->word = word;
    this->siguiente = NULL;
    this->anterior = NULL;
}
