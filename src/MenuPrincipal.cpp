#include "MenuPrincipal.h"
#include <iostream>
#include "ReadArchive.h"
#include "DoubleCircularListDiccionario.h"
#include "MenuJuego.h"
using namespace std;

MenuPrincipal::MenuPrincipal()
{
    this->diccionario_palabras = new DoubleCircularListDiccionario();
}
void MenuPrincipal::desplegarMenu(){
    MenuJuego* nuevo_juego = new MenuJuego();
    do{
    std::string file_string;
    cout << "BIENVENIDO AL PROGRAMA" << endl;
    cout << "Por favor seleccione una opcion" << endl;
    cout << "1. Lectura de archivo" << endl;
    cout << "2. Juego" << endl;
    cout << "3. Reportes" << endl;
    cout << "4. Salir" <<endl;
    cin >> opcion;
        switch(opcion){
        case 1:
            cout<< "Por favor ingrese la ruta del archivo que desea leer"<< endl;
            cin >> file_string;
            if(file_string!=""){
                reader = new ReadArchive(diccionario_palabras);
                reader->readJSON(file_string);
                cout<< "Carga masiva realizada con exito" <<endl;
                diccionario_palabras->createDOT("diccionario.dot");
            }
            break;
        case 2:
            nuevo_juego->mostrarMenu();
            break;
        case 3:
            break;
        }
    }while(opcion!=4);

}
