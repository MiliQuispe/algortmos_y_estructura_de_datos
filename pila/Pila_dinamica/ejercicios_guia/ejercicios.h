#ifndef EJERCICIOS_H_INCLUDED
#define EJERCICIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../primitivas/pila.h"
#include"../archivo/manejo_de_archivos.h"

#define TAM_NOMBRE 30
#define TAM_APELLIDO 30

typedef struct
{
    char nombre[TAM_NOMBRE];
    char apellido[TAM_APELLIDO];
    int edad;
    float promedio;
}tAlumno;

void prueba();

int crearLote();

int ejercicio_2_5();


#endif // EJERCICIOS_H_INCLUDED
