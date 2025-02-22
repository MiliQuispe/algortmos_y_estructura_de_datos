#include "arbol.h"

void crearArbol(tArbol *pa)
{
    *pa = NULL;
}

int insertarOrdenadoArbol(tArbol *pa, unsigned tamDato, const void* dato, Cmp cmp)
{
    tNodoArbol *nue;
    if(*pa)
    {
        if(cmp(dato, (*pa)->info)==0)
            return -1;
        if(cmp(dato, (*pa)->info)<0)
            return insertarOrdenadoArbol(&(*pa)->izq, tamDato, dato, cmp);
        return insertarOrdenadoArbol(&(*pa)->der, tamDato, dato, cmp);
    }
    if(!(nue=malloc(sizeof(tNodoArbol))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->der = NULL;
    nue->izq = NULL;
    *pa = nue;
    return 1;
}

int cargarDatosOrdenados(tArbol *pa, void* datos, int li, int ls, void* parametros, Leer leer)
{
    int respuesta, m = (li+ls)/2;
    unsigned tamDato;

    if(li>ls)
        return 1;

    if(!((*pa) = malloc(sizeof(tNodoArbol))) || (tamDato = leer(&(*pa)->info, parametros,m, datos)) ==0)
    {
        free(*pa);
        return 0;
    }

    (*pa)->izq = NULL;
    (*pa)->der = NULL;
    (*pa)->tamInfo = tamDato;

    respuesta = cargarDatosOrdenados(&(*pa)->izq, datos, li, m - 1, parametros, leer);
    if(respuesta == 1)
        return respuesta;
    return cargarDatosOrdenados(&(*pa)->der, datos, m + 1, ls, parametros, leer);
}

void mapInOrdenArbol(tArbol *pa, void* cond, Accion accion)
{
    if(*pa)
    {
        mapInOrdenArbol(&(*pa)->izq,cond, accion);
        accion((*pa)->info, cond);
        mapInOrdenArbol(&(*pa)->der,cond, accion);
    }
}

void vaciarArbol(tArbol *pa)
{
    tNodoArbol *elim;

    if(*pa)
    {
        vaciarArbol(&(*pa)->izq);
        vaciarArbol(&(*pa)->der);

        elim = *pa;
        *pa = NULL;
        free(elim->info);
        free(elim);
    }
}
