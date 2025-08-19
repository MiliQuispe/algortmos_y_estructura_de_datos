#include "arbol.h"

void crearArbol (tArbol *pa);

int insertarArbol(tArbol *pa, unsigned tamDato, void* datom, Cmp cmp);

int eliminarRaiz(tArbol *pa)
{
    tNodo *elim, **respuesta;

    if(*pa ==NULL)
        return 0;

    free((*pa)->info);
    if((*pa)->izq ==NULL && (*pa)->der==NULL)
    {
        free(*pa);
        *pa =NULL;
        return 1;
    }

    respuesta= altura(&(*pa)->izq) > altura(&(*pa)->der) ? mayorNodo(&(*pa)->izq) : menorNodo(&(*pa)->der);

    elim = *respuesta;
    (*pa)->info = elim->info;
    (*pa)->tamInfo = elim->tamInfo;

    *respuesta = elim->izq ? elim->izq : elim->der;

    free(elim->info);
    free(elim);
    return 1;

}

int cargarDatosOrdenadosArbol(tArbol *pa, int li, int ls, void* datos, void* parametros, Leer leer)
{
    int m = (li+ls)/2, res;

    if(li>ls)
        return 1;


}

int altura(tArbol *pa){return 1;}

tNodo ** mayorNodo(tArbol *pa)
{
    return (tNodo **) pa;
}
tNodo ** menorNodo(tArbol *pa)
{
    return (tNodo **) pa;
}

void mapInOrdenArbol(tArbol *pa, void* cond, Accion);

void vaciarArbol(tArbol *pa);

