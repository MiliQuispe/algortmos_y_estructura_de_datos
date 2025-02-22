#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tLista;
typedef int (*Cmp) (const void* a, const void* b);
typedef void (*Accion) (void* info, void *cond);

void crearLista(tLista *pl);

int insertarNordenadoLista(tLista *pl, unsigned tamDato, const void* dato, unsigned* ce, unsigned cMax, Cmp cmp);

void mapLista(tLista *pl, void* cond, Accion accion);

void vaciarLista(tLista *pl);

#endif // LISTA_H_INCLUDED
