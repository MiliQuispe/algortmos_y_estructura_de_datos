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

typedef void (*Accion) (void* dato, const void* cond);
typedef int (*Cmp) (const void* a, const void* b);

void crearLista (tLista *pl);

int siEsListaLLena(const tLista *pl, unsigned tamDato);

int siEsListaVacia(const tLista *pl);

int ponerXposicionLista(tLista *pl, unsigned tamdato, const void* dato, unsigned pos);
int insertarOrdenadoLista(tLista *pl, unsigned tamdato, const void* dato, Cmp cmp);
int insertarAlComienzoLista(tLista *pl, unsigned tamdato, const void* dato);
int losXmejores(tLista *pl, unsigned tamdato, const void* dato, unsigned ceMax, unsigned *ce, Cmp cmp);

int sacarEnXposicionLista(tLista *pl, unsigned tamdato,void* dato, unsigned pos);
int sacarXvalorLista(tLista *pl, unsigned tamdato, void* dato, Cmp cmp);
int eliminarApariciones(tLista *pl, unsigned tamDato, void* dato, Cmp cmp);


void mapLista(tLista *pl, const void* cond, Accion accion);


void ordenarLista(tLista *pl, Cmp cmp);
tNodo ** buscarMenorLista(tLista *pl, Cmp cmp);
void intercambiarNodos(tNodo** nodo1, tNodo **nodo2);



void vaciarLista(tLista *pl);



#endif // LISTA_H_INCLUDED
