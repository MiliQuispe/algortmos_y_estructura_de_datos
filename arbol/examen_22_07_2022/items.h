#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "arbol.h"

#define TAM_COD 6

typedef struct
{
    char cod[TAM_COD];
    char sector;
    int cant;
}tPedido;

/// item A

int pruebaItemA ();


/// item B

int crearLote();

int crearArchivoBinario(const char *ruta, const void* dato, unsigned tamdatos);

int cargarListaDobleArchiBin (const char* ruta, tLista *pl, unsigned tamDato);

int listaXpedidos(tLista *pl);

int guardarListaDobleArchTXT (const char* ruta, tLista *pl, Accion accion);

int cmpPedidos (const void* a, const void* b);
int cmpCantidad(const void* a, const void* b);
void duplicadosPedidos (void* info, const void *dato);
void mostrarYgrabarPedidos (void* info, void* cond);
void mostrarPedidos (void* info, void* cond);
void reduciApedidos (void* info, void* cond);

int pruebaItemB ();


#endif // ITEMS_H_INCLUDED
