#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "lista.h"

#define TAM_NOMP 26
#define TAM_RUTA 26

typedef struct
{
    int nroP;
    char nomM[TAM_NOMP];
}tParticipantes;

typedef struct
{
    int posicion;
    int cantRondas;
    tParticipantes part;
}tJugador;

int crearLote();

int crearArchivoBinario(const char* ruta, const void* datos, unsigned tamDatos, int ce);

int juego(const char* participantes, int* cantPartidas);

int empezarJuego(tCola *pcParticipantes, int* cantPartidas, int canrParticipantes);

int cmpJugador (const void* a, const void* b);


#endif // JUEGO_H_INCLUDED
