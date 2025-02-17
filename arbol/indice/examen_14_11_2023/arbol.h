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
typedef unsigned (*Leer) (void** info, unsigned pos, void* datos, void* parametros);

void crearArbol(tArbol *pa);

int siesArbolvacio(const tArbol* pa);

int insertarOrdenadoArbol(tArbol *pa, unsigned tamDato, void* dato, Cmp cmp);

int alturaArbol(const tArbol *pa);

tNodo** mayorHijoArbol(const tArbol *pa);

tNodo** menorHijoArbol(const tArbol *pa);

tNodo** buscarNodoArbol(const tArbol *pa, const void* dato, Cmp cmp);

int eliminarRaizArbol(tArbol *pa, unsigned tamdato, void* dato);

int cargarArbolIdx (tArbol *paIdx, int li, int ls, void* datos, void* parametros, Leer leer);

void mapInOrden(tArbol *pa, void* cond, Accion accion);

void vaciarArbol(tArbol *pa);

#endif // ARBOL_H_INCLUDED
