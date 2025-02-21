#include "arbol.h"

void crearArbol(tArbol *pa)
{
    *pa =NULL;
}

int insertarOrdenadoArbol ( tArbol *pa, unsigned tamDato, const void * dato, Cmp cmp)
{
    tNodo *nue;

    if(*pa)
    {
        if(cmp(dato, (*pa)->info) ==0)
            return -1;
        else
        {
            if(cmp(dato, (*pa)->info) <0)
                return insertarOrdenadoArbol(&(*pa)->izq, tamDato, dato, cmp);
            return insertarOrdenadoArbol(&(*pa)->der, tamDato, dato, cmp);
        }
    }

    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->der = NULL;
    nue->izq = NULL;
    *pa = nue;
    return 1;
}

int cargarDatosOrdenados(tArbol *pa, int li, int ls, void* datos, void* parametros, Leer leer)
{
    int media = (li+ls)/2, resultado;

    if(li > ls) // se verifica qe no se pueda ingresar los datos, CONDICION de fin
        return 1;

    if(!(*pa = malloc(sizeof(tNodo)))) // se reserva el lugar del nodo
        return 0;

    (*pa)->tamInfo = leer(&(*pa)->info, media, datos, parametros); // se gurd la informacion y se recive el tamaño

    if(!(*pa)->tamInfo) // se verifica si se pudo guardar
    {
        free((*pa));
        return 0;
    }

    (*pa)->izq = NULL;
    (*pa)->der = NULL;

    resultado = cargarDatosOrdenados(&(*pa)->izq, li, media - 1, datos, parametros, leer);

    if(resultado !=1)   ///Si ya no hay mas que ingresar a la izquierda
        return resultado;

    return cargarDatosOrdenados(&(*pa)->der, media + 1, ls, datos, parametros, leer);
}

void mapInOrdenArbol(tArbol *pa, void* cond, void* parametros,  Accion accion)
{
    if(*pa)
    {
        mapInOrdenArbol(&(*pa)->izq, cond,parametros, accion);
        accion((*pa)->info, cond,parametros);
        mapInOrdenArbol(&(*pa)->der, cond, parametros, accion);
    }
}

void vaciarArbol(tArbol *pa)
{
    tNodo *elim;

    if(*pa)
    {
        vaciarArbol(&(*pa)->izq);
        vaciarArbol(&(*pa)->der);

        elim = *pa;
        *pa = NULL;
        free(elim->info);
        free(elim);
    }
}
