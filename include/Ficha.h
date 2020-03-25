#ifndef FICHA_H
#define FICHA_H
#include <iostream>

using namespace std;

class Ficha
{
    public:
        Ficha();
        int noFicha;
        int puntaje;
        char letra;
        int getNoFicha()
        int getPuntaje();
        char getLetra();
        void setNoFicha(int);
        void setPuntaje(int);
        void setLetra(char);
    protected:

    private:
};

#endif // FICHA_H
