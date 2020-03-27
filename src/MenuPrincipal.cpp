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

            }
            break;
        case 2:
            nuevo_juego->mostrarMenu();
            break;
        case 3:
             do{
                cout<<"SELECCIONE EL REPORTE QUE DESEA VER"<<endl;
                cout<<"1. Palabras del diccionario" << endl;
                cout<<"2. Fichas disponibles en el juego" << endl;
                cout<<"3. Jugadores disponibles"<<endl;
                cout<<"4. Recorrido preorden del arbol binario de busqueda"<<endl;
                cout<<"5. Recorrido inorden del arbol binario de busqueda"<<endl;
                cout<<"6. Recorrido postorden del arbol binario de busqueda"<<endl;
                cout<<"7. Historial de puntajes de un jugador"<<endl;
                cout<<"8. Scoreboard general"<<endl;
                cout<<"9. Tablero"<<endl;
                cout<<"10. Fichas de los jugadores"<<endl;
                cout<<"11. Salir"<<endl;
                cin>>opcion;
                switch(opcion){
                case 1:
                    if(diccionario_palabras->getSize()!=0){
                        diccionario_palabras->createDOT("diccionario.dot");
                    }else{
                        cout<<"Lista vacia"<<endl;
                    }
                    break;
                case 2:
                    nuevo_juego->getColaFichas()->generateDOT("colaFichas.dot");
                    break;
                case 3:
                    nuevo_juego->getJugadores()->GraphABB(nuevo_juego->getRoot());
                    break;
                case 4:
                    nuevo_juego->getJugadores()->createDOT("JugadoresPreOrden.dot","preorder", nuevo_juego->getRoot());
                    break;
                case 5:
                    nuevo_juego->getJugadores()->createDOT("JugadoresInOrden.dot","inorder", nuevo_juego->getRoot());
                    break;
                case 6:
                    nuevo_juego->getJugadores()->createDOT("JugadoresPostOrden.dot","postorder", nuevo_juego->getRoot());
                    break;
                }
                system("pause");
                system("cls");
            }while(opcion!=11);
            break;
        }
        system("cls");
    }while(opcion!=4);

}
