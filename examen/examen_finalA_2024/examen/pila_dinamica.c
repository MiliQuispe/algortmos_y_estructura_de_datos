
#include "../include/pila_dinamica.h"


void crearPila( tPila* pp )
{
    *pp=NULL;
}

int apilar( tPila* pp, const void* pd, unsigned tam )
{
    tNodo *nue;

    if(!(nue=malloc(sizeof(tNodo))) || !(nue->info = malloc(tam)))
    {
        free(nue);
        return NO_PUDE_APILAR;
    }
    memcpy(nue->info, pd, tam);
    nue->tamInfo=tam;
    nue->sig = *pp;
    *pp=nue;
    return OK;
}

int desapilar( tPila* pp, void* pd, unsigned tam )
{
    tNodo *elim;

    if(*pp ==NULL)
        return NO_PUDE_DESAPILAR;

    elim=*pp;
    memcpy(pd, elim->info, MINIMO(tam, elim->tamInfo));
    *pp = elim->sig;
    free(elim->info);
    free(elim);
    return OK;
}

int pilaVacia( const tPila* pp )
{
    return *pp==NULL;
}

void vaciarPila( tPila* pp )
{
    tNodo *elim;

    while(*pp)
    {
        elim=*pp;
        *pp = elim->sig;
        free(elim->info);
        free(elim);
    }
}
