#include "cola.h"

int main()
{
    int vec[] ={1,2,3,4,5};
    int i,aux=-1;

    tCola p;
    crearCola(&p);

    for(i=0; i<5; i++)
    {
        insertarEnCola(&p,sizeof(int), vec+i);
    }


    for(i=0; i<7; i++)
    {

        sacarDeCola(&p,sizeof(int), &aux);
        printf("%d\t", aux);
    }

    vaciarCola(&p);

    return 0;
}
