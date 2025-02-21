#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodoArbol
{
    void* info;
    unsigned tamInfo;
    struct sNodoArbol *izq, *der;
}tNodoArbol;

typedef tNodoArbol* tArbol;

typedef int (*Cmp) (const void* a, const void* b);
typedef  void (*Accion) (void* info, void* cond);


void crearArbol(tArbol *pa);

int insertarOdenadoArbolBinarioDeBusqueda(tArbol *pa, unsigned tamInfo, const void* dato, Cmp cmp);

void mapNivelArbolBinarioDeBusqueda(tArbol *pa, void* cond, int nivel, Accion accion);

void vaciarArbolBinarioDeBusqueda(tArbol* pa);


#endif // ARBOL_H_INCLUDED
