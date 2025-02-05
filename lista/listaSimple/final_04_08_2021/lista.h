#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x<y ? x : Y

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tLista;

typedef int (*Cmp) (const void* a, const void* b);

typedef void (*Accion) (void* cond, void* info);

void crearLista(tLista *pl);

int siEsListaVacia(tLista *pl);

int insertarOrdenado(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp)  ;

void mapLista(tLista *pl, void* cond, Accion accion);

int eliminarUltimosNdelaLista(tLista *pl, int N);

int _eliminarUltimosNdelaLista(tLista *pl, int N, int cn);

void vaciarLista(tLista *pl);

#endif // LISTA_H_INCLUDED
