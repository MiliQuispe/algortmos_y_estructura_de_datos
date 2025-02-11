#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x<y ? x : y

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tCola;

void crearCola(tCola *pc);

int siEsColaLlena(const tCola *pc, unsigned tamDato);
int siEsColaVacia(const tCola *pc);

int insertarEnCola (tCola *pc, unsigned tamDato, const void* dato);

int sacarDeCola (tCola *pc, unsigned tamDato, void* dato);

void vaciarCola(tCola *pc);

#endif // COLA_H_INCLUDED
