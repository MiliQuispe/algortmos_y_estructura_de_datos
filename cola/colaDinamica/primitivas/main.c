#include "cola.h"

int main()
{
    int vec[]= {1,2,3,4,5};
    int i, aux;
    tCola pc;

    crearCola(&pc);


    for(i=0; i<5; i++)
    {
        ponerEnCola(&pc, sizeof(int), vec + i);
    }

//    vaciarCola(&pc);

    for(i=0; i<8; i++)
    {
        verPrimero(&pc, sizeof(int), &aux);
        printf("%d\n", aux);
        sacarEnCola(&pc, sizeof(int), &aux);
    }

    return 0;
}
