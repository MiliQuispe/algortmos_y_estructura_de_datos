#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x<y ? x : y

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;
typedef tNodo* tLista;

typedef int (*Cmp) (const void* a, const void* b);
typedef void (*Accion) (void* info, void* cond);

void crearLista(tLista *pl);

int siEsListaVacia(const tLista *pl);

int insertarOrdenadoLista(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp);

int eliminarPrimeroLista(tLista *pl, unsigned tamDato, void* dato);

int eliminarUltimoNdeLaLista(tLista *pl, int N);
int eliminarUltimoNdeLaLista_(tLista *pl, int N, int ce);

void mapLista(tLista *pl, void* cond, Accion accion);

void vaciarLista(tLista *pl);

#endif // LISTA_H_INCLUDED
