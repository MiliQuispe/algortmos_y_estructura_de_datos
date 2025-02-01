#include "ejercicios.h"


void prueba()
{
    int vec[] ={1,2,3,4,5};
    int i,aux=-1;

    tPila p;
    crearPila(&p);

    for(i=0; i<5; i++)
    {
        ponerEnPila(&p,sizeof(int), vec+i);
    }
    vaciarPila(&p);

    for(i=0; i<8; i++)
    {
        verTope(&p,sizeof(int), &aux);
        printf("%d\t", aux);
        sacarEnPila(&p,sizeof(int), &aux);
    }
}

int crearLote()
{
    tAlumno alums[]=
    {
        {"a","1a",1,1.5},
        {"b","2b",2,2.5},
        {"c","3c",3,3.5},
        {"d","4d",4,4.5},
        {"e","5e",5,5.5}
    };

    return crearArchivoBinario("datos.bin",alums,sizeof(alums));
}

int ejercicio_2_5()
{
    tPila p;
    int opcion;
    tAlumno alu;

    crearPila(&p);
    crearLote();


    printf("%d\n",cargarPilaBin("datos.bin",&p,sizeof(tAlumno)));
    printf("%d\n",siEsPilaVacia(&p));

    do
    {
        printf("\nMENU"
               "\n1-agregar Alumno"
               "\n2-Quitar ultimo Alumno"
               "\n3-Ver ultimo Alumno"
               "\n4-Salir");
        printf("\nOpcion:");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\nNombre: ");
                scanf("%s",alu.nombre);
                printf("\nApellido");
                scanf("%s",alu.apellido);
                printf("\nEdad: ");
                scanf("%d",&alu.edad);
                printf("\nPromedio: ");
                scanf("%f",&alu.promedio);
                break;
            case 2:
                if(sacarEnPila(&p,sizeof(tAlumno),&alu))
                    printf("\nUltimo alumno sacado: %s, %s, edad: %d, promedio:%f",alu.nombre, alu.apellido, alu.edad, alu.promedio);
                else
                    printf("\nLa pila esta vacia\n");
                break;


            case 3:
                if(verTope(&p,sizeof(tAlumno),&alu))
                    printf("\nEl ultimo alumno fue: %s, %s, edad: %d, promedio:%f",alu.nombre, alu.apellido, alu.edad, alu.promedio);
                else
                    printf("\nLa pila esta vacia\n");
                break;

            case 4:
                printf("\nSaliendo...");
                break;
            default:
                printf("\nIngrese una opcion correcta\n");
                break;

        }

    }while(opcion !=4);

    if(siEsPilaVacia(&p))
    {
        remove("datos.bin");
        return 0;
    }

    cargarArchiboBinPila("datos.bin",&p,sizeof(tAlumno));
    return 1;

}


