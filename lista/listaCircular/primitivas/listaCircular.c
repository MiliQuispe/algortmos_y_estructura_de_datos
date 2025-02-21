#include "listaCircular.h"

void crearListaCircular (tListaCircular *pl)
{
    *pl =NULL;
}

int siEsListaCircularLlena(const tListaCircular *pl, unsigned tamDato)
{
    return 0;
}
int siEsListaCircularVacia(const tListaCircular *pl)
{
    return *pl ==NULL;
}

int insertarOrdenadoListaCircular (tListaCircular *pl, unsigned tamDato, const void* dato, Cmp cmp)
{
    tNodo *nue, *pri = *pl, *actual=*pl;

    while(actual!=NULL && (pri != actual->sig) && cmp(actual->info, dato) <0)
    {
       actual = actual->sig;
    }
    if( actual!=NULL && cmp(actual->info, dato) ==0)
        return -1;

    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    if(actual!=NULL)
    {

        if(pri == pri->sig)
        {
            nue->sig= actual;
            actual->sig=nue;
        }
        else
        {
            if(pri == actual)
            {
                nue->sig = actual;
                *pl = nue;
            }
            else
            {
                if(cmp(actual->info, dato) <0)
                {
                    nue->sig = actual->sig;
                    actual->sig= nue;
                }
                else
                {
                    nue->sig= actual;
                    actual= nue;
                }
            }
        }
    }
    else
    {
        nue->sig = nue;
        *pl = nue;
    }
    return 1;
}

int eliminarXvalorListaCircular (tListaCircular *pl, unsigned tamDato, void* dato, Cmp cmp)
{
    tNodo *elim, *pri = *pl,*actual=*pl;

    if(*pl ==NULL)
        return 0;

    while(actual->sig != pri && cmp(actual->info, dato) !=0)
    {
        actual = actual->sig;
    }
    if(cmp(actual->info, dato) !=0)
        return -1;

    elim = *pl;
    memcpy(dato, elim->info, MIN(tamDato, elim->tamInfo));

    if(pri == pri->sig)
        *pl = NULL;
    else
    {
        if(pri == actual)
        {
            while(actual->sig != pri )
            {
                actual = actual->sig;
            }
            elim = pri;
            actual->sig= pri->sig;
            *pl = pri->sig;
        }
        else
            actual = elim->sig;
    }


    free(elim->info);
    free(elim);
    return 1;
}

void mapListaCircular (tListaCircular *pl, void* cond, Accion accion)
{
    tNodo *pri = *pl;

    if(*pl)
    {
        while((*pl)->sig != pri)
        {
            accion((*pl)->info, cond);
            pl = &(*pl)->sig;
        }
        accion((*pl)->info, cond);
    }

}

void vaciarListaCircular(tListaCircular *pl)
{
    tNodo *elim, *pri = *pl;
    if(*pl)
    {
        while((*pl)->sig != pri)
        {
            elim = *pl;
            *pl = elim->sig;
            free(elim->info);
            free(elim);
        }
        elim = *pl;
        *pl = NULL;
        free(elim->info);
        free(elim);
    }
}




