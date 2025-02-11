#include "cola.h"

void crearCola(tCola *pc)
{
    *pc = NULL;
}

int siEsColaLlena(const tCola *pc, unsigned tamDato)
{
    return 0;
}
int siEsColaVacia(const tCola *pc)
{
    return *pc ==NULL;
}

int insertarEnCola (tCola *pc, unsigned tamDato, const void* dato)
{
    tNodo *nue;

    if(!(nue= malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo= tamDato;

    if(*pc == NULL)
    {
        nue->sig=nue;
    }
    else
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig=nue;
    }
    *pc = nue;
    return 1;
}

int sacarDeCola (tCola *pc, unsigned tamDato, void* dato)
{
    tNodo *elim;

    if(*pc==NULL)
        return 0;
    elim= (*pc)->sig;
    memcpy(dato, elim->info, MIN(tamDato, elim->tamInfo));

    if(*pc == elim)
        *pc =NULL;
    else
        (*pc)->sig=elim->sig;

    free(elim->info);
    free(elim);
    return 1;
}

void vaciarCola(tCola *pc)
{
    tNodo *elim;

    while(*pc)
    {
        elim = (*pc)->sig;

        if(elim->sig == (*pc)->sig)
            *pc =NULL;
        else
            (*pc)->sig= elim->sig;

        free(elim->info);
        free(elim);
    }
}
