#ifndef SIMPLYLINKEDLISTSCOREBOARD_H
#define SIMPLYLINKEDLISTSCOREBOARD_H
#include "NodeScore.h"
#include "Score.h"
#include "CreateFile.h"
class SimplyLinkedListScoreboard
{

    public:
        CreateFile *creator;
        SimplyLinkedListScoreboard();
        void insertar(Score*);
        NodeScore *primero;
        NodeScore *ultimo;
        int size;
        void mostrarLista();
        int getSize();
        SimplyLinkedListScoreboard* devolverPrimerosCinco();
        Score* devolverMejorPuntaje();
        void createDOT(std::string);
    protected:

    private:
};

#endif // SIMPLYLINKEDLISTSCOREBOARD_H
