#ifndef EJERCICIO_6_6_H_INCLUDED
#define EJERCICIO_6_6_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

#define TAM_NOMBRE 30
#define TAM_APELLIDO 15

typedef struct
{
    char nombre[TAM_NOMBRE];
    char apellido[TAM_APELLIDO];
    unsigned dni;
    int edad;
}tPersona;

typedef struct
{
    unsigned dni;
    unsigned pos;
}tDni;

int cmpPersonas (const void * a, const void* b);
int cmpDNI (const void * a, const void* b);
void extraerArchivoBinPersonas (void* info, void* cond, void* parametros);
void grabarArchivoBinDNI (void* info, void* cond, void* parametros);
void mostrarDni (void* info, void* cond, void* parametros);
unsigned leerRgistroArchivoBin (void** info, unsigned pos, void* datos, void* parametros);

//////////////

int crearLote();

int cargarArchivoBin(const char* ruta, void* datos, unsigned tamDatos);

int cargarArchiboBinDesdeArbol(const char* ruta, tArbol *pa, Accion accion);

int cargarArbolArchivoBin(const char* ruta, tArbol *pa, unsigned tam, void* parametros, Cmp cmp, Accion accion);

int cargarArbolArchivoBinOrdenado(const char* ruta, tArbol *pa, unsigned tam, Leer leer);



#endif // EJERCICIO_6_6_H_INCLUDED
