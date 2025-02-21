#include "articulos.h"

void prueba()
{
    int vec[]={1,2,3,4,5};
    int i,aux;

    tCola pc;
    crearCola(&pc);

    for(i=0 ; i<5; i++)
    {
        ponerEnCola(&pc, sizeof(int), vec+i);
    }

    for(i=0 ; i<8; i++)
    {
        sacarEnCola(&pc, sizeof(int), &aux);
        printf("%d\t",aux);
    }
}


// crear lote

//
//    char codArt[TAM_ART];
//    char codMat[TAM_MAT];
//    int cantidad;
//    float costoU;

int crearLote()
{
    tArticulo art[]=
    {
        {"HGFK","KLHF",12, 34.56},
        {"HGFK","FTES",4, 78.2},
        {"HGFK","PQKS",56, 9.23},
        {"HGFK","CAIV",67, 5.98},
        {"JUTS","FTES",15, 78.2},
        {"JUTS","ZXRT",67, 5.98},
        {"QMNV","KLHF",3,34.56},
        {"QMNV","CAIV",6, 5.98},
        {"QMNV","PQKS",11, 9.23},
        {"QMNV","ZXRT",8, 5.98},
        {"QMNV","FTES",1, 78.2},
    };

    return crearArchivoBin("articulos.bin", art, sizeof(art));
}

int crearArchivoBin (const char* ruta, const void* datos, unsigned tamDatos)
{
    FILE* pf= fopen(ruta,"wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", ruta);
        return 0;
    }

    fwrite(datos, tamDatos, 1, pf);
    fclose(pf);
    return 1;
}

int verArchivoArticulo(const char* ruta)
{
    tArticulo art;

    FILE *pf = fopen(ruta,"rb");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", ruta);
        return 0;
    }

    fread(&art, sizeof(tArticulo), 1, pf);
    while(!feof(pf))
    {
        printf("%s,%s, %d, %f\n", art.codArt, art.codMat, art.cantidad, art.costoU);
        fread(&art, sizeof(tArticulo), 1, pf);
    }

    fclose(pf);
    return 1;
}

// separar articulos

int crearArchivos(const char* ruta, float limite)
{

    tArticulo art,aux;
    char codArt[TAM_ART];
    float PrecioTotal;
    tCola pc;

    FILE *pf = fopen(ruta,"rb");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", ruta);
        return 0;
    }

    FILE *psup = fopen("articulosSuperiorAlLimite","wb");
    if(!psup)
    {
        printf("No se pudo abrir el archivo ");
        fclose(pf);
        return 0;
    }
    FILE *pinf = fopen("articulosIgualInferiorAlLimite","wb");
    if(!pinf)
    {
        printf("No se pudo abrir el archivo ");
        fclose(pf);
        fclose(psup);
        return 0;
    }

    crearCola(&pc);

    fread(&art, sizeof(tArticulo), 1, pf);

    while(!feof(pf))
    {
        strcpy(codArt, art.codArt);
        PrecioTotal =0;

        while(strcmpi(codArt, art.codArt) == 0 && !feof(pf))
        {
            PrecioTotal += art.cantidad * art.costoU;

            ponerEnCola(&pc, sizeof(tArticulo), &art);

            fread(&art, sizeof(tArticulo), 1, pf);
        }

        while(!siEsColaVacia(&pc))
        {
            sacarEnCola(&pc, sizeof(tArticulo), &aux);
            if(limite < PrecioTotal)
                fwrite(&aux, sizeof(tArticulo), 1, psup);
            else
                fwrite(&aux, sizeof(tArticulo), 1, pinf);
        }

    }

    fclose(pf);
    fclose(psup);
    fclose(pinf);
    return 1;

}
