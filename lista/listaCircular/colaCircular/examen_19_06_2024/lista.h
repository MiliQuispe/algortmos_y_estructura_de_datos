#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

typedef tNodo* tLista;

typedef int (*Cmp) (const void* a, const void* b);

void crearLista(tLista *pl);

int siEsListaVacia(const tLista *pl);

int insertarOrdenadoLista(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp);

int eliminarPrimeroLista(tLista *pl, unsigned tamDato, void* dato);


#endif // LISTA_H_INCLUDED
