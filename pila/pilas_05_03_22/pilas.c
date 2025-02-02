#include "pilas.h"

//archivoLote

int crearLote()
{
    tRegistro reg[]=
    {
        {3,2},
        {1,5},
        {2,7},
        {-2,2},
        {1,2},
        {2,7},
        {3,7},
        {-1,-9},
        {3,0},
        {0,0}
    };

    return crearArchivoTexto("datos.txt", reg,sizeof(tRegistro), sizeof(reg)/sizeof(tRegistro),3, formatoPilas);
}

int crearArchivoTexto(const char* ruta, void* datos, unsigned tamDato, unsigned ce,unsigned cp, Formato formato)
{
    int i;

    FILE* pf = fopen(ruta,"wt");
    if(!pf)
    {
        printf("No se pudo crear el archvivo %s", ruta);
        return 0;
    }

    fprintf(pf, "%d\n", cp);

    for(i=0; i <ce; i++)
    {
        formato(pf, datos);
        datos = datos + tamDato;
    }

    fclose(pf);
    return 1;
}

void formatoPilas (FILE *pf, void* reg)
{
    tRegistro* registro = (tRegistro*)reg;
    fprintf(pf, "(%d,%d)\n", registro->pila, registro->val);
}

//archivoPilas

int crearPilas(const char* ruta, unsigned tamLinea)
{
    void* linea= malloc(tamLinea);
    int n,i;
    tPila *p;
    tRegistro reg;

    if(!linea)
        return 0;

    FILE* pf = fopen(ruta,"rt");
    if(!pf)
    {
        printf("No se pudo abrir el archvivo %s", ruta);
        free(linea);
        return 0;
    }

    fgets(linea,tamLinea,pf);
    sscanf(linea, "%d\n", &n);

    p = malloc(sizeof(tPila)* n);
    if(!p)
    {
        fclose(pf);
        free(linea);
        return 0;
    }


    //inicializar
    for(i=0; i<n; i++)
    {
        crearPila( p + i);
    }

    fgets(linea,tamLinea,pf);
    sscanf(linea,"(%d,%d)\n", &reg.pila, &reg.val);

    while(reg.pila!=0)
    {
        if(reg.pila>0)
        {
            if(reg.val==0)
                vaciarPila(p + reg.pila -1);
            else
                ponerEnPila(p + reg.pila -1, sizeof(int),&reg.val);
        }
        else
        {
            if(reg.pila<0)
                sacarEnPila(p + (reg.pila * -1) -1, sizeof(int),&reg.val);
        }

        fgets(linea,tamLinea,pf);
        sscanf(linea,"(%d,%d)\n", &reg.pila, &reg.val);
    }

    for(i=0; i<n; i++)
    {
        if(!siEsPilaVacia(p+i))
        {
            sprintf(linea,"pila%d.txt", i+1);
            guardarPila(linea, p + i, sizeof(int),formatoPilaI);
        }
    }



    free(linea);
    free(p);
    fclose(pf);
    return 1;
}

int guardarPila(const char* ruta, tPila *p, unsigned tamDato, Formato formato)
{
    void* aux= malloc(tamDato);
    if(!aux)
        return 0;

    FILE* pf = fopen(ruta,"wt");
    if(!pf)
    {
        printf("No se pudo crear el archvivo %s", ruta);
        free(aux);
        return 0;
    }

    while(!siEsPilaVacia(p))
    {
        sacarEnPila(p,tamDato, aux);
        formato(pf,aux);
    }

    free(aux);
    fclose(pf);
    return 1;

}

void formatoPilaI (FILE *pf, void* reg)
{
    int* registro = (int*)reg;
    fprintf(pf, "%d\n", *registro);
}
