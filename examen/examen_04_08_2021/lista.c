#include "lista.h"

void crearLista(tLista *pl)
{
    *pl = NULL;
}

int insertarNordenadoLista(tLista *pl, unsigned tamDato, const void* dato, unsigned* ce, unsigned cMax, Cmp cmp)
{
    tNodo *nue, *aux;
    int i=1;

    while((*pl) && cmp(dato, (*pl)->info)>0)
    {
        i++;
        pl = &(*pl)->sig;
    }

    if(*pl==NULL && *ce>=cMax)
        return 0;

    if(!(nue=malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;

    nue->sig=*pl;
    *pl = nue;
    (*ce)++;

    if(*ce <= cMax)
        return 1;

    aux= (*pl);

    while((*pl)!=NULL &&(i<=cMax || cmp(aux->info,(*pl)->info) ==0) )
    {
        if(cmp(aux->info,(*pl)->info)  !=0)
            aux=*pl;
        i++;
        (pl) = &(*pl)->sig;
    }

    if((*pl)!=NULL  && i>cMax)
    {
        while((*pl) !=NULL)
        {
            aux =(*pl);
            (*pl) = aux->sig;
            free(aux->info);
            free(aux);
        }
        (*pl) = NULL;
        return -1;
    }
    return 1;
}

void mapLista(tLista *pl, void* cond, Accion accion)
{
    while(*pl)
    {
        accion((*pl)->info,cond);
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
