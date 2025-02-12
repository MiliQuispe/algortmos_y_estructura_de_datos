#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) x<y ? x : y
#define SI_DUPLICADO 1
#define NO_DUPLICADO 0

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo *sig, *ant;
}tNodo;

typedef tNodo* tListaDoble;

typedef int (*Cmp) (const void* a, const void* b);
typedef void (*Accion) (void* info, void* cond);

typedef int (*Filter) (void* info);
typedef void (*Reduce) (void* info, void* cond);

void crearListaDoble(tListaDoble *pl);

int siEsListaDobleLlena(const tListaDoble *pl, unsigned tamDato);

int siEsListaDobleVacia(const tListaDoble *pl);

int insertarOrdenadoListaDoble(tListaDoble *pl, unsigned tamDato, const void* dato, Cmp cmp, int duplicado);

int eliminarValorListaDoble(tListaDoble *pl, unsigned tamDato, void* dato, Cmp cmp);

void mapListaDobleA(tListaDoble *pl, void* cond, Accion accion);
void mapListaDobleD(tListaDoble *pl, void* cond, Accion accion);

void filterListDoble(tListaDoble *pl, Filter filter);

void reduceListDoble(tListaDoble *pl, Reduce reduce);

void ordenarListaDoble(tListaDoble *pl, Cmp cmp);

void vaciarListaDoble(tListaDoble *pl);

#endif // LISTADOBLE_H_INCLUDED
