#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include "ReadArchive.h"
#include "DoubleCircularListDiccionario.h"
class MenuPrincipal
{
    public:
        DoubleCircularListDiccionario* diccionario_palabras;
        int opcion;
        MenuPrincipal();
        void desplegarMenu();
        ReadArchive* reader;
    protected:

    private:
};

#endif // MENUPRINCIPAL_H
