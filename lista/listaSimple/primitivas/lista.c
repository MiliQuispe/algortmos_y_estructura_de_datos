#include "lista.h"


void crearLista (tLista *pl)
{
    *pl =NULL;
}

int siEsListaLLena(const tLista *pl, unsigned tamDato)
{
    return 0;
}

int siEsListaVacia(const tLista *pl)
{
    return *pl ==NULL;
}

int ponerXposicionLista(tLista *pl, unsigned tamdato, const void* dato, unsigned pos)
{
    tNodo *nue;

    while(pos>0 && *pl)
    {
        pl = &(*pl)->sig;
        pos--;
    }
    if(*pl ==NULL && pos<0)
        return -1;
    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamdato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamdato);
    nue->tamInfo = tamdato;
    nue->sig= *pl;
    *pl = nue;
    return 1;
}

int insertarOrdenadoLista(tLista *pl, unsigned tamdato, const void* dato, Cmp cmp)
{
    tNodo *nue;

    while(*pl && cmp((*pl)->info, dato) <0)
    {
        pl = &(*pl)->sig;
    }

    if(!(nue= malloc(sizeof(tNodo))) || !(nue->info = malloc(tamdato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamdato);
    nue->tamInfo = tamdato;
    nue->sig= *pl;
    *pl = nue;
    return 1;
}

int insertarAlComienzoLista(tLista *pl, unsigned tamdato, const void* dato)
{
    tNodo *nue;

    if(!(nue= malloc(sizeof(tNodo))) || !(nue->info = malloc(tamdato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamdato);
    nue->tamInfo = tamdato;
    nue->sig= *pl;
    *pl = nue;
    return 1;
}

int losXmejores(tLista *pl, unsigned tamdato,  const void* dato, unsigned ceMax, unsigned *ce, Cmp cmp)
{
    tNodo *nue, *elim;

    while(*pl && cmp((*pl)->info, dato) <0)
    {
        pl = &(*pl)->sig;
    }
    if(*pl ==NULL && ceMax == *ce)
        return 0;

    if(!(nue= malloc(sizeof(tNodo))) || !(nue->info = malloc(tamdato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamdato);
    nue->tamInfo = tamdato;
    nue->sig= *pl;
    *pl = nue;

    if(ceMax > *ce)
    {
        *ce = *ce + 1;
        return 1;
    }

    while((*pl)->sig !=NULL)
    {
        pl = &(*pl)->sig;
    }

    elim = *pl;
    *pl =elim->sig;
    free(elim->info);
    free(elim);
    return 2;

}

int sacarEnXposicionLista(tLista *pl, unsigned tamdato,void* dato, unsigned pos)
{
    tNodo *elim;

    if(*pl == NULL)
        return 0;

    while(pos>0 && *pl)
    {
        pl = &(*pl)->sig;
        pos--;
    }
    if(*pl ==NULL)
        return -1;

    elim = *pl;
    *pl = elim->sig;
    memcpy(dato, elim->info, MIN(tamdato, elim->tamInfo));

    free(elim->info);
    free(elim);
    return 1;
}

int sacarXvalorLista(tLista *pl, unsigned tamdato, void* dato, Cmp cmp)
{
    tNodo *elim;

    if(*pl ==NULL)
        return 0;

    while(*pl && cmp((*pl)->info, dato) !=0)
    {
        pl = &(*pl)->sig;
    }
    if( *pl ==NULL)
        return -1;

    elim = *pl;
    *pl = elim->sig;
    memcpy(dato, elim->info, MIN(tamdato, elim->tamInfo));

    free(elim->info);
    free(elim);
    return 1;
}

int eliminarApariciones(tLista *pl, unsigned tamDato, void* dato, Cmp cmp)
{
    tNodo *elim;
    int cont=0;

    if(*pl ==NULL)
        return 0;

    while(*pl)
    {
        if(cmp((*pl)->info, dato) ==0)
        {
            elim = *pl;
            *pl =elim->sig;
            free(elim->info);
            free(elim);
            cont ++;
        }
        else
            pl = & (*pl)->sig;
    }

    if(cont ==0)
        return -1;
    return 1;
}

void mapLista(tLista *pl, const void* cond, Accion accion)
{
    while(*pl)
    {
        accion((*pl)->info, cond);
        pl = &(*pl)->sig;
    }
}


void ordenarLista(tLista *pl, Cmp cmp)
{
    tNodo **menor;

    while(*pl)
    {
        menor = buscarMenorLista(pl,cmp);
        intercambiarNodos(menor,pl);
        pl = &(*pl)->sig;
    }
}

tNodo** buscarMenorLista(tLista *pl, Cmp cmp)
{
    tNodo **menor;

    if(*pl ==NULL)
        return NULL;

    menor = pl;
    pl = &(*pl)->sig;

    while(*pl)
    {
        if(cmp((*menor)->info, (*pl)->info) > 0)
            menor = pl;
        pl = &(*pl)->sig;
    }
    return menor;
}
void intercambiarNodos(tNodo** nodo1, tNodo **nodo2)
{
    tNodo *aux;

    aux = *nodo1;
    *nodo1 = *nodo2;
    *nodo2 = aux;

    aux = (*nodo1)->sig;
    (*nodo1)->sig = (*nodo2)->sig;
    (*nodo2)->sig = aux;

}

void vaciarLista(tLista *pl)
{
    tNodo *elim;

    while(*pl)
    {
        elim = *pl;
        *pl = elim->sig;
        free(elim->info);
        free(elim);
    }
}

