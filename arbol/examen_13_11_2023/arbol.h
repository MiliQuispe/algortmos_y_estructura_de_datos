#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LOCALIDAD 51
#define MIN(x,y) x<y ? x : y

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *izq, *der;
}tNodo;

typedef tNodo* tArbol;

typedef int (*Cmp) (const void* a, const void* b);
typedef void (*Accion) (void* info, void* cond);
typedef void* (*Buscar) (void* info, void* cond);

void crearArbol(tArbol *pa);

int insertsarOrdenadoNarbol(tArbol *pa, unsigned tamDato, const void* dato,int* ce, int n, Cmp cmp);

int insertsarOrdenadoArbol(tArbol *pa, unsigned tamDato, const void* dato, Cmp cmp);

int eliminarMenor(tArbol *pa, unsigned tamDato, void* dato);

void mapInOrden(tArbol *pa, void* cond, Accion accion);

void* buscarCondicionArbol(const tArbol* pa, void* cond, Buscar buscar);

void vaciarArbol(tArbol *pa);


#endif // ARBOL_H_INCLUDED
