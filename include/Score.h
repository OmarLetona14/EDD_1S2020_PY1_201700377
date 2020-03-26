#ifndef SCORE_H
#define SCORE_H
#include <iostream>
using namespace std;

class Score
{
    public:
        std::string nombre_jugador;
        int puntaje;
        Score(std::string, int);
        int getPuntaje();
        std::string getNombreJugador();
        void setPuntaje(int);
        void setNombreJugador(std::string);
    protected:

    private:
};

#endif // SCORE_H
