#ifndef FICHA_H
#define FICHA_H
#include <iostream>

using namespace std;

class Ficha
{
    public:
        Ficha(int, char);
        int noFicha;
        int puntaje;
        char letra;
        int getNoFicha();
        int getPuntaje();
        char getLetra();
        bool getDoble();
        bool getTriple();
        void setNoFicha(int);
        void setPuntaje(int);
        void setLetra(char);
        void setDoble(bool);
        void setTriple(bool);
        bool doble;
        bool triple;
    protected:

    private:
};

#endif // FICHA_H
