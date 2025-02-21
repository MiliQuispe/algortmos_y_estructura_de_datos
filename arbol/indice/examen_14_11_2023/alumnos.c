#include "alumnos.h"

/// lote

///    char nombre[TAM_NOMBRE];
///    char apellido[TAM_APELLIDO];
///    unsigned dni;
///   char estado;


int crearLote()
{
    tAlumnos alum[]=
    {
        {"MP","Q", 35, 'A'},
        {"RH","H", 47, 'A'},
        {"ZT","W", 16, 'A'},
        {"NE","S", 33, 'A'},
        {"AT","U", 59, 'A'},
        {"EP","V", 11, 'A'},
        {"QK","J", 72, 'A'},
        {"JF","S", 83, 'A'}
    };
    return crearArchivoBin("alumnos.dat", alum, sizeof(alum));
}

int crearArchivoBin(const char* rutaDat, const void* datos, unsigned tamDatos)
{
    FILE  *pf = fopen(rutaDat,"wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", rutaDat);
        return 0;
    }

    fwrite(datos, tamDatos, 1,pf);

    fclose(pf);
    return 1;
}

///indice

void extraeDni (void* registro, tArbol *pa, unsigned pos)
{
    tAlumnos *alum = (tAlumnos*)registro;
    tDni dni ;

    dni.dni = alum->dni;
    dni.pos = pos;

    insertarOrdenadoArbol(pa, sizeof(tDni), &dni, cmpDni);
}

int cmpDni (const void* a, const void* b)
{
    tDni* dni1 = (tDni*)a;
    tDni* dni2 = (tDni*)b;
    return dni1->dni - dni2->dni;
}

void escribirArchivoAlumnosIdx (void* info, void* cond)
{
    tDni* dni = (tDni*)info;
    FILE* pf = (FILE*) cond;

    fwrite(dni, sizeof(tDni),1,pf);

}

unsigned leerArchivoIdx (void** info, unsigned pos, void* datos, void* parametros)
{
    FILE* pf =(FILE*) datos;
    int tam = *((int*)parametros);

    if(!(*info = malloc(tam)))
        return 0;
    fseek(pf, pos * tam, SEEK_SET);

    return fread(*info, tam, 1, pf);

}

int cargarArbol_archBin(const char* rutaDat, tArbol *pa, unsigned tamDato, ExtraerIndice extraer) // no balanceado
{
    void* aux = malloc(tamDato);
    int pos=0;

    if(!aux)
        return 0;

    FILE  *pf = fopen(rutaDat,"rb");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", rutaDat);
        free(aux);
        return 0;
    }

    fread(aux, tamDato, 1, pf);
    while(!feof(pf))
    {
        extraer(aux, pa,pos);
        pos ++;
        fread(aux, tamDato, 1, pf);
    }

    free(aux);
    return 1;
}

int cargarArchivoIDX_arbol (const char* rutaIdx, tArbol *pa, Accion escribir)
{
    FILE  *pf = fopen(rutaIdx,"wt");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", rutaIdx);
        return 0;
    }

    mapInOrden(pa, pf, escribir);

    fclose(pf);
    return 1;
}

int cargarArbol_archIdx (const char* rutaIdx, tArbol *paIdx, unsigned tam, Leer leer)
{
    int fin;
    FILE  *pf = fopen(rutaIdx,"rt");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", rutaIdx);
        return 0;
    }

    fseek(pf, 0, SEEK_END);
    fin = (ftell(pf)/tam) -1;
    fseek(pf, 0, SEEK_SET);

    cargarArbolIdx (paIdx, 0, fin, pf, &tam, leer);
    fclose(pf);
    return 1;
}

/// menu
int altasYbajasDeLosAlumnos(const char* rutaDat)
{
    int opcion;
    tArbol pa;

    crearArbol(&pa);

    if(crearLote() && cargarArbol_archBin("alumnos.dat", &pa, sizeof(tAlumnos), extraeDni) && cargarArchivoIDX_arbol("alumnos.idx",&pa, escribirArchivoAlumnosIdx))
    {
//        mapInOrden(&pa, NULL,mostrarIndice);
        vaciarArbol(&pa);
        crearArbol(&pa);
        if(cargarArbol_archIdx("alumnos.idx",&pa, sizeof(tDni),leerArchivoIdx))
        {
//            mapInOrden(&pa, NULL,mostrarIndice);
//            bajaAlumnos("alumnos.dat",&pa);


            do
            {
                mapInOrden(&pa, NULL,mostrarIndice);

                printf("\nMenu\n1- Bajar Alumno\n2- Grabar arbol binario de indice en un archivo binario\n"
                         "3-Vaciar el arbol de indice\n4- Salir\nOpcion:\t");
                scanf("%d",&opcion);

                switch(opcion)
                {
                    case 1:

                        if(!siesArbolvacio(&pa))
                            bajaAlumnos("alumnos.dat",&pa);
                        else
                            printf("\nNo se puede realizar la operacion por que el arbol esta vacio\n");

                        break;
                    case 2:
                        guardarIndice("nuevoAlumnos.idx",&pa, escribirArchivoAlumnosIdx);
                        vaciarArbol(&pa);
                        crearArbol(&pa);
                        cargarArbol_archIdx("alumnos.idx",&pa, sizeof(tDni),leerArchivoIdx);
                        mapInOrden(&pa, NULL,mostrarIndice);

                        break;
                    case 3:

                        printf("\nEliminando arbol de indice\n");
                        vaciarArbol(&pa);

                        break;
                    case 4:
                        printf("\nSaliendo\n");
                    case 5:
                        mapInOrden(&pa, NULL,mostrarIndice);

                        break;
                    default:
                        printf("\nSelecione una opcion correcta\n");
                        break;
                }
            }while(opcion !=4);

            vaciarArbol(&pa);

            return 1;
        }

    }
    return 0;
}

/// opcion 1

int bajaAlumnos (const char* rutaDat, tArbol *paIdx)
{
    int opcion;
    tDni dni;
    do
    {
        mapInOrden(paIdx, NULL,mostrarIndice);

        printf("\nMenu 1\n1- Ingresar dni del alumno\n2- Salir\nOpcion:\t");
        scanf("%d",&opcion);
        switch(opcion)
                {
                    case 1:
                        printf("\nDni:\t");
                        scanf("%d",&dni.dni);

                        if(eliminarRaizArbol((tArbol*)buscarNodoArbol(paIdx,&dni,cmpDni), sizeof(tDni), &dni))
                            actualizarBaja("alumnos.dat",dni.pos);
                        else
                            printf("\nIngrese un dni correcto\n");

                        break;
                    case 2:
                        printf("\nSaliendo\n");

                        break;
                    default:


                        printf("\nSelecione una opcion correcta\n");
                        break;
                }
    }while(opcion !=2);

    return 1;
}

int actualizarBaja (const char* rutaDat, unsigned pos)
{
    tAlumnos alu;
    unsigned tamReg;
    FILE  *pf = fopen(rutaDat,"r+b");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", rutaDat);
        return 0;
    }

    if(fseek(pf,1,SEEK_SET)==0)
    {
//        tamReg = ftell(pf);
        tamReg = sizeof(tAlumnos);

        fseek(pf, pos * tamReg, SEEK_SET);

        fread(&alu, sizeof(tAlumnos), 1, pf);
        fseek(pf, -1 * tamReg, SEEK_CUR);

        alu.estado = 'B';
        fwrite(&alu, sizeof(tAlumnos), 1, pf);
    }


    fclose(pf);
    return 1;
}

// eliminar en el indice ya en arbol.h

///opcion 2

int guardarIndice(const char* rutaIdx, const tArbol *paIdx, Accion accion)
{

    FILE  *pf = fopen(rutaIdx,"wt");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", rutaIdx);
        return 0;
    }

    mapInOrden((tArbol*)paIdx,pf, accion);

    fclose(pf);
    return 1;
}

/// opcion 3

//vaciar arbol en arbol.h

void mostrarIndice (void* info, void* cond)
{
    tDni* dni = (tDni*)info;
    printf("\n%d, %d\n", dni->dni,dni->pos);
}
