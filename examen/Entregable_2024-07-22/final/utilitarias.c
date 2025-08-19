#include<utilitarias.h>
#include<string.h>
#include<varias.h>
#include<ctype.h>

//#include"../include/arbol.h"

typedef struct
{
    int dni;
    int materiasAprobadas;
    float sumaNotas;
    t_arbol pAux;
}t_informe;


int informe_materias_aprobadas(const t_arbol *pa)
{
    t_informe info;
    t_info alu;
    char linea[TAM_NOMBRE_ARCH];
    int res;
    FILE*pf;

    printf("\nIngrese el dni del alumno:\t");
    scanf("%d",&alu.dni);

    if((res = buscar_en_arbol_bin_busq_res(pa, &alu, cmpDNI)) ==FALSO)
        return NO_EXISTE;

    sprintf(linea, "Materias_Aprobadas_%d.txt", alu.dni);
    pf = fopen(linea, "wt");
    if(!pf)
        return ERROR_ARCHIVO;

    fprintf(pf, "\tINFORME DE MATERIAS APROBADAS\n-------------DNI: %d-------------\n", alu.dni);

    crear_arbol_res(&info.pAux);
    info.materiasAprobadas=0;
    info.sumaNotas=0;
    info.dni = alu.dni;

    recorrer_arbol_en_res(pa, guardarMateriasAprobadas, &info);
    if(info.materiasAprobadas==0)
    {
        fclose(pf);
        return NO_EXISTE;
    }

    fprintf(pf, "Materias aprobadas: %d\tPromedio: %f\n\n", info.materiasAprobadas, info.sumaNotas/info.materiasAprobadas);
    fprintf(pf, "Materia   Periodo   \tNota\n");

    recorrer_arbol_en_res(&info.pAux, grabarMateriasAprobadas, pf);

    vaciar_arbol_res(&info.pAux);

    fclose(pf);
    return TODO_OK;
}

int cmpDNI(const t_info*a, const t_info*b)
{
    return a->dni- b->dni;
}

int cmpMateria(const t_info*a, const t_info*b)
{
    return strcmp(a->materia, b->materia);
}

void grabarMateriasAprobadas (t_info* pinfo, void* datos_accion)
{
    FILE* pf = (FILE*) datos_accion;

    fprintf(pf, "%-10s %4d-%-3d\t%d\n", pinfo->materia, pinfo->anio, pinfo->periodo, pinfo->nota);
}

void guardarMateriasAprobadas (t_info* pinfo, void* datos_accion)
{
    t_informe* info = (t_informe*)datos_accion;

    if(pinfo->dni == info->dni)
    {
        if(pinfo->nota>=4)
        {
            info->materiasAprobadas++;
            info->sumaNotas += pinfo->nota;
            insertar_en_arbol_bin_busq_res(&(info->pAux), pinfo, cmpMateria);
        }
    }
}
