#include "arbol.h"

void crearArbol(tArbol *pa)
{
    *pa = NULL;
}

int insertarOdenadoArbolBinarioDeBusqueda(tArbol *pa, unsigned tamInfo, const void* dato, Cmp cmp)
{
    tNodoArbol *nue;

    if(*pa)
    {
        if(cmp(dato, (*pa)->info) ==0)
            return -1;
        else
        {
            if(cmp(dato, (*pa)->info) < 0)
                return insertarOdenadoArbolBinarioDeBusqueda(&(*pa)->izq, tamInfo, dato, cmp);

            return insertarOdenadoArbolBinarioDeBusqueda(&(*pa)->der, tamInfo, dato, cmp);
        }
    }


    if(!(nue= malloc(sizeof(tNodoArbol))) || !(nue->info = malloc(tamInfo)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamInfo);
    nue->tamInfo = tamInfo;
    nue->der = NULL;
    nue->izq = NULL;
     *pa = nue;
     return 1;

}

void mapNivelArbolBinarioDeBusqueda(tArbol *pa, void* cond, int nivel, Accion accion)
{
    if(*pa && nivel >=0)
    {
        mapNivelArbolBinarioDeBusqueda(&(*pa)->izq, cond, nivel -1, accion);
        if(nivel ==0)
            accion((*pa)->info, cond);


        mapNivelArbolBinarioDeBusqueda(&(*pa)->der, cond, nivel -1, accion);

    }
}

void vaciarArbolBinarioDeBusqueda(tArbol* pa)
{
    tNodoArbol*elim;

    if(*pa)
    {
        vaciarArbolBinarioDeBusqueda(&(*pa)->izq);
        vaciarArbolBinarioDeBusqueda(&(*pa)->der);

        elim = *pa;
        *pa = NULL;
        free(elim->info);
        free(elim);
    }
}
