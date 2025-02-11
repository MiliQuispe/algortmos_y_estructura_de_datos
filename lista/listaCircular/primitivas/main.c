#include "listaCircular.h"

int cmpEntero (const void* a, const void* b);
void mostrarEntero (void* dato, void* cond);

int main()
{
    int vec[] ={1,2,3,4,5};
    int i,aux=-1;

    tListaCircular pl;

    crearListaCircular(&pl);

    for(i=0; i<5; i++)
    {
        insertarOrdenadoListaCircular(&pl, sizeof(int), vec+i, cmpEntero);
    }

//    mapListaCircular(&pl, NULL, mostrarEntero);
//    vaciarListaCircular(&pl);

    for(i=0; i<8; i++)
    {
        mapListaCircular(&pl, NULL, mostrarEntero);printf("\n");
        aux = i +1;
//        aux = 5 -i;
        eliminarXvalorListaCircular(&pl, sizeof(int), &aux, cmpEntero);
        printf("\n-%d-\n", aux);
    }
    vaciarListaCircular(&pl);
    return 0;
}

int cmpEntero (const void* a, const void* b)
{
    int* num1 = (int*)a;
    int* num2 = (int*)b;

    return *num1 - *num2;
}
void mostrarEntero (void* dato, void* cond)
{
    int* info = (int*)dato;
    printf("%d\t", *info);
}
