#include "pila.h"

void crearPila(tPila *p)
{
    p->TAM = TAM_PILA;
}

int siEsPilaLLena(const tPila *p, unsigned cantBytes)
{
    return p->TAM < (cantBytes + sizeof (unsigned));
}
int siEsPilaVacia(const tPila *p)
{
    return p->TAM == TAM_PILA;
}

int ponerEnPila(tPila *p, unsigned tamDato, const void* dato)
{
    if(p->TAM < (tamDato + sizeof (unsigned)))
        return 0;

    memcpy(p->pila + (p->TAM - tamDato), dato, tamDato);
    memcpy(p->pila + (p->TAM - tamDato- sizeof(unsigned)), &tamDato, sizeof(unsigned));
    p->TAM-= tamDato +  sizeof(unsigned);
    return 1;

}
int sacarEnPila(tPila *p, unsigned tamDato, void* dato)
{
    unsigned cantBytes;

    if(p->TAM == TAM_PILA)
        return 0;

    memcpy(&cantBytes ,p->pila+p->TAM, sizeof(unsigned));
    memcpy(dato, p->pila + (p->TAM + cantBytes), MIN(cantBytes, tamDato));
    p->TAM += cantBytes + sizeof(unsigned);
    return 1;
}

void vaciarPila(tPila *p)
{
    p->TAM = TAM_PILA;
}

int verTope(tPila *p, unsigned tamDato, void* dato)
{
    unsigned cantBytes;

    if(p->TAM == TAM_PILA)
        return 0;

    memcpy(&cantBytes ,p->pila+p->TAM, sizeof(unsigned));
    memcpy(dato, p->pila + (p->TAM + cantBytes), MIN(cantBytes, tamDato));
    return 1;
}
