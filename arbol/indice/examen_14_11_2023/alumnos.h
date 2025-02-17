#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

#define TAM_NOMBRE 30
#define TAM_APELLIDO 15

typedef struct
{
    char nombre[TAM_NOMBRE];
    char apellido[TAM_APELLIDO];
    unsigned dni;
    char estado;
}tAlumnos;

typedef struct
{
    unsigned dni;
    unsigned pos;
}tDni;

typedef void (* ExtraerIndice) (void* registro, tArbol *pa, unsigned pos);

// especifoco
//
//int (*Cmp) (const void* a, const void* b);
//void (*Accion) (void* info, void* cond);

void mostrarIndice (void* info, void* cond);

/// lote

int crearLote();

int crearArchivoBin(const char* rutaDat, const void* datos, unsigned tamDatos);

///indice

void extraeDni (void* registro, tArbol *pa, unsigned pos);

int cmpDni (const void* a, const void* b);

void escribirArchivoAlumnosIdx (void* info, void* cond);


unsigned leerArchivoIdx (void** info, unsigned pos, void* datos, void* parametros);


int cargarArbol_archBin(const char* rutaDat, tArbol *pa, unsigned tamDato, ExtraerIndice extraer); // no balanceado

int cargarArchivoIDX_arbol (const char* rutaIdx, tArbol *pa, Accion escribir); // cargar el arbol no balanceado en un archivo ordenado

int cargarArbol_archIdx (const char* rutaIdx, tArbol *paIdx, unsigned tam, Leer leer); // cargar el arbol de forma balanceada

/// menu
int altasYbajasDeLosAlumnos(const char* rutaDat);

/// opcion 1

int bajaAlumnos (const char* rutaDat, tArbol *paIdx);

int actualizarBaja (const char* rutaDat, unsigned pos);

// eliminar en el indice ya en arbol.h

///opcion 2

int guardarIndice(const char* rutaIdx, const tArbol *paIdx, Accion accion);

/// opcion 3

//vaciar arbol en arbol.h


#endif // ALUMNOS_H_INCLUDED
