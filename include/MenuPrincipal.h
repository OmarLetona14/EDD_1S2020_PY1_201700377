#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include "ReadArchive.h"
#include "DoubleCircularListDiccionario.h"
#include "MenuJuego.h"

class MenuPrincipal
{
    public:
        int dimension_tablero;
        //MenuJuego *nuevo_juego;
        void generarReportes();
        DoubleCircularListDiccionario *diccionario_palabras;
        int opcion;
        MenuPrincipal();
        void desplegarMenu();
        ReadArchive* reader;
    protected:

    private:
};

#endif // MENUPRINCIPAL_H
