#include "ejercicio_2_6.h"

/// crear lote

int crearLote()
{
    tAlumno alu[]=
    {
        {"alejandra","triz",13,5.6},
        {"monica","yug",15,7.8},
        {"luz","kess",13,5.6},
        {"ana","troya",12,4.2},
        {"jazmin","yim",15,6.8},
        {"laura","koy",12,9},
        {"manuela","thers",13,3.8}
    };

    return crearArchivoBin("dato.bin",alu,sizeof(alu));
}

int crearArchivoBin (const char* ruta, const void* datos, unsigned tamDatos)
{
    FILE* pf = fopen(ruta, "wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", ruta);
        return 0;
    }

    fwrite(datos, tamDatos,1, pf);
    fclose(pf);
    return 1;
}

/// crear Archivos dato1 y dato2

int crearYmostrarArchivoBinPila(const char* ruta, tPila *p, unsigned tamDato, Mostrar mostrar)
{
    void* aux = malloc(tamDato);
    if(!aux)
        return 0;

    FILE* pf = fopen(ruta, "wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", ruta);
        free(aux);
        return 0;
    }

    while(!siEsPilaVacia(p))
    {
        sacarEnPila(p,tamDato, aux);
        mostrar(aux);
        fwrite(aux,tamDato,1,pf);
    }

    free(aux);
    fclose(pf);
    return 1;
}
int crearYmostrarArchivoBinCola(const char* ruta, tCola *pc, unsigned tamDato, Mostrar mostrar)
{
    void* aux = malloc(tamDato);
    if(!aux)
        return 0;

    FILE* pf = fopen(ruta, "wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", ruta);
        free(aux);
        return 0;
    }

    while(!siEsColaVacia(pc))
    {
        sacarEnCola(pc,tamDato, aux);
        mostrar(aux);
        fwrite(aux,tamDato,1,pf);
    }

    free(aux);
    fclose(pf);
    return 1;
}

int crearArchivosDatosI(const char* rutaOriginal, const char* ruta1, const char* ruta2, const void* condi, Condicion condicion)
{
    tPila p;
    tCola pc;
    tAlumno alu;

    FILE* pf= fopen(rutaOriginal,"rb");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", rutaOriginal);
        return 0;
    }

    crearCola(&pc);
    crearPila(&p);

    printf("\nDato\n");
    fread(&alu, sizeof(alu), 1, pf);

    while(!feof(pf))
    {
        if(condicion(&alu,condi))
        {
            printf("%s, %s, %d, %f\n",alu.nombre, alu.apeliido, alu.edad, alu.promedio);
            ponerEnCola(&pc, sizeof(tAlumno), &alu);
            ponerEnPila(&p, sizeof(tAlumno), &alu);
        }

        fread(&alu, sizeof(alu), 1, pf);
    }

    printf("\nDato 1\n");
    crearYmostrarArchivoBinPila(ruta1,&p,sizeof(tAlumno),mostrarAlumno);
    printf("\nDato 2\n");
    crearYmostrarArchivoBinCola(ruta2,&pc,sizeof(tAlumno),mostrarAlumno);


    fclose(pf);
    return 1;
}

int alumnoConLaLetra (const void* dato, const void* condi)
{
    tAlumno* alu = (tAlumno*) dato;
    char* comparador = (char*) condi;

    return *comparador == *(alu->apeliido);
}

void mostrarAlumno (const void* dato)
{
    tAlumno* alu = (tAlumno*) dato;

    printf("%s, %s, %d, %f\n",alu->nombre, alu->apeliido, alu->edad, alu->promedio);
}
