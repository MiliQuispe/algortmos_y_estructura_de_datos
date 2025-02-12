#include "listaDoble.h"

int cmpEntero (const void* a, const void* b);
void mostrarEntero( void* info, void* cond);

int mayoresA3 (void* info);
void sumarEnteros ( void* info, void* cond);

int main()
{
    int vec[]={2,1,4,5,3,6};
    int i, reduce =0, aux;

    tListaDoble pl;

    crearListaDoble(&pl);

    for(i=0; i<6; i++)
    {
        insertarOrdenadoListaDoble(&pl, sizeof(int), vec+i, cmpEntero, SI_DUPLICADO);
    }
    mapListaDobleA(&pl, NULL, mostrarEntero);printf("\n");
    mapListaDobleD(&pl, NULL, mostrarEntero);printf("\n\n");

    filterListDoble(&pl,mayoresA3);
    mapListaDobleA(&pl, NULL, mostrarEntero);printf("\n");
    mapListaDobleD(&pl, NULL, mostrarEntero);printf("\n\n");

    mapListaDobleA(&pl, &reduce, sumarEnteros);printf("%d\n",reduce); reduce =0;
    mapListaDobleD(&pl, &reduce, sumarEnteros);printf("%d\n",reduce);


    vaciarListaDoble(&pl);

    for(i=0; i<6; i++)
    {
        aux = i+1;
        if(eliminarValorListaDoble(&pl, sizeof(int), &aux, cmpEntero))
            printf("\n%d\n",aux);
    }

    vaciarListaDoble(&pl);

    return 0;
}


int cmpEntero (const void* a, const void* b)
{
    int* num1 = (int*)a;
    int* num2 = (int*)b;

    return *num1 - *num2;
}

void mostrarEntero(void* info, void* cond)
{
    int* num = (int*)info;
    printf("%d\t",*num);
}

int mayoresA3 (void* info)
{
    int* num = (int*)info;

    return *num <= 3;

}
void sumarEnteros (void* info, void* cond)
{
    int* dato = (int*)info;
    int* suma = (int*)cond;

    *suma = *suma + *dato;
}
