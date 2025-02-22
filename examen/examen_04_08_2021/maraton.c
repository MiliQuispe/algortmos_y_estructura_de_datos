#include "maraton.h"


int crearLote()
{
    tParticipante par[]=
    {
        {123,"AAA", "1", 14.23},
        {456,"BBB", "2", 12.12},
        {789,"CCC", "3", 17.12},
        {912,"DDD", "4", 12.13},
        {912,"FFF", "4", 11.11},
        {345,"EEE", "5", 11.10}
    };

    return crearArchivoTxtFijo("maraton.txt",par, sizeof(tParticipante), 6, escribirParticipante);
}

int crearArchivoTxtFijo(const char* ruta, const void* datos, unsigned tamDato,int ce,  FormatoEscribir escribir)
{
    int i;
    FILE* pf = fopen(ruta,"wt");
    if(!pf)
    {
        return 0;
    }
    for(i=0; i<ce;i++)
    {
        escribir(datos,pf);
        datos = datos + tamDato;
    }
    fclose(pf);
    return 1;
}

int losNmejoresMaraton(const char* ruta, tLista *pl, int n)
{
    tParticipante par;
    char linea[TAM_LINEA];
    unsigned ce=0;

    FILE* pf = fopen(ruta,"rt");
    if(!pf)
    {
        return 0;
    }

    while(fgets(linea,sizeof(linea),pf))
    {
        sscanf(linea, "%8d %30s %15s %3f.2\n", &par.dni, par.nombre, par.apell, &par.tiempo);
        insertarNordenadoLista(pl, sizeof(tParticipante), &par , &ce, n, cmpParticipantes);
    }

    fclose(pf);
    return 1;
}

/////////////

void escribirParticipante (const void* dato, FILE* pf)
{
    tParticipante* par = (tParticipante*)dato;
    fprintf(pf, "%8d %-30s %-15s %.3f\n", par->dni, par->nombre, par->apell, par->tiempo);
}

void leerParticipante (const void* dato, FILE* pf);

int cmpParticipantes (const void* a, const void* b)
{
    tParticipante* par1 = (tParticipante*)a;
    tParticipante* par2 = (tParticipante*)b;
    return ((par1->tiempo - par2->tiempo)==0 )? 0 : ((par1->tiempo - par2->tiempo)>0 ? 1 : -1 );
}

void mostrarParticipante (void* info, void *cond)
{
    tParticipante* par = (tParticipante*)info;
    printf("%d, %s, %s, %f\n", par->dni, par->nombre, par->apell, par->tiempo);
}
