#include "pila.h"

void crearPila(tPila *p)
{
    *p = NULL;
}

int siEsPilaVacia(const tPila *p)
{
    return *p ==NULL;
}
int siEsPilaLLlena (const tPila *p , unsigned cantBytes)
{
    return 0;
}

int ponerEnPila(tPila* p, unsigned cantBytes, const void* dato)
{
    tNodo *nue;

    if(!(nue= malloc(sizeof(tNodo))) || !(nue->info = malloc(cantBytes)))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, dato, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p=nue;

    return 1;
}
int sacarEnPila(tPila* p, unsigned cantBytes, void* dato)
{
    tNodo *elim;

    if(*p ==NULL)
        return 0;

    elim = *p;
    memcpy(dato,elim->info, MIN(cantBytes, elim->tamInfo));

    *p= elim->sig;
    free(elim->info);
    free(elim);
    return 1;
}

void vaciarPila(tPila *p)
{
    tNodo *elim;
    while(*p)
    {
        elim = *p;
        *p = elim->sig;
        free(elim->info);
        free(elim);
    }
}

int verTope(tPila *p, unsigned cantBytes, void* dato)
{
    if(*p ==NULL)
        return 0;

    memcpy(dato,(*p)->info, MIN(cantBytes, (*p)->tamInfo));
    return 1;
}
