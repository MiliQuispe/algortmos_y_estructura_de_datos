#include "lista.h"

void crearLista(tLista *pl)
{
    *pl = NULL;
}

int insertarListaAlFinal(tLista*pl, unsigned tamDato,const void* dato)
{
    tNodoLista *nue;

    while(*pl)
    {
        pl = & (*pl)->sig;
    }

    if(!(nue= malloc(sizeof(tNodoLista))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo= tamDato;
    nue->sig= NULL;
    *pl = nue;
    return 1;
}

void mapListaInverso(tLista *pl, void* cond, Accion accion)
{
    if(*pl)
    {
        mapListaInverso(& (*pl)->sig, cond,accion);
        accion((*pl)->info, cond);
    }
}

void vaciarLista(tLista *pl)
{
    tNodoLista *elim;

    while(*pl)
    {
        elim = *pl;
        *pl = elim->sig;
        free(elim->info);
        free(elim);
    }
}
