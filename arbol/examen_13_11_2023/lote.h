#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"


typedef struct
{
    int provincia;
    char localidad[TAM_LOCALIDAD];
    float superficie;
    int habitantes;
}tLote;

typedef struct
{
    int superficie;
    int provincia;
}tSuperficie;

// especifica

int cmpLote (const void* a, const void* b);
int cmpSuperficie (const void* a, const void* b);
void* loteConMenorSuperficie (void* info, void* dato);
void pasarSuperficie (void* info, void* cond);
void mostrarLote (void* info, void* cond);

///ejercicio 1

int crearLOte();

int crearArchBin(const char* ruta, const void* daots, unsigned tamDatos);

int los5MayoresLocalidades(const char* ruta, tArbol* pa);

///ejercicio 2

float menorSuperficie(tArbol* pa, const void* cond);

#endif // LOTE_H_INCLUDED
