#include "cola.h"

int main()
{
    int vec[] ={1,2,3,4,5};
    int i,aux=-1;

    tCola pc;
    crearCola(&pc);

    for(i=0; i<5; i++)
    {
        ponerEnCola(&pc,sizeof(int), vec+i);
    }
//    vaciarPila(&p);

    for(i=0; i<9; i++)
    {
        verPrimero(&pc,sizeof(int), &aux);
        printf("%d\t", aux);
        sacarEnCola(&pc,sizeof(int), &aux);
    }
}
