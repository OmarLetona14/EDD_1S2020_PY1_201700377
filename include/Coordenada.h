#ifndef COORDENADA_H
#define COORDENADA_H
#include <iostream>

using namespace std;
class Coordenada
{
    public:
        Coordenada(int, int, std::string);
        int getY();
        int getX();
        std::string getValor();
        void setX(int);
        void setY(int);
        void setValor(std::string);
        void desplegarLista();
        int y;
        int x;
        std::string valor;

    protected:

    private:
};

#endif // COORDENADA_H
