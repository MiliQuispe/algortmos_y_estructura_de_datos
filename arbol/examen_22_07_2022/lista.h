#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodoLista
{
    void* info;
    unsigned tamInfo;
    struct sNodoLista *sig, *ant;
}tNodoLista;

typedef tNodoLista* tLista;

typedef int (*Cmp) (const void* a, const void* b);
typedef  void (*Actualizar) (void* info, const void *dato);
typedef  void (*Accion) (void* info,  void* cond);

void crearListaDoblementeEnlazada(tLista *pl);

int insertarAlfinalListaDoblementeEnlazada(tLista *pl, unsigned tamDato, const void* dato);

int insertarAlfinalListaDoblementeEnlazadaNoDuplicado(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp, Actualizar actualizar);

void mapListaDoblementeEnlazadaD (tLista *pl, void* cond, Accion accion);

void mapVaciarListaDoblementeEnlazadaD(tLista *pl, const void* cond, Accion accion);


void VaciarListaDoblementeEnlazada(tLista *pl);


#endif // LISTA_H_INCLUDED
