#include "cola.h"

void crearCola(tCola *pc)
{
    pc->pri = NULL;
    pc->ult = NULL;
}

int siEsColaLlena(const tCola *pc, unsigned tamDato)
{
    return 0;
}
int siEsColaVacia(const tCola *pc)
{
    return pc->pri == NULL;
}

int ponerEnCola (tCola *pc, unsigned tamDato, const void* dato)
{
    tNodo *nue;

    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = NULL;

    if(pc->pri ==NULL)
    {
        pc->pri = nue;
    }
    else
    {
        pc->ult->sig = nue;
    }

    pc->ult = nue;
    return 1;
}
int sacarEnCola (tCola *pc, unsigned tamDato, void* dato)
{
    tNodo *elim;

    if(pc->pri == NULL)
        return 0;

    elim = pc->pri;
    pc->pri = elim->sig;
    memcpy(dato,elim->info, MIN(tamDato,elim->tamInfo));

    free(elim->info);
    free(elim);
    return 1;
}

void vaciarCola(tCola *pc)
{
    tNodo *elim;

    while(pc->pri != NULL)
    {
        elim = pc->pri;
        pc->pri = elim->sig;

        free(elim->info);
        free(elim);
    }

    pc->ult =NULL;
}

int verPrimero (tCola *pc, unsigned tamDato, void* dato)
{
    tNodo *ver;

    if(pc->pri == NULL)
        return 0;

    ver = pc->pri;
    memcpy(dato, ver->info, MIN(tamDato, ver->tamInfo));
    return 1;
}
