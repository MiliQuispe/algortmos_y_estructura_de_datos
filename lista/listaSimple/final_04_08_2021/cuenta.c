#include "cuenta.h"

///   unsigned numeroDeCuenta;
///   char tipoDeCuenta[TAM_TIPO_DE_CUENTA];
///   char apellido[TAM_APELLIDO];
///   unsigned extensionClave;
///   float saldo;

int crearLote()
{
    tCuenta cuenta[]=
    {
        {1234,"FB","QUIROGA", 123, 1234},
        {5678,"FB","QUISPE", 567, 5678},
        {9123,"IK","PEREZ", 568, 3000},
        {5678,"IK","RODRIGUEZ", 561, 1000},
        {9123,"FB","DIAZ", 235, 4000},
        {1234,"BH","QUIROGA", 234, 1000},
        {1234,"BH","SOLIZ", 341, 2000},
        {9123,"IK","PEREZ", 912, 9123},
        {5678,"BH","RODRIGUEZ", 612, 2000},
        {9123,"BH","PEREZ", 124, 1000},
        {1234,"IK","SOLIZ", 412, 3000},
        {1234,"FB","QUIROGA", 127, 4000}
    };
    return crearArchivoTXT("cuentas.txt", cuenta, sizeof(tCuenta), 12, formatoCuentaW);
}

int crearArchivoTXT(const char* ruta, const void* datos, unsigned tamDato, unsigned ce, FormatoEsbribir formato)
{

    FILE* pf= fopen(ruta,"wt");
    if(!pf)
    {
        printf("No se pude crear el archivo %s", ruta);
        return 0;
    }
    while(ce>0)
    {
        formato(pf,datos);
        datos = datos + tamDato;
        ce--;
    }
    fclose(pf);
    return 1;
}

int crearListaOrdenadaConArchivoTXT(const char* ruta, tLista *pl, unsigned tamDato, FormatoLeer formato, Cmp cmp)
{
    char linea[TAM_LINEA];
    void* aux = malloc(tamDato);
    if(!aux)
        return 0;

    FILE* pf= fopen(ruta,"rt");
    if(!pf)
    {
        printf("No se pude abrir el archivo %s", ruta);
        free(aux);
        return 0;
    }

    while(fgets(linea, TAM_LINEA, pf))
    {
        formato(linea,aux);
        insertarOrdenado(pl,tamDato, aux, cmp);
    }

    free(aux);
    fclose(pf);
    return 1;
}

int crearArchivoBINConLista(const char* ruta, tLista *pl, Accion guardar)
{

    FILE* pf= fopen(ruta,"wb");
    if(!pf)
    {
        printf("No se pude crear el archivo %s", ruta);
        return 0;
    }

    mapLista(pl, pf, guardar);

    fclose(pf);
    return 1;
}

//
int cmpCuentas (const void* a, const void* b)
{
    tCuenta* cuenta1 =(tCuenta*)a;
    tCuenta* cuenta2 =(tCuenta*)b;
    int rest;

    rest = cuenta1->numeroDeCuenta - cuenta2->numeroDeCuenta;
    if(rest ==0)
    {
        rest = strcmp(cuenta1->tipoDeCuenta, cuenta2->tipoDeCuenta);
        if(rest ==0)
            return cuenta1->extensionClave - cuenta2->extensionClave;
    }
    return rest;
}

void formatoCuentaW (FILE* pf, const void* dato)
{
    tCuenta* cuenta =(tCuenta*)dato;

    fprintf(pf, "%d; %s; %s; %d; %f\n",cuenta->numeroDeCuenta, cuenta->tipoDeCuenta, cuenta->apellido, cuenta->extensionClave, cuenta->saldo);
}
void formatoCuentaR (const char* linea, const void* dato)
{
    tCuenta* cuenta =(tCuenta*)dato;

    sscanf(linea,"%d; %[^;]; %[^;]; %d; %f\n", &cuenta->numeroDeCuenta, cuenta->tipoDeCuenta, cuenta->apellido, &cuenta->extensionClave, &cuenta->saldo);
}

void mostrarCuenta (void* cond, void* info)
{
    tCuenta* cuenta =(tCuenta*)info;

    printf("%d %s %d %s %f\n",cuenta->numeroDeCuenta, cuenta->tipoDeCuenta, cuenta->extensionClave, cuenta->apellido, cuenta->saldo);
}

void guardarCuenta (void* cond, void* info)
{
    tCuenta* cuenta =(tCuenta*)info;
    FILE* pf = (FILE*)cond;

    fread( cuenta,sizeof(tCuenta), 1, pf);
}
