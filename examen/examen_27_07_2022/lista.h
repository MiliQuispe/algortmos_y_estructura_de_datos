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
}tNodoLista;
typedef tNodoLista* tLista;

typedef void (*Accion) (void* info, void* cond);

void crearLista(tLista *pl);

int insertarListaAlFinal(tLista*pl, unsigned tamDato, const void* dato);

void mapListaInverso(tLista *pl, void* cond, Accion accion);

void vaciarLista(tLista *pl);


#endif // LISTA_H_INCLUDED
