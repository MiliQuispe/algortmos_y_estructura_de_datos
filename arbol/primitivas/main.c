#include "arbol.h"

int cmpInt (const void* a, const void* b)
{
    int* num1 = (int*)a;
    int* num2 = (int*)b;

    return *num1 - *num2;
}

void mostrarInt (void* info, const void* cond)
{
    int* num = (int*)info;
    printf("%d\t",*num);
}

int main()
{
    int vec[]= {3,5,1,6,2,4};
    int i;
    tArbol pa;

    crearArbol(&pa);

    for(i=0; i<6; i++)
    {
        insertarOrdenadoaArbolBinario(&pa, sizeof(int), vec+i, cmpInt);
    }
     i=5;

    if(buscarArbolBinario(&pa, &i,cmpInt))
        eliminarRaiz(buscarArbolBinario(&pa,&i,cmpInt));

    printf("Altura del arbol %d\n", alturaDelArbol(&pa));
    printf("\n");
    mapInOrden(&pa, NULL,mostrarInt);
    printf("\n");
    mapPosOrden(&pa, NULL,mostrarInt);
    printf("\n");
    mapPreOrden(&pa, NULL,mostrarInt);

    vaciarArbol(&pa);

    return 0;
}
