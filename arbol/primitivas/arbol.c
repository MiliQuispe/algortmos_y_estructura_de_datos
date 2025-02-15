#include "arbol.h"

void crearArbol(tArbol *pa)
{
    *pa = NULL;
}

int siEsArbolBinarioVacio(const tArbol *pa)
{
    return *pa==NULL;
}

int siEsArbolBinarioLleno(const tArbol *pa, unsigned tamDato)
{
    return 0;
}

int insertarOrdenadoaArbolBinario(tArbol *pa, unsigned tamDato, const void* dato,Cmp cmp)
{
    tNodo *nue;

    if(*pa)
    {
        if(cmp((*pa)->info, dato)==0)
            return -1;
        else
        {
            if(cmp((*pa)->info, dato)>0)
                return insertarOrdenadoaArbolBinario(&(*pa)->izq, tamDato, dato, cmp);
            else
                return insertarOrdenadoaArbolBinario(&(*pa)->der, tamDato, dato, cmp);
        }

    }

    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->der = NULL;
    nue->izq = NULL;
    *pa =nue;
    return 1;
}

void mapPreOrden(tArbol *pa, const void* cond, Accion accion)
{
    if(*pa)
    {
        accion((*pa)->info, cond);
        mapPosOrden(&(*pa)->izq,cond, accion);
        mapPosOrden(&(*pa)->der,cond, accion);
    }
}

void mapInOrden(tArbol *pa, const void* cond, Accion accion)
{
    if(*pa)
    {
        mapInOrden(&(*pa)->izq,cond, accion);
        accion((*pa)->info, cond);
        mapInOrden(&(*pa)->der,cond, accion);
    }
}

void mapPosOrden(tArbol *pa, const void* cond, Accion accion)
{
    if(*pa)
    {
        mapPosOrden(&(*pa)->izq,cond, accion);
        mapPosOrden(&(*pa)->der,cond, accion);
        accion((*pa)->info, cond);
    }
}

int eliminarRaiz(tArbol *pa)
{
    tNodo **remp,*elim;

    if(*pa ==NULL)
        return 0;

    free((*pa)->info);
    if((*pa)->izq ==NULL && (*pa)->der ==NULL)
    {
        free(*pa);
        *pa =NULL;
        return 1;
    }

    remp = alturaDelArbol(&(*pa)->izq) > alturaDelArbol(&(*pa)->der) ? mayorDelArbol(&(*pa)->izq) : menorDelArbol(&(*pa)->der);

    elim = *remp;
    (*pa)->info = elim->info;
    (*pa)->tamInfo = elim->tamInfo;

    *remp =  elim->izq ? elim->izq : elim->der;

    free(elim);

    return 1;
}

int alturaDelArbol(const tArbol *pa)
{
    int h1, h2;

    if(*pa ==NULL)
        return 0;

    h1 = alturaDelArbol(&(*pa)->izq) + 1;
    h2 = alturaDelArbol(&(*pa)->der) + 1;

    return h1>h2 ? h1 : h2;
}

tNodo** mayorDelArbol(const tArbol *pa)
{
    if(*pa)
    {
        if((*pa)->der ==NULL)
            return (tArbol*)pa;
        return mayorDelArbol(&(*pa)->der);
    }
    return NULL;
}

tNodo** menorDelArbol(const tArbol *pa)
{
    if(*pa)
    {
        if((*pa)->izq ==NULL)
            return (tArbol*)pa;

        return mayorDelArbol(&(*pa)->izq);
    }
    return NULL;
}

tNodo** buscarArbolBinario(const tArbol *pa, const void* dato, Cmp cmp)
{
    if(*pa)
    {
        if(cmp((*pa)->info, dato)==0)
            return (tArbol*)pa;
        else
        {
            if(cmp((*pa)->info, dato)>0)
                return buscarArbolBinario(&(*pa)->izq, dato, cmp);
            else
                return buscarArbolBinario(&(*pa)->der, dato, cmp);
        }
    }
    return NULL;
}

void vaciarArbol(tArbol *pa)
{
    tNodo *elim;
    if(*pa)
    {
        vaciarArbol(&(*pa)->izq);
        vaciarArbol(&(*pa)->der);

        elim = *pa;
        *pa =NULL;
        free(elim->info);
        free(elim);
    }
}
