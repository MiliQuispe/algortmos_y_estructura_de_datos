#include "listaDoble.h"

void crearListaDoble(tListaDoble *pl)
{
    *pl = NULL;
}

int siEsListaDobleLlena(const tListaDoble *pl, unsigned tamDato)
{
    return 0;
}

int siEsListaDobleVacia(const tListaDoble *pl)
{
    return *pl ==NULL;
}

int insertarOrdenadoListaDoble(tListaDoble *pl, unsigned tamDato, const void* dato, Cmp cmp, int duplicado )
{
    tNodo *nue, *actual = *pl, *sig, *ant;
    if(*pl)
    {
        while(actual->ant !=NULL && cmp(dato, actual->info) <0)
        {
            actual = actual->ant;
        }
        while(actual->sig !=NULL && cmp(dato, actual->info) >0)
        {
            actual = actual->sig;
        }

        if(cmp(dato, actual->info) == 0 && duplicado == NO_DUPLICADO)
            return -1;

        else
        {
            if(cmp(dato, actual->info) > 0)
            {
                ant = actual;
                sig = actual->sig;
            }
            else
            {
                ant = actual->ant;
                sig = actual;
            }
        }
    }
    else
    {
        ant = NULL;
        sig = NULL;
    }


    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->ant = ant;
    nue->sig = sig;

    if(ant)
    {
        ant->sig = nue;
    }
    if(sig)
    {
        sig->ant = nue;
    }
    *pl = nue;
    return 1;
}

int eliminarValorListaDoble(tListaDoble *pl, unsigned tamDato, void* dato, Cmp cmp)
{
    tNodo *elim, *actual;

    if(*pl ==NULL)
        return 0;

    actual = (*pl);
    while(actual->ant !=NULL && cmp(dato, actual->info) !=0)
    {
        actual = actual->ant;
    }

    if(cmp(dato, actual->info) !=0)
        actual = (*pl)->sig;

    while(actual->sig !=NULL && cmp(dato, actual->info) !=0)
    {
        actual = actual->sig;
    }

    if(cmp(dato, actual->info) !=0)
        return -1;

    elim = actual;
    memcpy(dato, elim->info, MIN(elim->tamInfo, tamDato));

    if(actual->ant ==NULL && (actual->sig==NULL))
       *pl =NULL;
    else
    {
        if(actual->ant)
        {
            actual->ant->sig = actual->sig;
            *pl =actual->ant;
        }

        if(actual->sig)
        {
            actual->sig->ant = actual->ant;
            *pl =actual->sig;
        }
    }


    free(elim->info);
    free(elim);
    return 1;
}

void mapListaDobleA(tListaDoble *pl, void* cond, Accion accion)
{
    tNodo *actual = *pl;
    if(actual !=NULL)
    {
        while(actual->ant !=NULL)
        {
            actual = actual->ant;
        }

        while(actual !=NULL)
        {
            accion(actual->info, cond);
            actual = actual->sig;
        }
    }
}

void mapListaDobleD(tListaDoble *pl, void* cond, Accion accion)
{
    tNodo *actual = *pl;
    if(actual !=NULL)
    {
        while(actual->sig !=NULL)
        {
            actual = actual->sig;
        }

        while(actual !=NULL)
        {
            accion(actual->info, cond);
            actual =  actual->ant;
        }
    }
}

void filterListDoble(tListaDoble *pl, Filter filter)
{
    tNodo *actual, *elim;
    if(*pl !=NULL)
    {
        actual = *pl;
        while(actual->ant !=NULL)
        {
            actual = actual->ant;
        }


        while(actual !=NULL)
        {
            if(filter(actual->info))
            {
                elim= actual;

                if(actual->ant)
                {
                    actual->ant->sig = actual->sig;
                }

                if(actual->sig)
                {
                    actual->sig->ant = actual->ant;
                }
                actual = actual->sig;

                free(elim->info);
                free(elim);
            }
            else
            {
                actual = actual->sig;
                if(actual)
                    *pl = actual;
            }

        }
    }
}

void reduceListDoble(tListaDoble *pl, Reduce reduce);
void ordenarListaDoble(tListaDoble *pl, Cmp cmp);


void vaciarListaDoble(tListaDoble *pl)
{
    tNodo *elim, *actual;

     if(*pl)
     {
         actual = (*pl)->ant;

         while(actual !=NULL)
        {
            elim = actual;
            if(actual->ant)
            {
                actual->ant->sig = actual->sig;
            }

            if(actual->sig)
            {
                actual->sig->ant = actual->ant;
            }
            actual = actual->ant;

            free(elim->info);
            free(elim);

        }
        actual =*pl;
        *pl =NULL;

        while(actual !=NULL)
        {
            elim = actual;
            if(actual->ant)
            {
                actual->ant->sig = actual->sig;
            }

            if(actual->sig)
            {
                actual->sig->ant = actual->ant;
            }
            actual = actual->sig;

            free(elim->info);
            free(elim);

        }
     }
}
