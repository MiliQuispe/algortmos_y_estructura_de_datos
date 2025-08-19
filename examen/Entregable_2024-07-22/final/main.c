#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <arbol.h>

void imprimir_mensaje(int res);
void op_alta(t_arbol * pa);
void op_baja(t_arbol * pa);
void op_informe_materias_aprobadas(const t_arbol * pa);
void op_mostrar_arbol(const t_arbol * pa);
void op_listar_materias(const t_arbol * pa);
void op_validar_arbol(const t_arbol * pa);
int main()
{
    const char opciones [][TAM_MENU] = {"ABMILVS","Cargar Nota", "Baja Nota", "Mostrar Arbol", "Informe Materias Aprobadas", "Listar Materias","Validar Arbol", "Salir"};
    char op;
    t_arbol arbol;
    crear_arbol_res(&arbol);
    cargar_arbol_de_archivo_ordenado_res(&arbol,"..\\archivos\\materias.dat");
    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'A':
                op_alta(&arbol);
                break;
            case 'B':
                op_baja(&arbol);
                break;
            case 'M':
                op_mostrar_arbol(&arbol);
                break;
            case 'I':
                op_informe_materias_aprobadas(&arbol);
                break;
            case 'L':
                op_listar_materias(&arbol);
                break;
            case 'V':
                op_validar_arbol(&arbol);
                break;
        }
    }while(op!='S');
    grabar_arbol_en_archivo_ordenado_res(&arbol,"..\\archivos\\materias.dat");
    vaciar_arbol_res(&arbol);
    return 0;
}

void op_alta(t_arbol * pa)
{
    int res;
    res= alta_res(pa);
    imprimir_mensaje(res);
}

void op_baja(t_arbol * pa)
{
    int res;
    res= baja_res(pa);
    imprimir_mensaje(res);
}

void op_mostrar_arbol(const t_arbol * pa)
{
    printf("\n\n");
    arbol_grafico_res(pa, mostrar_clave_res);
    pausa("\n\n");
}

void op_informe_materias_aprobadas(const t_arbol * pa)
{
    int res;
    printf("\n\n");
//    res = informe_materias_aprobadas_res(pa);
    res = informe_materias_aprobadas(pa);
    imprimir_mensaje(res);
}

void op_listar_materias(const t_arbol * pa)
{
    printf("\n\n");
    imprimir_listado_res(pa);
    pausa("\n\n");
}

void op_validar_arbol(const t_arbol * pa)
{
    printf("\n\n");
    validar_arbol_res(pa);
    pausa("\n\n");
}

void imprimir_mensaje(int res)
{
    switch(res)
    {
        case TODO_OK: pausa("Operacion realizada correctamente.");
                break;
        case SIN_MEM: pausa("Error de memoria.");
                break;
        case ERROR_ARCHIVO: pausa("Error en el archivo.");
                break;
        case DUPLICADO: pausa("Registro duplicado.");
                break;
        case NO_EXISTE: pausa("Registro inexistente.");
                break;
    }
}
