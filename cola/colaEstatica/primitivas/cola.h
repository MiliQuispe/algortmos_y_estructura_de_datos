#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_COLA 100
#define MIN(x,y) x<y ? x : y

typedef struct
{
    char cola[TAM_COLA];
    unsigned tamInfo, pri, ult;
}tCola;

void crearCola(tCola *pc);

int siEsColaVacia(const tCola *pc);
int siEsColaLLena(const tCola *pc, unsigned tamDato);

int ponerEnCola(tCola *pc, unsigned tamDato, const void* dato);

int sacarEnCola(tCola *pc, unsigned tamDato, void* dato);

void vaciarCola(tCola *pc);

int verPrimero(tCola *pc, unsigned tamDato, void* dato);


#endif // COLA_H_INCLUDED
