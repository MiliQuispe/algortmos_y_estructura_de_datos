////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Complete sus datos /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//
// Apellido, Nombres: Quispe Milagros
//
// DNI: 45064110
//
// Justificación de estructura de datos seleccionada:
//
//
/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/arbol.h"

#define TAM_CLAVE 6
#define TAM_LINEA 20

typedef struct
{
    char clave[TAM_CLAVE];
    int dato;
}tDatos;

typedef void (*FormatoLeer)(const char* linea, void* dato);
typedef void (*Accion)(void *, unsigned, void *);
typedef int (*Cmp)(const void *, const void *);


///

int crearLote();

int guardarArbolPreOrdenArchivoTXT(const char* ruta, tArbolBinBusq *pa, Accion accion);

int cargarArbolArchivoTXT(const char* ruta, tArbolBinBusq *pa, unsigned tamInfo, FormatoLeer leer, Cmp cmp);

///

int cantNodosNnivel(const tArbolBinBusq *pa, int nivel);

///

int SiEsNivelIncompleto(const tArbolBinBusq *pa, int nivel);

///

int potencia(int x, int p);

void leerDato (const char* linea, void* dato);

void guardarDato (void *info, unsigned tamInfo, void *cond);

void mostrarDato (void *info, unsigned tamInfo, void *cond);

int cmpDato (const void *a, const void *b);

///

int main()
{
    int opcion, nivel, arch=-1;
    tArbolBinBusq pa;
    crearArbolBinBusq(&pa);


    if(crearLote())
    {

        do
        {

            printf("\nMENU\n1-Cargar arbol\n"
                   "2-Cantidad de nodos un nivel 'n'\n"
                   "3-El nivel 'n' es completo?\n4-Salir\nOpcion:\t");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    printf("\n1-\n");
                    if((arch=cargarArbolArchivoTXT("datos.txt", &pa, sizeof(tDatos), leerDato, cmpDato))!=0)
                        recorrerEnOrdenSimpleArbolBinBusq_res(&pa, NULL,mostrarDato);
                    else
                        printf("\nNo se pudo cargar\n");
                    break;

                case 2:

                    if(arch>0)
                    {
                        printf("\nIngrese el nivel\n");
                        scanf("%d",&nivel);

                        printf("\nCantidad de nodos en el nivel %d:\t%d\n", nivel,  cantNodosNnivel(&pa,nivel));

                    }
                    else
                        printf("\nCargue el arbol\n");
                    break;

                case 3:

                    if(arch>0)
                    {
                        printf("\nIngrese el nivel\n");
                        scanf("%d",&nivel);

                        printf("\nNodos faltantes en el nivel %d:\t%d\n", nivel, SiEsNivelIncompleto(&pa,nivel));
                    }
                    else
                        printf("\nCargue el arbol\n");
                    break;

                case 4:
                    printf("\nSaliendo..\n");
                    break;

                default:
                    printf("\nElija una opcion correcta\n");
                    break;
            }
        }while(opcion !=4);

    }

    return 0;
}

///

int crearLote()
{
    tDatos dat[]=
    {
        {"BB",22},
        {"DD",44},
        {"AA",11},
        {"CC",33},
        {"FF",66},
        {"EE",55}
    };
    int i;
    tArbolBinBusq pa;
    crearArbolBinBusq(&pa);

    for(i=0; i<6; i++)
    {
        insertarArbolBinBusq(&pa, dat+i, sizeof(tDatos), cmpDato);
    }

//    recorrerEnOrdenSimpleArbolBinBusq_res(&pa, NULL,mostrarDato);

    i=guardarArbolPreOrdenArchivoTXT("datos.txt", &pa, guardarDato);

    vaciarArbolBin(&pa);
    return i;
}

int guardarArbolPreOrdenArchivoTXT(const char* ruta, tArbolBinBusq *pa, Accion accion)
{
    FILE*  pf = fopen(ruta,"wt");
    if(!pf)
    {
        printf("\nNo se pudo crear el archivo %s\n", ruta);
        return 0;
    }

    recorrerPreOrdenSimpleArbolBinBusq(pa,pf, accion);

    fclose(pf);
    return 1;

}

int cargarArbolArchivoTXT(const char* ruta, tArbolBinBusq *pa, unsigned tamInfo, FormatoLeer leer, Cmp cmp)
{
    char linea[TAM_LINEA];
    void* aux;

    if(!(aux = malloc(tamInfo)))
        return 0;

    FILE*  pf = fopen(ruta,"rt");
    if(!pf)
    {
        printf("\nNo se pudo abrir el archivo %s\n", ruta);
        free(aux);
        return 0;
    }

    while(fgets(linea, TAM_LINEA, pf))
    {
        leer(linea,aux);
        insertarArbolBinBusq(pa, aux, tamInfo, cmp);
    }

    fclose(pf);
    free(aux);
    return 1;
}

///

int potencia(int x, int p)
{
    if(p ==0)
        return 1;

    return x * potencia(x, p-1);
}

int cantNodosNnivel(const tArbolBinBusq *pa, int nivel)
{
    int c1,c2;

    if(*pa ==NULL || nivel<0)
        return 0;

    if(nivel ==0)
        return 1;

    c1 = cantNodosNnivel(&(*pa)->izq, nivel-1);
    c2 = cantNodosNnivel(&(*pa)->der, nivel-1);

    return c1 + c2;
}

///

int SiEsNivelIncompleto(const tArbolBinBusq *pa, int nivel)
{
    int ce;

    if(nivel<0)
        return -1;

    ce = cantNodosNnivel(pa, nivel);

    return ((potencia(2,nivel+1)/2) - ce);
}

///

void leerDato (const char* linea, void* dato)
{
    tDatos* dat = (tDatos*)dato;

    sscanf(linea,"%[^-]-%d\n", dat->clave, &dat->dato);
}

void guardarDato (void *info, unsigned tamInfo, void *cond)
{
    tDatos* dat = (tDatos*)info;
    FILE* pf =(FILE*) cond;

    fprintf(pf, "%s-%d\n", dat->clave, dat->dato);
}

void mostrarDato (void *info, unsigned tamInfo, void *cond)
{
    tDatos* dat = (tDatos*)info;
    printf("%s-%d\n", dat->clave, dat->dato);
}

int cmpDato (const void *a, const void *b)
{
    tDatos* dat1 = (tDatos*)a;
    tDatos* dat2 = (tDatos*)b;

    return strcmpi(dat1->clave, dat2->clave);
}

