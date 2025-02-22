#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "arbol.h"

#define TAM_CODIGO 6

typedef struct
{
    char cod[TAM_CODIGO];
    char tipo;
    int stock;
}tProducto;

typedef struct
{
    char cod[TAM_CODIGO];
    char tipo;
    unsigned pos;
}tIndiceProducto;

typedef void (*Indice) (const void* info, void* dato, unsigned pos);

void itemA();
void mostrarMayoesDe3 (void* info, void* cond);

///

void itemB();

int crearLote();
int crearArchivoBinario(const char* ruta, const void* datos, unsigned tamDatos);

int cargarArbol(const char* ruta, tArbol *pa, unsigned tamDato, unsigned tamInfo, Cmp cmp, Indice indice);
int crearArchivoIndice(const char* ruta, const tArbol* pa, Accion cargarDato);
int cargarIndice(const char* ruta, tArbol *pa, unsigned tamReg, Leer leer);

void indiceProducto (const void* info, void* dato, unsigned pos);
int cmpIndiceProducto (const void* a, const void* b);
void escribirIndice (void* info, void* cond);
void mostrarIndice (void* info, void* cond);
void mostrarProductto (void* info, void* cond);
int leerIndiceProducto (void** info, void* parametros,unsigned pos, void* datos);

#endif // ITEM_H_INCLUDED
