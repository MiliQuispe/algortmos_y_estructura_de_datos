////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Complete sus datos /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//
// Apellido, Nombres:
//
// DNI:
//
// Justificación de estructura de datos seleccionada:
//
/////////////////////////////////////////////////////////////////////////////////////////

//    1- crear una cola de pilas
//    2- hacer una pila con los datos de la cola de pilas

/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cola_dinamica.h"
#include "../include/pila_dinamica.h"

#define TAM_CANTPILAS 3
#define TAM_CANTDATOS 4

typedef void (*Accion) (void* info, void* cond);
typedef int (*PonerEnPila) (const void* datos, int ce, tPila* p);

int crearLote(tCola *pc);

int ponerPilaEnCola(tCola *pc, tPila*p, const void* datos, int ce, PonerEnPila poner);

int mostrarYvaciarColaDePilas(tCola *pc, void* cond, unsigned tamDato, Accion accion);

int obtenerPilaColaDePilas(tCola *pc, tPila *p, unsigned tamDato);

int mostrarYvaciarPila(tPila *p, void* cond, unsigned tamDato, Accion accion);

///

void mostrarEntero (void* info, void* cond);

int ponerEnteroEnPila (const void* datos, int ce, tPila* p);

int main()
{
//    tCola pc;
//    tPila p;
//    int i, vec[]={1,2,3,4,5}, aux;
//
//    crearCola(&pc);
//    crearPila(&p);
//
//    for(i=0; i<5; i++)
//    {
//        poner_en_cola(&pc, vec+i, sizeof(int));
//        apilar(&p, vec+i, sizeof(int));
//    }
//
////    vaciarPila(&p);
////    vaciar_cola(&pc);
//
//    for(i=0; i<7; i++)
//    {
//        desapilar(&p, &aux, sizeof(int));
//        printf("%d\t", aux);
//    }
//    printf("\n");
//    for(i=0; i<9; i++)
//    {
//        sacar_de_cola(&pc, &aux, sizeof(int));
//        printf("%d\t", aux);
//    }
    tCola pc;
    tPila p;

    crearCola(&pc);
    crearPila(&p);

    crearLote(&pc);
//    mostrarYvaciarColaDePilas(&pc, NULL, sizeof(int), mostrarEntero);

    obtenerPilaColaDePilas(&pc, &p, sizeof(int));
    mostrarYvaciarPila(&p, NULL, sizeof(int), mostrarEntero);

    vaciar_cola(&pc);
    vaciarPila(&p);

    return 0;
}

int crearLote(tCola *pc)
{
    int mat[][TAM_CANTDATOS]=
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    }, i;
    tPila p;

    for(i=0; i<TAM_CANTPILAS; i++)
    {
        crearPila(&p);
        if(!(ponerPilaEnCola(pc, &p, mat[i], TAM_CANTDATOS, ponerEnteroEnPila)))
            return 0;
    }
    return 1;
}

int ponerPilaEnCola(tCola *pc, tPila*p, const void* datos, int ce, PonerEnPila poner)
{
    if(!(poner(datos, ce,p)))
        return 0;
    return poner_en_cola(pc, p, sizeof(tPila));
}

int mostrarYvaciarColaDePilas(tCola *pc, void* cond, unsigned tamDato, Accion mostrar)
{
    void* aux = malloc(tamDato);
    tPila p;

    if(pc->pri==NULL)
        return 0;

    if(!aux)
        return 0;

    crearPila(&p);

    while(!colaVacia(pc))
    {
        sacar_de_cola(pc, &p, sizeof(tPila));

        while(!pilaVacia(&p))
        {
            desapilar(&p, aux, tamDato);
            mostrar(aux, cond);
        }
        printf("\n");
    }

    free(aux);
    return 1;

}

int obtenerPilaColaDePilas(tCola *pc, tPila *p, unsigned tamDato)
{
    void* aux = malloc(tamDato);
    tPila paux1, paux2;

    if(!aux)
        return 0;

    crearPila(&paux1);
    crearPila(&paux2);

    while(!colaVacia(pc))
    {
        sacar_de_cola(pc, &paux1, sizeof(tPila));

        while(!pilaVacia(&paux1))
        {
            desapilar(&paux1, aux, tamDato);
            apilar(&paux2, aux, tamDato);
        }

        while(!pilaVacia(&paux2))
        {
            desapilar(&paux2, aux, tamDato);
            apilar(p, aux, tamDato);
        }
    }

    free(aux);
    return 1;
}

int mostrarYvaciarPila(tPila *p, void* cond, unsigned tamDato, Accion mostrar)
{
    void* aux = malloc(tamDato);

    if(*p==NULL)
        return 0;

    if(!aux)
        return 0;

    while(!pilaVacia(p))
    {
        desapilar(p, aux, tamDato);
        mostrar(aux,cond);
    }

        free(aux);
    return 1;
}


void mostrarEntero (void* info, void* cond)
{
    int* num = (int*)info;
    printf("%d\t",*num);
}

int ponerEnteroEnPila (const void* datos, int ce, tPila* p)
{
    int* nums = (int*)datos;
    int i;
    for(i=0;i<ce;i++)
    {
        if(!(apilar(p, nums+i, sizeof(int))))
           return 0;
    }
    return 1;
}
