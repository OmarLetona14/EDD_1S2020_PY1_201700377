#ifndef FICHA_H
#define FICHA_H
#include <iostream>

using namespace std;

class Ficha
{
    public:
        Ficha(int, char);
        int noFicha;
        int posicion_x;
        int posicion_y;
        int puntaje;
        char letra;
        int getPosicionX();
        int getPosicionY();
        int getNoFicha();
        int getPuntaje();
        char getLetra();
        bool getDoble();
        bool getTriple();
        void setPosicionX(int);
        void setPosicionY(int);
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
