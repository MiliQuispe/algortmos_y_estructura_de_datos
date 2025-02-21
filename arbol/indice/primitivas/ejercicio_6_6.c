#include "ejercicio_6_6.h"

int cmpPersonas (const void * a, const void* b)
{
    tPersona* per1 = (tPersona*)a;
    tPersona* per2 = (tPersona*)b;

    return per1->dni - per2->dni;
}
int cmpDNI (const void * a, const void* b)
{
    tDni* per1 = (tDni*)a;
    tDni* per2 = (tDni*)b;

    return per1->dni - per2->dni;
}
void extraerArchivoBinPersonas (void* info, void* cond, void* parametros)
{
    tPersona* per = (tPersona*)info;
    int *pos = ((int*)parametros);
    tArbol *pa = (tArbol* )cond;

    tDni dni;
    dni.dni = per->dni;
    dni.pos = *pos;

    *pos = *pos +1;

    insertarOrdenadoArbol(pa, sizeof(tDni), &dni ,cmpDNI);
}

void grabarArchivoBinDNI (void* info, void* cond, void* parametros)
{
    tDni* dni = (tDni*)info;
    FILE* pf = (FILE*) cond;

    fwrite(dni, sizeof(tDni), 1 ,pf);
}


void mostrarDni (void* info, void* cond, void* parametros)
{
    tDni* per = (tDni*)info;

    printf("%d, %d\n", per->dni, per->pos);
}
unsigned leerRgistroArchivoBin (void** info, unsigned pos, void* datos, void* parametros)
{
    int tam = *((int*)parametros);

    if(!((*info)= malloc(tam)))
        return 0;

    fseek((FILE*)datos, pos * (tam), SEEK_SET);
    return fread(*info, tam, 1, (FILE*)datos);
}

////////////// lote

//    char nombre[TAM_NOMBRE];
//    char apellido[TAM_APELLIDO];
//    unsigned dni;
//    int edad;

int crearLote()
{
    tPersona pers[]=
    {
        {"MP","Q",34, 23},
        {"LS","K",28, 19},
        {"TY","S",67, 14},
        {"HE","D",47, 20},
        {"SJ","Y",12, 56},
        {"XU","H",25, 44},
        {"UD","G",39, 41},
        {"LA","A",17, 19}
    };

    return cargarArchivoBin("personas.dat", pers, sizeof(pers));
}

int cargarArchivoBin(const char* ruta, void* datos, unsigned tamDatos)
{
    FILE*pf = fopen(ruta,"wb");
    if(!pf)
    {
        printf("No se puede crear  el archivo %s", ruta);
        return 0;
    }

    fwrite(datos, tamDatos, 1, pf);

    fclose(pf);
    return 1;
}

///////////////////// ordenar archivo

int cargarArbolArchivoBin(const char* ruta, tArbol *pa, unsigned tam, void* parametros, Cmp cmp, Accion accion)
{
    void* aux = malloc(tam);

    if(!aux)
        return 0;

    FILE*pf = fopen(ruta,"rb");
    if(!pf)
    {
        printf("No se puede crear  el archivo %s", ruta);
        free(aux);
        return 0;
    }

    fread(aux, tam, 1, pf);

    while(!feof(pf))
    {
        accion(aux, pa, parametros);
        fread(aux, tam, 1, pf);
    }

    fclose(pf);
    free(aux);
    return 1;
}

//////////////////////////// idx

int cargarArchiboBinDesdeArbol(const char* ruta, tArbol *pa, Accion accion)
{
    int pos =0;
    FILE*pf = fopen(ruta,"wb");
    if(!pf)
    {
        printf("No se puede crear  el archivo %s", ruta);
        return 0;
    }

    mapInOrdenArbol(pa, pf, &pos, accion);

    fclose(pf);
    return 1;
}



int cargarArbolArchivoBinOrdenado(const char* ruta, tArbol *pa, unsigned tam, Leer leer)
{
    int fin;
    FILE*pf = fopen(ruta,"rb");
    if(!pf)
    {
        printf("No se puede abrir el archivo %s", ruta);
        return 0;
    }

    fseek(pf, 0, SEEK_END);
    fin = ((ftell(pf))/ tam) - 1;
    fseek(pf, 0, SEEK_SET);

    cargarDatosOrdenados(pa, 0, fin, pf, &tam, leer);

    fclose(pf);
    return 1;
}
