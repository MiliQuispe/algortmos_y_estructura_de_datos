// Apellido, Nombres: Cancian, Facundo Leonel
//
// DNI: 42290675
#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef OK
    #define OK 1
#endif // OK
#ifndef MINIMO
#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))
#endif // MINIMO

#ifndef T_NODO
#define T_NODO
typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;
#endif // T_NODO

typedef struct
{
    tNodo * pri;
    tNodo * ult;
}tCola;

void crearCola(tCola* pc);

int poner_en_cola(tCola * pc, const void * pd, unsigned tam);
int sacar_de_cola(tCola * pc, void * pd, unsigned tam);

int ver_pri_de_cola(const tCola * pc, void * pd, unsigned tam);

int cola_llena(const tCola * pc, unsigned tam);
int colaVacia(const tCola* pc);

void vaciar_cola(tCola * pc);

/// Resueltas
void crear_cola_res(tCola * pc);

int poner_en_cola_res(tCola * pc, const void * pd, unsigned tam);
int sacar_de_cola_res(tCola * pc, void * pd, unsigned tam);

int ver_pri_de_cola_res(const tCola * pc, void * pd, unsigned tam);

int cola_llena_res(const tCola * pc, unsigned tam);
int cola_vacia_res(const tCola * pc);

void vaciar_cola_res(tCola * pc);

#endif // COLA_DINAMICA_H_INCLUDED
