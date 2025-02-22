#ifndef PILAD_H_INCLUDED
#define PILAD_H_INCLUDED

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

typedef tNodo* tPilaD;

void crearPilaD(tPilaD *p);

int siEsPilaDvacia(const tPilaD *p);

int ponerEnPilaD(tPilaD *p, unsigned tamDato, const void* dato);

int sacarEnPilaD(tPilaD *p, unsigned tamDato, void* dato);

void vaciarPilaD(tPilaD *p);

#endif // PILAD_H_INCLUDED
