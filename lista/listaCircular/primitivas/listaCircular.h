#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

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

typedef tNodo* tListaCircular;

typedef int (*Cmp) (const void* a, const void* b);
typedef void (*Accion) (void* dato, void* cond);

void crearListaCircular (tListaCircular *pl);

int siEsListaCircularLlena(const tListaCircular *pl, unsigned tamDato);
int siEsListaCircularVacia(const tListaCircular *pl);

int insertarOrdenadoListaCircular (tListaCircular *pl, unsigned tamDato, const void* dato, Cmp cmp);

int eliminarXvalorListaCircular (tListaCircular *pl, unsigned tamDato, void* dato, Cmp cmp);

void mapListaCircular (tListaCircular *pl, void* cond, Accion accion);

void vaciarListaCircular(tListaCircular *pl);



#endif // LISTACIRCULAR_H_INCLUDED
