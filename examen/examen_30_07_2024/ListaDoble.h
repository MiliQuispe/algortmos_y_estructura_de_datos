#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *sig, *ant;
}tNodo;

typedef tNodo* tLista;

typedef int (*Cmp) (const void* a, const void* b);
typedef void (*Accion)(void* info, void* cond);
typedef int (*AcumularDuplicado) (void* info, const void* dato);

void crearListaDoble (tLista *pl);

int insertarOrdenadoListaDoble(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp, AcumularDuplicado duplicado);

void mapListaDoble(tLista *pl, void* cond, Accion accion);

void mapVaciarListaDoble(tLista *pl, void* cond, Accion accion);

#endif // LISTADOBLE_H_INCLUDED
