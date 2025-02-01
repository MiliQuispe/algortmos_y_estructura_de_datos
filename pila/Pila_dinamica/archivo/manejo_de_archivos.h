#ifndef MANEJO_DE_ARCHIVOS_H_INCLUDED
#define MANEJO_DE_ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../primitivas/pila.h"

typedef void (*FormatoGuardar) (FILE* pf, const void* dato);
typedef void (*FormatoExtraer) (char* linea, const void* dato);

int crearArchivoBinario (const char* ruta, const void* datos, unsigned tamDatos);
int crearArchivoTexto (const char* ruta, const void* datos, unsigned tamDato, unsigned ce, FormatoGuardar formato);

int cargarPilaBin (const char* ruta, tPila *p, unsigned tamDato);
int cargarPilaTXT (const char* ruta, tPila *p, unsigned tamDato, unsigned tamLinea, FormatoExtraer formato);

int cargarArchiboBinPila(const char* ruta, tPila *p, unsigned tamDato);

#endif // MANEJO_DE_ARCHIVOS_H_INCLUDED
