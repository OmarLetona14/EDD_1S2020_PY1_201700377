#include "GenerateRandom.h"
#include <cstdlib>      // rand, srand
#include <ctime>
#include "ColaFicha.h"
GenerateRandom::GenerateRandom()
{
    this->cola = new ColaFicha();
}
int GenerateRandom::generateR(){
    int valor = 0;
    valor = rand() % 25;
    return valor;
}

ColaFicha* GenerateRandom::fillQueue(){
    int suma = 0;
    cout<<"Generando fichas..."<<endl;
    do{
        int random_c = 97+generateR();
        char letra = char(random_c);
        ficha = new Ficha(cola->getSize()+1,letra);
        switch(letra){
        case 'a':
            if(a<=12){
                ficha->setPuntaje(1);
                a++;suma++;
                cola->push(ficha);
            }
            break;
        case 'b':
            if(b<=2){
                ficha->setPuntaje(3);
                b++;suma++;
                cola->push(ficha);
            }
            break;
        case 'c':
            if(c<=4){
                ficha->setPuntaje(3);
                c++;suma++;
                cola->push(ficha);
            }
            break;
        case 'd':
            if(d<=5){
                ficha->setPuntaje(2);
                d++;suma++;
                cola->push(ficha);
            }
            break;
        case 'e':
            if(e<=12){
                ficha->setPuntaje(1);
                e++;suma++;
                cola->push(ficha);
            }
            break;
        case 'f':
            if(f<=1){
                ficha->setPuntaje(4);
                f++;suma++;
                cola->push(ficha);
            }
            break;
        case 'g':
            if(g<=2){
                ficha->setPuntaje(2);
                g++;suma++;
                cola->push(ficha);
            }
            break;
        case 'h':
            if(h<=2){
                ficha->setPuntaje(4);
                h++;suma++;
                cola->push(ficha);
            }
            break;
        case 'i':
            if(i<=6){
                ficha->setPuntaje(1);
                i++;suma++;
                cola->push(ficha);
            }
            break;
        case 'j':
            if(j<=1){
                ficha->setPuntaje(8);
                j++;suma++;
                cola->push(ficha);
            }
            break;
        case 'l':
            if(l<=4){
                ficha->setPuntaje(1);
                l++;suma++;
                cola->push(ficha);
            }
            break;
        case 'm':
            if(m<=2){
                ficha->setPuntaje(3);
                m++;suma++;
                cola->push(ficha);
            }
            break;
        case 'n':
            if(n<=5){
                ficha->setPuntaje(1);
                n++;suma++;
                cola->push(ficha);
            }
            break;
        case 'ñ':
            if(ene<=1){
                ficha->setPuntaje(8);
                ene++;suma++;
                cola->push(ficha);
            }
            break;
        case 'o':
            if(o<=9){
                ficha->setPuntaje(1);
                o++;suma++;
                cola->push(ficha);
            }
            break;
        case 'p':
            if(p<=2){
                ficha->setPuntaje(3);
                p++;suma++;
                cola->push(ficha);
            }
            break;
        case 'q':
            if(q<=1){
                ficha->setPuntaje(5);
                q++;suma++;
                cola->push(ficha);
            }
            break;
        case 'r':
            if(r<=5){
                ficha->setPuntaje(1);
                r++;suma++;
                cola->push(ficha);
            }
            break;
        case 's':
            if(s<=6){
                ficha->setPuntaje(1);
                s++;suma++;
                cola->push(ficha);
            }
            break;
        case 't':
            if(t<=4){
                ficha->setPuntaje(1);
                t++;suma++;
                cola->push(ficha);
            }
            break;
        case 'u':
            if(u<=5){
                ficha->setPuntaje(1);
                u++;suma++;
                cola->push(ficha);
            }
            break;
        case 'v':
            if(v<=1){
                ficha->setPuntaje(4);
                v++;suma++;
                cola->push(ficha);
            }
            break;
        case 'x':
            if(random_x<=1){
                ficha->setPuntaje(8);
                random_x++;suma++;
                cola->push(ficha);
            }
            break;
        case 'y':
            if(y<=1){
                ficha->setPuntaje(4);
                y++;suma++;
                cola->push(ficha);
            }
            break;
        case 'z':
            if(z<=1){
                ficha->setPuntaje(10);
                z++;suma++;
                cola->push(ficha);
            }
            break;
        }
    }while(suma<=80);
    cout<<"Fichas generadas correctamente...";
    return cola;
}
