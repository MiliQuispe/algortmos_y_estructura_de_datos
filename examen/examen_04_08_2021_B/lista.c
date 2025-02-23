#include "lista.h"

void crearLista(tLista *pl)
{
    *pl = NULL;
}

int siEsListaVacia(const tLista *pl)
{
    return *pl ==NULL;
}

int insertarOrdenadoLista(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp)
{
    tNodo *nue;

    while(*pl && cmp(dato,(*pl)->info) >0)
    {
        pl = &(*pl)->sig;
    }

    if(!(nue=malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 1;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo= tamDato;
    nue->sig=*pl;
    *pl = nue;
    return 1;
}

int eliminarPrimeroLista(tLista *pl, unsigned tamDato, void* dato)
{
    tNodo *elim;

    if(*pl ==NULL)
        return 0;

    elim = *pl;
    *pl = elim->sig;

    memcpy(dato, elim->info, MIN(tamDato, elim->tamInfo));
    free(elim->info);
    free(elim);
    return 1;
}

int eliminarUltimoNdeLaLista(tLista *pl, int N)
{
    if(eliminarUltimoNdeLaLista_(pl, N, 1)==-1)
        return 1;
    return 0;
}
int eliminarUltimoNdeLaLista_(tLista *pl, int N, int ce)
{
    tNodo *elim;
    int val;

    if(*pl)
    {
        val= eliminarUltimoNdeLaLista_(&(*pl)->sig, N, ce+1);
        if(val>-1)
        {
            if(val ==0)
                return -1;

            elim = *pl;
            *pl =NULL;
            free(elim->info);
            free(elim);
            return val-1;
        }
        return val;
    }

    if(ce<N)
        return -2;
    return N;
}

void mapLista(tLista *pl, void* cond, Accion accion)
{
    while(*pl)
    {
        accion((*pl)->info, cond);
        pl = &(*pl)->sig;
    }
}

void vaciarLista(tLista *pl)
{
    tNodo *elim;
    while(*pl)
    {
        elim =*pl;
        *pl = elim->sig;

        free(elim->info);
        free(elim);
    }
}
