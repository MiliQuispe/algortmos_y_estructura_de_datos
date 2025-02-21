#include "lista.h"

void crearLista(tLista *pl)
{
    *pl =NULL;
}

int siEsListaVacia(tLista *pl)
{
    return *pl == NULL;
}

int insertarOrdenado(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp)
{
    tNodo *nue;

    while(*pl && cmp((*pl)->info, dato) <0)
    {
        pl = &(*pl)->sig;
    }

    if(*pl && cmp((*pl)->info, dato) ==0)
        return 2;

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

int eliminarUltimosNdelaLista(tLista *pl, int N)
{
    if( _eliminarUltimosNdelaLista(pl, N, 0) == -2)
        return 1;
    return 0;
}

int _eliminarUltimosNdelaLista(tLista *pl, int N, int cn)
{
    tNodo *elim;

    int aux;
    if(*pl)
    {
        aux= _eliminarUltimosNdelaLista(&(*pl)->sig, N , cn+1);
        if(aux>=0)
        {
            if(aux==0)
                return -2;

            elim = *pl;
            *pl= NULL;
            free(elim->info);
            free(elim);
            return aux-1;
        }
        else
            return aux;
    }

    if(cn ==1 || cn<N)
        return -1;
    else
        return N;
}

void mapLista(tLista *pl, void* cond, Accion accion)
{
    while(*pl)
    {
        accion(cond, (*pl)->info);
        pl = &(*pl)->sig;
    }
}

void vaciarLista(tLista *pl)
{
    tNodo *elim;

    while(*pl)
    {
        elim = *pl;
        *pl = elim->sig;
        free(elim->info);
        free(elim);
    }
}
