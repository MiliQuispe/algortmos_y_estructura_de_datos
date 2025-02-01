#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x<y ? x : y
#define TAM_PILA 150

typedef struct
{
    char pila[TAM_PILA];
    unsigned TAM;
}tPila;

void crearPila(tPila *p);

int siEsPilaLLena(const tPila *p, unsigned cantBytes);
int siEsPilaVacia(const tPila *p);

int ponerEnPila(tPila *p, unsigned tamdato, const void* dato);
int sacarEnPila(tPila *p, unsigned tamdato, void* dato);

void vaciarPila(tPila *p);

int verTope(tPila *p, unsigned tamdato, void* dato);

#endif // PILA_H_INCLUDED
