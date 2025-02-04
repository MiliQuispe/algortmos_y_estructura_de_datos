#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cola.h"
#define TAM_ART 7
#define TAM_MAT 7
#define TAM_NOMBRE_ARCHIVO 30

typedef struct
{
    char codArt[TAM_ART];
    char codMat[TAM_MAT];
    int cantidad;
    float costoU;
}tArticulo;


void prueba();

// crear lote

int crearLote();

int crearArchivoBin (const char* ruta, const void* datos, unsigned tamDatos);

int verArchivoArticulo(const char* ruta);

// separar articulos

int crearArchivos(const char* ruta, float limite);

#endif // ARTICULOS_H_INCLUDED
