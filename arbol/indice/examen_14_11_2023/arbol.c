#include "arbol.h"

void crearArbol(tArbol *pa)
{
    *pa = NULL;
}
int siesArbolvacio(const tArbol* pa)
{
    return *pa ==NULL;
}

int insertarOrdenadoArbol(tArbol *pa, unsigned tamDato, void* dato, Cmp cmp)
{
    tNodo *nue;

    if(*pa)
    {
        if(cmp(dato, (*pa)->info) ==0)
            return -1;
        if(cmp(dato, (*pa)->info) < 0)
            return insertarOrdenadoArbol(&(*pa)->izq, tamDato,dato ,cmp);

        return insertarOrdenadoArbol(&(*pa)->der, tamDato,dato ,cmp);
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
    *pa = nue;
    return 1;
}

int alturaArbol(const tArbol *pa)
{
    int h1,h2;

    if(*pa==NULL)
        return 0;

    h1 = alturaArbol(&(*pa)->izq);
    h2 = alturaArbol(&(*pa)->der);

    return (h1>h2 ? h1 : h2) +1;
}

tNodo** mayorHijoArbol(const tArbol *pa)
{
    if(*pa)
    {
        if((*pa)->der ==NULL)
            return (tNodo** )pa;

        return mayorHijoArbol(&(*pa)->der);
    }
    return NULL;
}

tNodo** menorHijoArbol(const tArbol *pa)
{
    if(*pa)
    {
        if((*pa)->izq ==NULL)
            return (tNodo** )pa;

        return menorHijoArbol(&(*pa)->izq);
    }
    return NULL;
}

tNodo** buscarNodoArbol(const tArbol *pa, const void* dato, Cmp cmp)
{
    if(*pa)
    {
        if(cmp(dato, (*pa)->info) !=0)
        {
            if(cmp(dato, (*pa)->info) < 0)
                return buscarNodoArbol(&(*pa)->izq, dato ,cmp);

            return buscarNodoArbol(&(*pa)->der, dato ,cmp);
        }
    }
    return (tNodo** )pa;
}

int eliminarRaizArbol(tArbol *pa, unsigned tamdato, void* dato)
{
    tNodo *elim , **reemplazo;
    int h1, h2;

    if(*pa ==NULL)
        return 0;

    memcpy(dato, (*pa)->info, MIN(tamdato,(*pa)->tamInfo));
    free((*pa)->info);

    if((*pa)->izq ==NULL && (*pa)->der==NULL)
    {
        free(*pa);
        *pa =NULL;
        return 1;
    }

    h1 =  alturaArbol(&(*pa)->izq);
    h2 = alturaArbol(&(*pa)->der) ;

    reemplazo = h1>h2 ? mayorHijoArbol(&(*pa)->izq) : menorHijoArbol(&(*pa)->der);

    elim = *reemplazo;

    (*pa)->info = elim->info;
    (*pa)->tamInfo = elim->tamInfo;

    *reemplazo = elim->izq ? elim->izq : elim->der;

    free(elim);
    return 1;
}

int cargarArbolIdx (tArbol *pa, int li, int ls, void* datos, void* parametros, Leer leer)
{
    int m = (li + ls)/2, r;

    if(li>ls)
        return 1;

    if(!((*pa) = malloc(sizeof(tNodo))) || ((*pa)->tamInfo = leer(&(*pa)->info, m , datos, parametros) == 0))
    {
        free(*pa);
        return 0;
    }

    (*pa)->izq = NULL;
    (*pa)->der = NULL;

    r = cargarArbolIdx(&(*pa)->izq, li, m - 1, datos, parametros, leer);
    if(r !=1)
        return 1;
    return cargarArbolIdx(&(*pa)->der, m + 1, ls, datos, parametros, leer);
}

void mapInOrden(tArbol *pa, void* cond, Accion accion)
{
    if(*pa)
    {
        mapInOrden(&(*pa)->izq, cond, accion);
        accion((*pa)->info, cond);
        mapInOrden(&(*pa)->der, cond, accion);
    }
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
