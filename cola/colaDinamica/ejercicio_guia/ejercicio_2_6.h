#ifndef EJERCICIO_2_6_H_INCLUDED
#define EJERCICIO_2_6_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "cola.h"

#define TAM_NOMBRE 15
#define TAM_APELLIDO 15

typedef struct
{
    char nombre[TAM_NOMBRE];
    char apeliido[TAM_APELLIDO];
    int edad;
    float promedio;
}tAlumno;

typedef int (*Condicion) (const void* dato, const void* condi);
typedef void (*Mostrar) (const void* dato);

/// crear lote

int crearLote();

int crearArchivoBin (const char* ruta, const void* datos, unsigned tamDatos);

/// crear Archivos dato1 y dato2

int crearYmostrarArchivoBiPila(const char* ruta, tPila *p, unsigned tamDato, Mostrar mostrar);
int crearYmostrarArchivoBinCola(const char* ruta, tCola *pc, unsigned tamDato, Mostrar mostrar);

int crearArchivosDatosI(const char* rutaOriginal, const char* ruta1, const char* ruta2, const void* condi, Condicion condicion);

int alumnoConLaLetra (const void* dato, const void* condi);

void mostrarAlumno (const void* dato);


#endif // EJERCICIO_2_6_H_INCLUDED
