#ifndef POLINOMIOS_H_INCLUDED
#define POLINOMIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDoble.h"

#define TAM_LINEA 15

typedef struct
{
    int potencia;
    int coeficiente;
}tTermino;

typedef void (*FormatoEscribir) (const void* info, FILE* pf);

int crearLote();

int crearArchivoTXT(const char* ruta, const void* datos, unsigned tamDato, int ce, FormatoEscribir escribir);

int sumarPolinomiosTXT(const char* rutaP1, const char* rutaP2, const char* rutaPr);

int guardarListaDobleOrdenadaTXT(const char* ruta, tLista *pl, Accion accion);

////////

void escribirTermino (const void* info, FILE* pf);

int cmpTermino (const void* a, const void* b);

void grabarTermino(void* info, void* cond);

void mostrarTermino(void* info, void* cond);

int acumularTermino(void* info, const void* dato);


#endif // POLINOMIOS_H_INCLUDED
