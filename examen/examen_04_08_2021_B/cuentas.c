#include "cuentas.h"
int crearLote()
{
        tCuenta cuentas[]=
    {
        {22, "EE", "EE11", 20, 22.5},
        {33, "CC", "CC11", 60, 66.5},
        {11, "AA", "AA11", 10, 11.5},
        {33, "FF", "FF11", 30, 33.5},
        {55, "BB", "BB11", 50, 55.5},
        {22, "DD", "DD11", 40, 44.5}
    };

    return crearArchivoTxt("cuentas.txt", cuentas, sizeof(tCuenta), 6, escribirCuenta);
}

int crearArchivoTxt(const char* ruta, const void* datos, unsigned tamDato, int ce, FormatoEscribir escribir)
{
    int i;

    FILE* pf = fopen(ruta,"wt");
    if(!pf)
    {
        printf("No se pudo crear archivo %s\n", ruta);
        return 0;
    }

    for(i=0; i<ce; i++)
    {
        escribir(datos, pf);
        datos = datos + tamDato;
    }

    fclose(pf);
    return 1;
}

int cargarListaArchivoTxt(const char* ruta, tLista *pl, unsigned tamDato, Cmp cmp, FormatoLeer leer)
{
    char linea[TAM_LINEA];
    void* aux;

    if(!(aux = malloc(tamDato)))
        return 0;

    FILE* pf = fopen(ruta,"rt");
    if(!pf)
    {
        printf("No se pudo abrir archivo %s\n", ruta);
        free(aux);
        return 0;
    }

    while(fgets(linea, TAM_LINEA, pf))
    {
        leer(linea,aux);
        insertarOrdenadoLista(pl, tamDato, aux, cmp);
    }

    fclose(pf);
    free(aux);
    return 1;
}

int guardarListaArchivoBin(const char* ruta, tLista *pl, unsigned tamInfo)
{
    void* aux;

    if(!(aux = malloc(tamInfo)))
        return 0;

    FILE* pf = fopen(ruta,"wb");
    if(!pf)
    {
        printf("No se pudo crear archivo %s\n", ruta);
        free(aux);
        return 0;
    }

    while(!siEsListaVacia(pl))
    {
        eliminarPrimeroLista(pl, tamInfo, aux);
        fwrite(aux, tamInfo, 1, pf);
    }

    fclose(pf);
    free(aux);
    return 1;
}


//////////////

void escribirCuenta (const void* dato, FILE* pf)
{
    tCuenta* cuenta = (tCuenta*)dato;

    fprintf(pf,"%d;%s;%s;%d;%f\n", cuenta->nroCuenta, cuenta->tipoCuenta, cuenta->apellido, cuenta->extClave, cuenta->saldo);
}

void leerCuenta (const char* linea, void* dato)
{
   tCuenta* cuenta = (tCuenta*)dato;

   sscanf(linea,"%d;%[^;];%[^;];%d;%f\n", &cuenta->nroCuenta, cuenta->tipoCuenta, cuenta->apellido, &cuenta->extClave, &cuenta->saldo);
}

int cmpCuenta (const void* a, const void* b)
{
    tCuenta* cuenta1 = (tCuenta*)a;
    tCuenta* cuenta2 = (tCuenta*)b;

    if((cuenta1->nroCuenta - cuenta2->nroCuenta) ==0)
    {
        if(strcmpi(cuenta1->tipoCuenta, cuenta2->tipoCuenta) ==0)
        {
            return cuenta1->extClave - cuenta2->extClave;
        }
        return strcmpi(cuenta1->tipoCuenta, cuenta2->tipoCuenta);
    }
    return (cuenta1->nroCuenta - cuenta2->nroCuenta);
}

void mostrarCuenta (void* info, void* cond)
{
    tCuenta* cuenta = (tCuenta*)info;
    printf("%d, %s, %s, %d, %f\n", cuenta->nroCuenta, cuenta->tipoCuenta, cuenta->apellido, cuenta->extClave, cuenta->saldo);
}
