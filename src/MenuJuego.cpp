#include "MenuJuego.h"
#include <iostream>
#include "GenerateRandom.h"
using namespace std;

MenuJuego::MenuJuego()
{
    this->colaFichas = new ColaFicha();
}

void MenuJuego::mostrarMenu(){
    do{
        cout<<" BIENVENIDO AL JUEGO " <<endl;
        cout<<" 1.Nuevo Juego " <<endl;
        cout<<" 2. Mostrar mayores puntajes" <<endl;
        cout<<" 3. Introducir nuevo jugador" <<endl;
        cout<<" 4. Regresar al menu principal" <<endl;
        cin>>opcion;
        switch(opcion){
        case 1:
            randomQueue = new GenerateRandom();
            colaFichas = randomQueue->fillQueue();
            colaFichas->desplegarCola();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }while(opcion!=4);


}

