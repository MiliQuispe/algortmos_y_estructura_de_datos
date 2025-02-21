#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

#define TAM_LINEA 1024
#define TAM_PALABRA 30
#define ES_LETRA(x) ( (x <= 'z' && x >= 'a') || (x <= 'Z' && x >= 'A') )
#define ES_MINUSCULA(x) (x <= 'z' && x >= 'a')
#define ES_MAYUSCULA(x) (x <= 'Z' && x >= 'A')
#define A_MINUSCULA(x) ( x + 32 )
#define A_MAYUSCULA(x) ( x - 32 )

typedef struct
{
    char palabra[TAM_PALABRA];
    int cantApariciones;
}tPalabra;

///////

int menu();

///////////////

int proximaPalabraProcesada(char* linea, char ** ini);

int procesarPalabra(char* palabra, int ce);

int procesarLibro(const char* ruta, tArbol *pa, tPalabra* mayor);

////////////

int cmpPalabra (const void* a, const void* b);

void mostrarPalabra (void* info, void* cond);

void menorPalabra (void* info, void* cond);

void duplicadoPalabra (void* info, void* dato);
//void duplicadoPalabra (tArbol *pa, void* info, void* dato);


#endif // LIBRO_H_INCLUDED
