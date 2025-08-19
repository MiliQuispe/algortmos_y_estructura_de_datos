#include "ListaDoble.h"

void crearListaDoble (tLista *pl)
{
    *pl =NULL;
}

int insertarOrdenadoListaDoble(tLista *pl, unsigned tamDato, const void* dato, Cmp cmp, AcumularDuplicado duplicado)
{
    tNodo *nue, *actual = *pl, *sig, *ant, *elim;

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

        if(cmp(dato, actual->info)==0)
         {
            if(duplicado(actual->info, dato)==0)
            {
                elim=actual;

                if(elim->ant ==NULL && elim->sig ==NULL)
                {
                    *pl =NULL;
                }
                else
                {
                    if(elim->ant !=NULL )
                    {
                        elim->ant->sig = elim->sig;
                        *pl = elim->ant;
                    }

                    if(elim->sig !=NULL )
                    {
                        elim->sig->ant = elim->ant;
                        *pl = elim->sig;
                    }
                }

                free(elim->info);
                free(elim);
            }

             return -1;
         }

        if(cmp(dato, actual->info)<0)
        {
            sig = actual;
            ant= actual->ant;
        }
        else
        {
            sig = actual->sig;
            ant =actual;
        }
    }
    else
    {
        sig=NULL;
        ant=NULL;
    }

    if(!(nue = malloc(sizeof(tNodo))) || !(nue->info = malloc(tamDato)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, tamDato);
    nue->tamInfo = tamDato;
    nue->ant= ant;
    nue->sig=sig;

    if(sig)
        sig->ant = nue;
    if(ant)
        ant->sig =nue;

    *pl =nue;
    return 1;
}
void mapListaDoble(tLista *pl, void* cond, Accion accion)
{

    if(*pl)
    {
        while((*pl)->ant !=NULL)
        {
            pl = & (*pl)->ant;
        }
        while((*pl)!=NULL)
        {
            accion((*pl)->info, cond);
            pl = & (*pl)->sig;
        }
    }
}

void mapVaciarListaDoble(tLista *pl, void* cond, Accion accion)
{
    tNodo *elim;

    if(*pl)
    {
        while((*pl)->ant !=NULL)
        {
            pl = & (*pl)->ant;
        }
        while(*pl)
        {
            accion((*pl)->info, cond);

            elim = *pl;
            *pl = elim->sig;
            free(elim->info);
            free(elim);
        }
    }
}
