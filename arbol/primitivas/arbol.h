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
typedef void (*Accion) (void* info, const void* cond);

void crearArbol(tArbol *pa);

int siEsArbolBinarioVacio(const tArbol *pa);

int siEsArbolBinarioLleno(const tArbol *pa, unsigned tamDato);

int insertarOrdenadoaArbolBinario(tArbol *pa, unsigned tamDato, const void* dato,Cmp cmp);

void mapPreOrden(tArbol *pa, const void* cond, Accion accion);

void mapInOrden(tArbol *pa, const void* cond, Accion accion);

void mapPosOrden(tArbol *pa, const void* cond, Accion accion);

int eliminarRaiz(tArbol *pa);

int alturaDelArbol(const tArbol *pa);

tNodo** mayorDelArbol(const tArbol *pa);

tNodo** menorDelArbol(const tArbol *pa);

tNodo** buscarArbolBinario(const tArbol *pa, const void* dato, Cmp cmp);

void vaciarArbol(tArbol *pa);

#endif // ARBOL_H_INCLUDED
