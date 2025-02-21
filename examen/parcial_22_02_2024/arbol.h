#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
typedef void (*Duplicado) (void* info, void* dato);
//typedef void (*Duplicado) (tArbol *pa, void* info, void* dato);

void crearArbol(tArbol *pa);

int insertarOrdenadoArbol(tArbol *pa, unsigned tamDato, void* dato, Duplicado duplicado, Cmp cmp);

void mapInOrdenArbol(tArbol *pa, void* cond, Accion accion);
void mapInOrdenArbolInverso(tArbol *pa, void* cond, Accion accion);

int alturaArbol(const tArbol *pa);

tNodo** mayorArbol(const tArbol *pa);
tNodo** menorArbol(const tArbol *pa);

int eliminarRaiz(tArbol *pa, unsigned tamDato, void* dato);

void vaciarArbol(tArbol *pa);

#endif // ARBOL_H_INCLUDED
