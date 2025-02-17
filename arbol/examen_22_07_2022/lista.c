#include "lista.h"


void crearListaDoblementeEnlazada(tLista *pl)
{
    *pl = NULL;
}

int insertarAlfinalListaDoblementeEnlazada(tLista *pl, unsigned tamDato, const void* dato)
{
    tNodoLista *nue;

    while(*pl && (*pl)->sig !=NULL)
    {
        pl = &(*pl)->sig;
    }

    if(!(nue= malloc(sizeof(tNodoLista))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = NULL;
    nue->ant = *pl;
    *pl = nue;
    return 1;
}

int insertarAlfinalListaDoblementeEnlazadaNoDuplicado(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp, Actualizar actualizar)
{
    tNodoLista *nue,  *actual;

    if(*pl)
    {
        actual= *pl;
        while(actual->ant !=NULL && cmp(dato, actual->info) !=0)
        {
           actual = actual->ant;
        }

        if(cmp(dato, actual->info) !=0)
        {
            actual = (*pl)->sig;
        }

        while(actual !=NULL && actual->sig !=NULL && cmp(dato, actual->info) !=0)
        {
            actual = actual->sig;
        }

        if(actual !=NULL && cmp(dato, actual->info) ==0)
        {
            actualizar(actual->info, dato);
            return 2;
        }
    }

    if(!(nue= malloc(sizeof(tNodoLista))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = NULL;
    nue->ant = *pl;
    *pl = nue;
    return 1;
}

void mapListaDoblementeEnlazadaD (tLista *pl, void* cond, Accion accion)
{
    if(*pl)
    {
        while((*pl)->sig !=NULL)
        {
            pl = &(*pl)->sig;
        }

        while(*pl)
        {
            accion((*pl)->info, cond);

            pl = &(*pl)->ant;
        }
    }
}

void VaciarListaDoblementeEnlazada(tLista *pl)
{
    tNodoLista *elim;
    if(*pl)
    {
        while((*pl)->sig !=NULL)
        {
            pl = &(*pl)->sig;
        }

        while(*pl)
        {
            elim = *pl;
            *pl = elim->ant;

            free(elim->info);
            free(elim);
        }
    }
}

void mapVaciarListaDoblementeEnlazadaD(tLista *pl, const void* cond, Accion accion)
{
    tNodoLista *elim;
    if(*pl)
    {
        while((*pl)->sig !=NULL)
        {
            pl = &(*pl)->sig;
        }

        while(*pl)
        {
            accion((*pl)->info,(void*) cond);

            elim = *pl;
            *pl = elim->ant;

            free(elim->info);
            free(elim);
        }
    }

}
