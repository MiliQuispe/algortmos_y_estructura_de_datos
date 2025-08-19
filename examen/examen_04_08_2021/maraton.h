#ifndef MARATON_H_INCLUDED
#define MARATON_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define TAM_APELLIDO 15
#define TAM_NOMBRE 30
#define TAM_LINEA 100
typedef struct
{
    int dni;
    char nombre[TAM_NOMBRE];
    char apell[TAM_APELLIDO];
    float tiempo;
}tParticipante;

typedef void (*FormatoEscribir) (const void* dato, FILE* pf);
typedef void (*FormatoLeer) (const void* dato, FILE* pf);

int crearLote();

int crearArchivoTxtFijo(const char* ruta, const void* datos, unsigned tamDato,int ce,  FormatoEscribir ecribir);

int losNmejoresMaraton(const char* ruta, tLista *pl, int n);

/////////////

void escribirParticipante (const void* dato, FILE* pf);

void leerParticipante (const void* dato, FILE* pf);

int cmpParticipantes (const void* a, const void* b);
void mostrarParticipante (void* info, void *cond);

#endif // MARATON_H_INCLUDED
