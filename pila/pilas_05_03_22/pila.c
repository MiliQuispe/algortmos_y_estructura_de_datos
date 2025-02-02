#include "pila.h"

void crearPila (tPila *p)
{
    *p = NULL;
}

int siEsPilaLLena(const tPila *p, unsigned tamDato)
{
    return 0;
}
int siEsPilaVacia (const tPila *p)
{
    return *p ==NULL;
}

int ponerEnPila(tPila *p, unsigned tamDato, const void* dato)
{
    tNodo *nue;

    if(!(nue = malloc(sizeof (tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = *p;
    *p = nue;
    return 1;
}
int sacarEnPila(tPila *p, unsigned tamDato, void* dato)
{
    tNodo *elim;

    if(*p ==NULL)
        return 0;

    elim= *p;
    memcpy(dato, elim->info, MIN(tamDato, elim->tamInfo));
    *p = elim->sig;
    free(elim->info);
    free(elim);

    return 1;
}

void vaciarPila(tPila *p)
{
    tNodo *elim;

    while(*p)
    {
        elim= *p;
        *p = elim->sig;
        free(elim->info);
        free(elim);
    }
}

int verTope(tPila *p, unsigned tamDato, void* dato)
{
    tNodo *ver;

    if(*p ==NULL)
        return 0;

    ver= *p;
    memcpy(dato, ver->info, MIN(tamDato,ver->tamInfo));
    return 1;
}
