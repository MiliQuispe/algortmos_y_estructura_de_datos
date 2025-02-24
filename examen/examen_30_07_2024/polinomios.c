#include "polinomios.h"

int crearLote()
{
    tTermino ter1[]=
    {
        {3,4},
        {6,1},
        {-1,3},
        {2,-5},
        {4,6}
    }, ter2[]=
    {
        {2,6},
        {6,-1},
        {3,-2},
        {-2,3},
        {4,5}
    };

    if(crearArchivoTXT("p1.txt",ter1, sizeof(tTermino), 5, escribirTermino))
        return crearArchivoTXT("p2.txt",ter2, sizeof(tTermino), 5, escribirTermino);
    return 0;
}

int crearArchivoTXT(const char* ruta, const void* datos, unsigned tamDato, int ce, FormatoEscribir escribir)
{
    int i;
    FILE*pf=fopen (ruta,"wt");
    if(!pf)
    {
        printf("\nNo se pudo crear el archivo %s\n",ruta);
        return 0;
    }

    for(i=0; i<ce; i++)
    {
        escribir(datos, pf);
        datos = datos + tamDato;
    }

    fclose(pf);
    return 1;
}

int sumarPolinomiosTXT(const char* rutaP1, const char* rutaP2, const char* rutaPr)
{
    char linea[TAM_LINEA];
    tTermino ter;
    tLista pl;

    FILE*p1=fopen (rutaP1,"rt");
    if(!p1)
    {
        printf("\nNo se pudo abrir el archivo %s\n",rutaP1);
        return 0;
    }

    FILE*p2=fopen (rutaP2,"rt");
    if(!p2)
    {
        printf("\nNo se pudo abrir el archivo %s\n",rutaP2);
        fclose(p1);
        return 0;
    }

    crearListaDoble(&pl);

    while(fgets(linea,TAM_LINEA,p1))
    {
        sscanf(linea, "X(%d)(%d)\n", &ter.potencia, &ter.coeficiente);
        insertarOrdenadoListaDoble(&pl, sizeof(tTermino), &ter, cmpTermino, acumularTermino);
//        mapListaDoble(&pl, NULL,mostrarTermino);
    }


    while(fgets(linea,TAM_LINEA,p2))
    {
        sscanf(linea, "X(%d)(%d)\n", &ter.potencia, &ter.coeficiente);
        insertarOrdenadoListaDoble(&pl, sizeof(tTermino), &ter, cmpTermino, acumularTermino);
    }

    mapListaDoble(&pl, NULL,mostrarTermino);

    guardarListaDobleOrdenadaTXT(rutaPr, &pl, grabarTermino);

    fclose(p1);
    fclose(p2);
    return 1;
}

int guardarListaDobleOrdenadaTXT(const char* ruta, tLista *pl, Accion accion)
{
    FILE*pf=fopen (ruta,"wt");
    if(!pf)
    {
        printf("\nNo se pudo crear el archivo %s\n",ruta);
        return 0;
    }

    mapVaciarListaDoble(pl, pf, accion);

    fclose(pf);
    return 1;
}


////////

void escribirTermino (const void* info, FILE* pf)
{
    tTermino* ter = (tTermino*)info;
    fprintf(pf, "X(%d)(%d)\n", ter->potencia, ter->coeficiente);
}

int cmpTermino (const void* a, const void* b)
{
    tTermino* ter1 = (tTermino*)a;
    tTermino* ter2 = (tTermino*)b;
    int res =ter1->potencia - ter2->potencia;


    return res;
}

void grabarTermino(void* info, void* cond)
{
    tTermino* ter = (tTermino*)info;
    FILE* pf = (FILE*)cond;

    fprintf(pf, "X(%d)(%d)\n", ter->potencia, ter->coeficiente);
}

void mostrarTermino(void* info, void* cond)
{
    tTermino* ter = (tTermino*)info;
    printf("X(%d)(%d)\n", ter->potencia, ter->coeficiente);
}

int acumularTermino(void* info, const void* dato)
{
    tTermino* ter1 = (tTermino*)info;
    tTermino* ter2 = (tTermino*)dato;

    ter1->coeficiente += ter2->coeficiente;

    return ter1->coeficiente;
}
