#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *izq, *der;
}tNodo;

typedef tNodo* tArbol;

typedef int (*Cmp) (const void* a, const void* b);
typedef void (*Accion) (void* info, void* cond);
typedef int (*Leer) (void** info, unsigned pos, void* parametros, void* datos);

void crearArbol (tArbol *pa);

int insertarArbol(tArbol *pa, unsigned tamDato, void* datom, Cmp cmp);

int eliminarRaiz(tArbol *pa);

int cargarDatosOrdenadosArbol(tArbol *pa, int li, int ls, void* datos, void* parametros, Leer leer);

int altura(tArbol *pa);

tNodo ** mayorNodo(tArbol *pa);
tNodo ** menorNodo(tArbol *pa);

void mapInOrdenArbol(tArbol *pa, void* cond, Accion);

void vaciarArbol(tArbol *pa);


#endif // ARBOL_H_INCLUDED
