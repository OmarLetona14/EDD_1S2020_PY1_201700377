#ifndef NODEDICCIONARIO_H
#define NODEDICCIONARIO_H
#include <iostream>
using namespace std;

class NodeDiccionario
{
    public:
        std::string word;
        NodeDiccionario(std::string);
        NodeDiccionario* siguiente;
        NodeDiccionario* anterior;

    protected:

    private:


};

#endif // NODEDICCIONARIO_H
