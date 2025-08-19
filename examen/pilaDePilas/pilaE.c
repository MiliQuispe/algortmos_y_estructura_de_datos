#include "pilaE.h"

void crearPilaE(tPilaE *p)
{
    p->tam = TAM_PILA;
}

int siEsPilaEvacia(const tPilaE *p)
{
    return p->tam == TAM_PILA;
}

int siEsPilaEllena(const tPilaE *p, unsigned tamDato)
{
    return p->tam < (tamDato + sizeof(unsigned));
}

int ponerEnPilaE(tPilaE *p, unsigned tamDato, const void* dato)
{
    if(p->tam < (tamDato + sizeof(unsigned)))
        return 0;

    memcpy(p->pila + (p->tam - tamDato), dato, tamDato);
    memcpy(p->pila + (p->tam - tamDato - sizeof(unsigned)), &tamDato, sizeof(unsigned));
    p->tam -= tamDato + sizeof(unsigned);

    return 1;
}

int sacarEnPilaE(tPilaE *p, unsigned tamDato, void* dato)
{
    unsigned tamInfo;

    if(p->tam == TAM_PILA)
        return 0;

    memcpy(&tamInfo, p->pila + (p->tam), sizeof(unsigned));
    memcpy(dato,  p->pila + (p->tam + sizeof(unsigned)), MIN(tamInfo, tamDato));
    p->tam +=tamInfo+ sizeof(unsigned);
    return 1;
}

void vaciarPilaE(tPilaE *p)
{
    p->tam = TAM_PILA;
}
