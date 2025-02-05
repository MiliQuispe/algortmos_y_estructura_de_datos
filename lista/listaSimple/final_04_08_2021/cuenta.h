#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

#define TAM_TIPO_DE_CUENTA 3
#define TAM_APELLIDO 26
#define TAM_LINEA 250

typedef struct
{
    unsigned numeroDeCuenta;
    char tipoDeCuenta[TAM_TIPO_DE_CUENTA];
    char apellido[TAM_APELLIDO];
    unsigned extensionClave;
    float saldo;
}tCuenta;

typedef void (*FormatoEsbribir) (FILE* pf, const void* dato);
typedef void (*FormatoLeer) (const char* linea, const void* dato);

int crearLote();

int crearArchivoTXT(const char* ruta, const void* datos, unsigned tamDato, unsigned ce, FormatoEsbribir formato);

int crearListaOrdenadaConArchivoTXT(const char* ruta, tLista *pl, unsigned tamDato, FormatoLeer formato, Cmp cmp);

int crearArchivoBINConLista(const char* ruta, tLista *pl, Accion guardar);

//
int cmpCuentas (const void* a, const void* b);

void formatoCuentaW (FILE* pf, const void* dato);

void formatoCuentaR (const char* linea, const void* dato);

void mostrarCuenta (void* cond, void* info);

void guardarCuenta (void* cond, void* info);

#endif // CUENTA_H_INCLUDED
