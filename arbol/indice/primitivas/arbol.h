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

typedef int (*Cmp) (const void * a, const void* b);
typedef void (*Accion) (void* info, void* cond, void* parametros);
typedef unsigned (*Leer) (void** info, unsigned pos, void* datos, void* parametros);

void crearArbol(tArbol *pa);

int insertarOrdenadoArbol ( tArbol *pa, unsigned tamDato, const void * dato, Cmp cmp);

int cargarDatosOrdenados(tArbol *pa, int li, int ls, void* datos, void* parametros, Leer leer);

void mapInOrdenArbol(tArbol *pa, void* cond, void* parametros,  Accion accion);

void vaciarArbol(tArbol *pa);


#endif // ARBOL_H_INCLUDED
