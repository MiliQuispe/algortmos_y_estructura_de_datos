#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


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

typedef tNodo* tPila;

void crearPila (tPila *p);

int siEsPilaLLena(const tPila *p, unsigned tamDato);
int siEsPilaVacia (const tPila *p);

int ponerEnPila(tPila *p, unsigned tamDato, const void* dato);
int sacarEnPila(tPila *p, unsigned tamDato, void* dato);

void vaciarPila(tPila *p);

int verTope(tPila *p, unsigned tamDato, void* dato);

#endif // PILA_H_INCLUDED
