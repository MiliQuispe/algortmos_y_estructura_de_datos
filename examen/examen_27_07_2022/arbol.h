#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x<y ? x : y

typedef struct sNodoArbol
{
    void* info;
    unsigned tamInfo;
    struct sNodoArbol *izq, *der;
}tNodoArbol;

typedef tNodoArbol* tArbol;

typedef int (*Cmp) (const void* a, const void* b);
typedef void (*Accion) (void* info, void* cond);
typedef int (*Leer) (void** info, void* parametros,unsigned pos, void* datos);

void crearArbol(tArbol *pa);

int insertarOrdenadoArbol(tArbol *pa, unsigned tamDato, const void* dato, Cmp cmp);

int cargarDatosOrdenados(tArbol *pa, void* datos, int li, int ls, void* parametros, Leer leer);

void mapInOrdenArbol(tArbol *pa, void* cond, Accion accion);

void vaciarArbol(tArbol *pa);

#endif // ARBOL_H_INCLUDED
