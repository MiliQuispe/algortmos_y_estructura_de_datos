#ifndef PILAE_H_INCLUDED
#define PILAE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 150
#define MIN(x,y) x<y ? x : y

typedef struct
{
    char pila[TAM_PILA];
    unsigned tam;
}tPilaE;

void crearPilaE(tPilaE *p);

int siEsPilaEvacia(const tPilaE *p);

int siEsPilaEllena(const tPilaE *p, unsigned tamDato);

int ponerEnPilaE(tPilaE *p, unsigned tamDato, const void* dato);

int sacarEnPilaE(tPilaE *p, unsigned tamDato, void* dato);

void vaciarPilaE(tPilaE *p);

#endif // PILAE_H_INCLUDED
