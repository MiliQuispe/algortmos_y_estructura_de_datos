#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

#define MIN(x,y) x<y ? x : y


typedef struct
{
    tNodo *pri, *ult;
}tCola;

void crearCola(tCola *pc);

int siEsColaLlena(const tCola *pc, unsigned tamDato);
int siEsColaVacia(const tCola *pc);

int ponerEnCola (tCola *pc, unsigned tamDato, const void* dato);
int sacarEnCola (tCola *pc, unsigned tamDato, void* dato);

void vaciarCola(tCola *pc);

int verPrimero (tCola *pc, unsigned tamDato, void* dato);

#endif // COLA_H_INCLUDED
