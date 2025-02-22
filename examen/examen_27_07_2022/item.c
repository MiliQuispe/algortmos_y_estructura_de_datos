#include "item.h"

void itemA()
{
    int vec[]={1,2,3,4,5,6};
    int i, cond = 3;
    tLista pl;

    crearLista(&pl);

    for(i=0; i<6; i++)
    {
        insertarListaAlFinal(&pl, sizeof(int), vec+i);
    }

    mapListaInverso(&pl, &cond,mostrarMayoesDe3);

    vaciarLista(&pl);
}


//////////

void mostrarMayoesDe3 (void* info, void* cond)
{
    int* num = (int*)info;
    int* condicion = (int*)cond;

    if(*condicion < *num)
        printf("%d\t",*num);
}


///

void itemB()
{
    tArbol pa;

    crearArbol(&pa);
    if(crearLote() && cargarArbol("producto.dat",&pa, sizeof(tIndiceProducto), sizeof(tProducto),cmpIndiceProducto,indiceProducto))
    {
//        mapInOrdenArbol(&pa, NULL, mostrarIndice);
        if(crearArchivoIndice("productos.idx",&pa, escribirIndice))
        {
            vaciarArbol(&pa);
            crearArbol(&pa);
            cargarIndice("productos.idx",&pa, sizeof(tIndiceProducto),leerIndiceProducto);

            mapInOrdenArbol(&pa, NULL, mostrarIndice);

            vaciarArbol(&pa);
        }
    }
}

int crearLote()
{
    tProducto prod[]=
    {
        {"DD111",'C',234},
        {"AA111",'B',53},
        {"BB111",'B',123},
        {"CC111",'C',98},
        {"EE111",'B',273},
        {"FF111",'C',387}
    };

    return crearArchivoBinario("producto.dat", prod, sizeof(prod));
}
int crearArchivoBinario(const char* ruta, const void* datos, unsigned tamDatos)
{
    FILE* pf = fopen(ruta, "wb");
    if(!pf)
    {
        printf("\nNo se pudo crear el archivo %s",ruta);
        return 0;
    }

    fwrite(datos, tamDatos, 1, pf);

    fclose(pf);
    return 1;
}

int cargarArbol(const char* ruta, tArbol *pa, unsigned tamDato, unsigned tamInfo, Cmp cmp, Indice indice)
{
    void *reg, *indi;
    unsigned pos=0;

    if(!(reg = malloc(tamInfo)) || !(indi=malloc(tamDato)))
    {
        free(reg);
        free(indi);
        return 0;
    }
    FILE* pf = fopen(ruta, "rb");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", ruta);
        free(reg);
        free(indi);
        return 0;
    }

    fread(reg, tamInfo, 1, pf);
    while(!(feof(pf)))
    {
        indice(reg, indi, pos);
        insertarOrdenadoArbol(pa,tamDato,indi,cmp);
        pos ++;
        fread(reg, tamInfo, 1, pf);
    }

    free(reg);
    free(indi);
    fclose(pf);
    return 1;
}

int crearArchivoIndice(const char* ruta, const tArbol* pa, Accion cargarDato)
{
    FILE* pf = fopen(ruta, "wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", ruta);
        return 0;
    }

    mapInOrdenArbol((tArbol*)pa, pf,cargarDato);

    fclose(pf);
    return 1;
}

int cargarIndice(const char* ruta, tArbol *pa, unsigned tamReg, Leer leer)
{
    unsigned tam;
    FILE* pf = fopen(ruta, "rb");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", ruta);
        return 0;
    }

    fseek(pf,0,SEEK_END);

    tam = (ftell(pf)/tamReg)-1;
    cargarDatosOrdenados(pa,pf,0, tam , &tamReg, leer);

    fclose(pf);
    return 1;
}

void indiceProducto (const void* info, void* dato, unsigned pos)
{
    tProducto* prod = (tProducto*) info;
    tIndiceProducto* indi = (tIndiceProducto*)dato;
    strcpy(indi->cod, prod->cod);
    indi->tipo=prod->tipo;
    indi->pos = pos;
}

int cmpIndiceProducto (const void* a, const void* b)
{
    tIndiceProducto* indi1 = (tIndiceProducto*)a;
    tIndiceProducto* indi2 = (tIndiceProducto*)b;


    if((indi1->tipo - indi2->tipo)==0)
    {
        return strcmpi(indi1->cod, indi2->cod);
    }

    return indi1->tipo - indi2->tipo;
}

void escribirIndice (void* info, void* cond)
{
    tIndiceProducto* indi = (tIndiceProducto*)info;
    FILE* pf = (FILE*)cond;

    fwrite(indi,sizeof(indi), 1, pf);
}

void mostrarIndice (void* info, void* cond)
{
    tIndiceProducto* indi = (tIndiceProducto*)info;
    printf("%s, %c, %d\n", indi->cod, indi->tipo, indi->pos);
}

void mostrarProductto (void* info, void* cond)
{
    tProducto* prod = (tProducto*)info;
    printf("%s, %c, %d\n", prod->cod, prod->tipo, prod->stock);
}

int leerIndiceProducto (void** info, void* parametros,unsigned pos, void* pf)
{
    int tam = *((int*)parametros);

    if(!(*info = malloc(tam)))
        return 0;

    fseek(pf, tam*pos, SEEK_SET);
    return fread(*info, tam, 1, (FILE*)pf);
}
