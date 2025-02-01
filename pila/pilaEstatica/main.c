#include "primitivas/pila.h"

int main()
{
    int vec[] ={1,2,3,4,5};
    int i,aux=-1;

    tPila p;
    crearPila(&p);

    for(i=0; i<5; i++)
    {
        ponerEnPila(&p,sizeof(int), vec+i);
    }
//    vaciarPila(&p);

    for(i=0; i<8; i++)
    {
        verTope(&p,sizeof(int), &aux);
        printf("%d\t", aux);
        sacarEnPila(&p,sizeof(int), &aux);
    }
}
