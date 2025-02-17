#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cargarArchivoBin(const char* ruta, void* datos, unsigned tamDatos);

int cargarArchiboBinDesdeArbol(const char* ruta, tArbol *pa);





#endif // INDICE_H_INCLUDED
