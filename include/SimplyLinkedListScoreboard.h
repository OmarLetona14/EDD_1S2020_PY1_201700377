#ifndef SIMPLYLINKEDLISTSCOREBOARD_H
#define SIMPLYLINKEDLISTSCOREBOARD_H
#include "NodeScore.h"
#include "Score.h"
class SimplyLinkedListScoreboard
{
    public:
        SimplyLinkedListScoreboard();
        void insertar(Score*);
        NodeScore *primero;
        NodeScore *ultimo;
        int size;
        void mostrarLista();
        SimplyLinkedListScoreboard* devolverPrimerosCinco();
        Score* devolverMejorPuntaje();
    protected:

    private:
};

#endif // SIMPLYLINKEDLISTSCOREBOARD_H
