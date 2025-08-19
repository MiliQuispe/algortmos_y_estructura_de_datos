#include "pilaD.h"

void crearPilaD(tPilaD *p)
{
    *p = NULL;
}

int siEsPilaDvacia(const tPilaD *p)
{
    return *p ==NULL;
}

int ponerEnPilaD(tPilaD *p, unsigned tamDato, const void* dato)
{
    tNodo *nue;

    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int sacarEnPilaD(tPilaD *p, unsigned tamDato, void* dato)
{
    tNodo *elim;

    if(*p ==NULL)
        return 0;

    elim = *p;
    *p = elim->sig;

    memcpy(dato, elim->info, MIN(elim->tamInfo, tamDato));
    free(elim->info);
    free(elim);
    return 1;
}

void vaciarPilaD(tPilaD *p)
{
    tNodo *elim;

    while(*p)
    {
        elim = *p;
        *p = elim->sig;

        free(elim->info);
        free(elim);
    }
}
