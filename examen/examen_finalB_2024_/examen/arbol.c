///45064110_Quispe_Milagros
#include "../include/arbol.h"

void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p =NULL;
}


int insertarArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, int (*cmp)(const void *, const void *))
{
    tNodoArbol *nue;

    if(*p)
    {
        if(cmp(d, (*p)->info) ==0)
            return -1;
        if(cmp(d, (*p)->info) <0)
            return insertarArbolBinBusq(&(*p)->izq, d, tam, cmp);
        return insertarArbolBinBusq(&(*p)->der, d, tam, cmp);
    }

    if(!(nue=malloc(sizeof(tNodoArbol))) || !(nue->info = malloc(tam)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, tam);
    nue->tamInfo = tam;
    nue->der = NULL;
    nue->izq= NULL;
    *p = nue;
    return 1;
}

void recorrerPreOrdenSimpleArbolBinBusq(const tArbolBinBusq *p, void *params, void (*accion)(void *, unsigned, void *))
{
    if(*p)
    {
        accion((*p)->info, (*p)->tamInfo, params);
        recorrerPreOrdenSimpleArbolBinBusq(&(*p)->izq, params, accion);
        recorrerPreOrdenSimpleArbolBinBusq(&(*p)->der, params, accion);
    }
}

void vaciarArbolBin(tArbolBinBusq *p)
{
    tNodoArbol *elim;
    if(*p)
    {
        vaciarArbolBin(&(*p)->izq);
        vaciarArbolBin(&(*p)->der);

        elim = *p;
        *p = NULL;
        free(elim->info);
        free(elim);
    }
}
