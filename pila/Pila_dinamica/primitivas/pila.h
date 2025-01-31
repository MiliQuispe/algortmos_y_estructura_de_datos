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

void crearPila(tPila *p);

int siEsPilaVacia(const tPila *p);
int siEsPilaLLlena (const tPila *p , unsigned cantBytes);

int ponerEnPila(tPila* p, unsigned cantBytes, const void* dato);
int sacarEnPila(tPila* p, unsigned cantBytes, void* dato);

void vaciarPila(tPila *p);

int verTope(tPila *p, unsigned cantBytes, void* dato);

#endif // PILA_H_INCLUDED
