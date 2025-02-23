#ifndef CUENTAS_H_INCLUDED
#define CUENTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define TAM_TIPOCUENTA 3
#define TAM_APELLIDO 26
#define TAM_LINEA 100


typedef struct
{
    unsigned nroCuenta;
    char tipoCuenta[TAM_TIPOCUENTA];
    char apellido[TAM_APELLIDO];
    unsigned extClave;
    float saldo;
}tCuenta;

typedef void (*FormatoEscribir) (const void* dato, FILE* pf);
typedef void (*FormatoLeer) (const char* linea, void* dato);

int crearLote();

int crearArchivoTxt(const char* ruta, const void* datos, unsigned tamDato, int ce, FormatoEscribir escribir);

int cargarListaArchivoTxt(const char* ruta, tLista *pl, unsigned tamDato, Cmp cmp, FormatoLeer leer);

int guardarListaArchivoBin(const char* ruta, tLista *pl, unsigned tamInfo);

//////////////

void escribirCuenta (const void* dato, FILE* pf);

void leerCuenta (const char* linea, void* dato);

int cmpCuenta (const void* a, const void* b);

void mostrarCuenta (void* info, void* cond);

#endif // CUENTAS_H_INCLUDED
