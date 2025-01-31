#include "manejo_de_archivos.h"

int crearArchivoBinario (const char* ruta, const void* datos, unsigned tamDatos)
{
    FILE*pf= fopen(ruta, "wb");
    if(!pf)
    {
        printf("\nNo se pudo crear el archivo %s", ruta);
        return 0;
    }

    fwrite(datos,tamDatos,1,pf);

    fclose(pf);
    return 1;
}
int crearArchivoTexto (const char* ruta, const void* datos, unsigned tamDato, unsigned ce, FormatoGuardar formato)
{
    int i;
    FILE*pf= fopen(ruta, "wt");
    if(!pf)
    {
        printf("\nNo se pudo crear el archivo %s", ruta);
        return 0;
    }

    for(i=0; i<ce; i++)
    {
        formato(pf,datos);
        datos= datos + tamDato;
    }

    fclose(pf);
    return 1;
}

int cargarPilaBin (const char* ruta, tPila *p, unsigned tamDato)
{
    void* aux = malloc(tamDato);
    if(!aux)
        return 0;

    FILE*pf= fopen(ruta, "rb");
    if(!pf)
    {
        printf("\nNo se pudo abrir el archivo %s", ruta);
        free(aux);
        return 0;
    }

    fread(aux,tamDato,1,pf);
    while(feof(pf))
    {
        ponerEnPila(p,tamDato,aux);
        fread(aux,tamDato,1,pf);
    }

    free(aux);
    fclose(pf);
    return 1;
}
int cargarPilaTXT (const char* ruta, tPila *p, unsigned tamDato, unsigned tamLinea, FormatoExtraer formato)
{

    void* linea, *dato;
    if(!(linea = malloc(tamLinea)) || !(dato = malloc(tamDato)))
    {
        free(linea);
        return 0;
    }


    FILE*pf= fopen(ruta, "rt");
    if(!pf)
    {
        printf("\nNo se pudo abrir el archivo %s", ruta);
        free(linea);
        free(dato);
        return 0;
    }

    while(fgets(linea,tamLinea,pf))
    {
        formato(linea,dato);
        ponerEnPila(p,tamDato,dato);
    }

    free(linea);
    free(dato);
    fclose(pf);
    return 1;
}
