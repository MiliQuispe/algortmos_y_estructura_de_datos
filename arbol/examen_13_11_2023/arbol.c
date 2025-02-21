#include "arbol.h"

void crearArbol(tArbol *pa)
{
    *pa=NULL;
}


int insertsarOrdenadoNarbol(tArbol *pa, unsigned tamDato, const void* dato,int* ce, int n, Cmp cmp)
{
    tNodo *nue;

    if(*pa)
    {
        if(cmp(dato, (*pa)->info)==0)
            return -1;
        else
        {
            if(cmp(dato, (*pa)->info)<0)
            {
                return insertsarOrdenadoNarbol(&(*pa)->izq,tamDato, dato, ce, n,cmp);
            }
            else
                return insertsarOrdenadoNarbol(&(*pa)->der,tamDato, dato, ce, n,cmp);
        }

    }
    if(!(nue= malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->izq = NULL;
    nue->der = NULL;
    *pa = nue;

    if(*ce == n)
        return 2;
    else
    {
        *ce = *ce +1;
        return 1;
    }
}

int insertsarOrdenadoArbol(tArbol *pa, unsigned tamDato, const void* dato, Cmp cmp)
{
tNodo *nue;

    if(*pa)
    {
        if(cmp(dato, (*pa)->info)==0)
            return -1;
        else
        {
            if(cmp(dato, (*pa)->info)<0)
            {
                return insertsarOrdenadoArbol(&(*pa)->izq,tamDato, dato,cmp);
            }
            else
                return insertsarOrdenadoArbol(&(*pa)->der,tamDato, dato,cmp);
        }

    }
    if(!(nue= malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->izq = NULL;
    nue->der = NULL;
    *pa = nue;

    return 1;
}


int eliminarMenor(tArbol *pa, unsigned tamDato, void* dato)
{
    tNodo *elim;

    if(*pa)
    {
        if((*pa)->izq !=NULL)
            return eliminarMenor(&(*pa)->izq, tamDato, dato);
        elim = *pa;
        *pa = elim->der;

        memcpy(dato, elim->info, MIN(tamDato, elim->tamInfo));
        free(elim->info);
        free(elim);
        return 1;
    }
    return 0;
}

void  mapInOrden(tArbol *pa, void* cond, Accion accion)
{
    if(*pa)
    {
        mapInOrden(&(*pa)->izq,cond, accion);
        accion((*pa)->info, cond);
        mapInOrden(&(*pa)->der,cond, accion);
    }
}

void* buscarCondicionArbol(const tArbol* pa, void* cond, Buscar buscar)
{
    void* aux = NULL;
    if(*pa)
    {
        aux = buscarCondicionArbol(&(*pa)->izq, cond, buscar);

        if(aux ==NULL)
        {
            aux = (void* )buscar((*pa)->info, cond);

        }
        if(aux ==NULL)
                aux = buscarCondicionArbol(&(*pa)->der, cond, buscar);

//
//        aux = buscarCondicionArbol(&(*pa)->izq, cond, buscar);
//
//        if(!aux)
//            aux = buscar((*pa)->info, cond);
//        if(aux)
//        {
//            return aux;
//        }
//        buscarCondicionArbol(&(*pa)->der, cond, buscar);
    }
    return aux;
}

void vaciarArbol(tArbol *pa)
{
    tNodo *elim;

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
