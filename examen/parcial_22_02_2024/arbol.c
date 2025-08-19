#include "arbol.h"

void crearArbol(tArbol *pa)
{
    *pa = NULL;
}

int insertarOrdenadoArbol(tArbol *pa, unsigned tamDato, void* dato, Duplicado duplicado, Cmp cmp)
{
    tNodo *nue;

    if(*pa)
    {
        if(cmp(dato, (*pa)->info) == 0)
        {
            duplicado((*pa)->info, dato);
//            duplicado(pa, (*pa)->info, dato);
            return -1;
        }
        else
        {
            if(cmp(dato, (*pa)->info) < 0)
                return insertarOrdenadoArbol(&(*pa)->izq, tamDato, dato, duplicado, cmp);
            return insertarOrdenadoArbol(&(*pa)->der, tamDato, dato, duplicado, cmp);
        }

    }
    if(!(nue= malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
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

void mapInOrdenArbol(tArbol *pa, void* cond, Accion accion)
{
    if(*pa)
    {
        mapInOrdenArbol(&(*pa)->izq, cond, accion);
        accion((*pa)->info, cond);
        mapInOrdenArbol(&(*pa)->der, cond, accion);
    }
}
void mapInOrdenArbolInverso(tArbol *pa, void* cond, Accion accion)
{
    if(*pa)
    {
        mapInOrdenArbolInverso(&(*pa)->der, cond, accion);
        accion((*pa)->info, cond);
        mapInOrdenArbolInverso(&(*pa)->izq, cond, accion);
    }
}

int eliminarRaiz(tArbol *pa, unsigned tamDato, void* dato)
{
    tNodo *elim, **remplazo;
    if(*pa)
        return 0;

    memcpy(dato, (*pa)->info, MIN(tamDato, (*pa)->tamInfo));
    free((*pa)->info);

    if( (*pa)->izq ==NULL && (*pa)->der ==NULL )
    {
        free(*pa);
        *pa =NULL;
        return -1;
    }

    remplazo = alturaArbol(&(*pa)->izq) > alturaArbol(&(*pa)->der) ? mayorArbol(&(*pa)->izq) : menorArbol(&(*pa)->der);
    elim = *remplazo;
    (*pa)->info = elim->info;
    (*pa)->tamInfo = elim->tamInfo;

    *remplazo = elim->izq ? elim->izq : elim->der;
    free(elim->info);
    free(elim);
    return 1;
}

int alturaArbol(const tArbol *pa)
{
    int h1, h2;
    if(*pa ==NULL)
        return 0;

    h1 = alturaArbol(&(*pa)->izq);
    h2 = alturaArbol(&(*pa)->der);

    return (h1>h2 ? h1 : h2) +1;
}

tNodo** mayorArbol(const tArbol *pa)
{
    if(*pa)
    {
        if((*pa)->der ==NULL)
            return (tNodo**)pa;
        mayorArbol(&(*pa)->der);
    }
    return NULL;
}
tNodo** menorArbol(const tArbol *pa)
{
    if(*pa)
    {
        if((*pa)->izq ==NULL)
            return (tNodo**)pa;
        menorArbol(&(*pa)->izq);
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
        *pa = NULL;
        free(elim->info);
        free(elim);
    }
}
