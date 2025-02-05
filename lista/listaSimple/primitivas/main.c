#include "lista.h"

/// no generica

void mostrarEntero (void* dato, const void* cond);
int cmpEntero (const void* a, const void* b);

int main()
{
    int vec[]={1,2,3,4,5};
    int i,aux;
    tLista pl;

    crearLista(&pl);

    for(i=0; i<5; i++)
    {
//        ponerXposicionLista(&pl, sizeof(int), vec+i, i);
        insertarOrdenadoLista(&pl, sizeof(int), vec+i, cmpEntero);
    }

    for(i=0; i<6; i++)
    {
        mapLista(&pl,NULL,mostrarEntero); printf("\n");
//        sacarEnXposicionLista(&pl, sizeof(int), &aux, 4-i);
        aux= i+1;
        sacarXvalorLista(&pl, sizeof(int), &aux, cmpEntero);
    }

    vaciarLista(&pl);

    return 0;
}

void mostrarEntero (void* dato, const void* cond)
{
    int* info = (int*) dato;

    printf("%d\t", *info);
}

int cmpEntero (const void* a, const void* b)
{
    int* dato1 = (int*)a;
    int* dato2 = (int*)b;

    return *dato1 - *dato2;
}
