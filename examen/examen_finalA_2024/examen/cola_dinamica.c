#include "../include/cola_dinamica.h"

void crearCola(tCola* pc)
{
    pc->pri=NULL;
    pc->ult=NULL;
}

int poner_en_cola(tCola * pc, const void * pd, unsigned tam)
{
    tNodo *nue;

    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tam)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, pd, tam);
    nue->tamInfo = tam;
    nue->sig = NULL;

    if(pc->pri ==NULL)
        pc->pri = nue;

    if(pc->ult !=NULL)
        pc->ult->sig = nue;

    pc->ult = nue;
    return 1;
}

int sacar_de_cola(tCola * pc, void * pd, unsigned tam)
{
    tNodo *elim;

    if(pc->pri ==NULL)
        return 0;

    elim=pc->pri;
    memcpy(pd, elim->info, MINIMO(tam,elim->tamInfo));

    pc->pri= elim->sig;
    free(elim->info);
    free(elim);
    return 1;
}

int cola_llena(const tCola * pc, unsigned tam)
{
    return 0;
}

int colaVacia(const tCola* pc)
{
    return pc->pri ==NULL;
}

void vaciar_cola(tCola * pc)
{
    tNodo *elim;

    while(pc->pri!=NULL)
    {
        elim=pc->pri;
        pc->pri= elim->sig;
        free(elim->info);
        free(elim);
    }
}
