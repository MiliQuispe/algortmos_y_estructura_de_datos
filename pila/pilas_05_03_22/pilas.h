#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define TAM_LINEA 15
#define TAMMAX_PILAS 500

typedef struct
{
    int pila;
    int val;
}tRegistro;

typedef void (*Formato) (FILE *pf, void* reg);

//archivoLote

int crearLote();
int crearArchivoTexto(const char* ruta, void* datos, unsigned tamDato, unsigned ce,unsigned cp, Formato formato);
void formatoPilas (FILE *pf, void* reg);

//archivoPilas

int crearPilas(const char* ruta, unsigned tamLinea);
int guardarPila(const char* ruta, tPila *p, unsigned tamDato, Formato formato);

void formatoPilaI (FILE *pf, void* reg);

#endif // PILAS_H_INCLUDED
