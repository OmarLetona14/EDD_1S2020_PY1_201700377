#include "GenerateRandom.h"
#include <cstdlib>      // rand, srand
#include <ctime>

GenerateRandom::GenerateRandom()
{
    //ctor
}
int GenerateRandom::generateR(){
    int valor = 0;
    srand(time(NULL));
    valor = rand() % 25;
    return valor;
}

void GenerateRandom::fillQueue(){
    int suma = 0;
    do{
        int random_c = 97+generateR();
        char letra = (char)random_c;
        switch(letra){
        case 'a':
            if(a<=12){

            }
            break;
        case 'b':
            if(){

            }
            break;
        case 'c':
            if(){

            }
            break;
        case 'd':
            if(){

            }
            break;
        case 'e':
            if(){

            }
            break;
        case 'f':
            if(){

            }
            break;
        case 'g':
            break
        case 'h':
            if(){

            }
            break;
        case 'i':
            if(){

            }
            break;
        case 'j':
            if(){

            }
            break;
        case 'k':
            if(){

            }
            break;
        case 'l':
            if(){

            }
            break;
        case 'm':
            if(){

            }
            break;
        case 'n':
            if(){

            }
            break;
        case 'g':
            if(){

            }
            break;
        case 'o':
            if(){

            }
            break;
        case 'p':
            if(){

            }
            break;
        case 'q':
            if(){

            }
            break;
        case 'r':
            if(){

            }
            break;
        case 's':
            if(){

            }
            break;
        case 't':
            if(){

            }
            break;
            if(){

            }
        case 'u':
            break;
        case 'v':
            if(){

            }
            break;
        case 'w':
            if(){

            }
            break;
        case 'x':
            if(){

            }
            break;
        case 'y':
            if(){

            }
            break;
        case 'z':
            break;
        }
    }while(suma<=95);




}
