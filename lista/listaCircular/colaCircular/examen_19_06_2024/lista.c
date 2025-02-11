#include "lista.h"

void crearLista(tLista *pl)
{
    *pl = NULL;
}

int insertarOrdenadoLista(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp)
{
    tNodo *nue;

    while(*pl && cmp(dato, (*pl)->info)>0)
    {
        pl = &(*pl)->sig;
    }

    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = *pl;
    *pl = nue;
    return 1;
}

int siEsListaVacia(const tLista *pl)
{
    return *pl ==NULL;
}

int eliminarPrimeroLista(tLista *pl, unsigned tamDato, void* dato)
{
    tNodo *elim;

    if(*pl ==NULL)
        return 0;

    elim = (*pl);
    memcpy(dato, elim->info, MIN(tamDato, elim->tamInfo));

    *pl = elim->sig;
    free(elim->info);
    free(elim);
    return 1;
}
