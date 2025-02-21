#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x<y ? x : y
#define TAM_COLA 1024

typedef struct
{
    char cola[TAM_COLA];
    unsigned tamInfo, pri, ult;
}tCola;

void crearCola(tCola *pc);

int siEsColaLLena(const tCola *pc, unsigned tamDato);
int siEsColaVacia(const tCola *pc);

int ponerEnCola(tCola *pc, unsigned tamDato, const void* dato);

int sacarEnCola(tCola *pc, unsigned tamDato, void* dato);

void vaciarCola(tCola *pc);

#endif // COLA_H_INCLUDED
