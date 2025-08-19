#include "libro.h"

///////

int menu()
{
    int opcion, subOpcion ;
    tPalabra mayor, menor;
    tArbol pa;

    crearArbol(&pa);

    mayor.cantApariciones =0;
    menor.cantApariciones =0;

    if(procesarLibro("libro.txt", &pa,&mayor))
    {
        do
        {
            printf("\nMENU\n1-Ver la lista de palabras con la cantidad de repeticiones"
                   "\n2-La palabra con mayor cantidad de repeticiones"
                   "\n3-La palabra con menor cantidad de repeticiones"
                   "\n4-Salir\nopcion:\t");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    do
                    {
                        printf("\nMENU\n1-Ver la lista en orden ascendente"
                               "\n2-Ver la lista en orden descendente"
                               "\n3-Salir\nopcion:\t");
                        scanf("%d",&subOpcion);
                        switch(subOpcion)
                        {


                            case 1:
                                printf("\n");
                                mapInOrdenArbol(&pa,NULL,mostrarPalabra);

                                break;
                            case 2:
                                printf("\n");
                                mapInOrdenArbolInverso(&pa,NULL,mostrarPalabra);
                                break;
                            case 3:
                                printf("\nSaliendo\n");
                                break;

                            default:
                                printf("\nSeleccione una opcion correcta\n");
                                break;
                        }

                    }while(subOpcion !=3);

                    break;

                case 2:

                    printf("\nMayor:\t%s, %d\n",mayor.palabra, mayor.cantApariciones);

                    break;

                case 3:

                    if(menor.cantApariciones ==0)
                    {
                        menor = mayor;
                        mapInOrdenArbol(&pa,&menor,menorPalabra);
                    }

                    printf("\nMenor:\t%s, %d\n",menor.palabra,menor.cantApariciones);

                    break;

                case 4:
                    printf("\nSaliendo\n");
                    break;

                default:
                    printf("\nSeleccione una opcion correcta\n");
                    break;
            }

        }while(opcion !=4);

        vaciarArbol(&pa);

        return 1;
    }

    return 0;
}

///////////////

int proximaPalabraProcesada(char* linea, char ** ini)
{
    int ce =0;

    while(*linea)
    {
        if(ES_LETRA(*linea))
        {
            if(ce ==0)
            {
                *ini = linea;
                if(ES_MINUSCULA(*linea))
                    *linea = A_MAYUSCULA(*linea);
            }
            else
            {
                if(ES_MAYUSCULA(*linea))
                    *linea =A_MINUSCULA(*linea);
            }
            ce++;
        }
        else
        {
            if(ce !=0)
                return ce;
        }
        linea ++;
    }
    return ce;
}

int procesarPalabra(char* palabra, int ce);

int procesarLibro(const char* ruta, tArbol *pa, tPalabra* mayor)
{
    char linea[TAM_LINEA];
    char *ini=NULL, *aux;
    int ce=-1;
    tPalabra palabra;


    FILE* pf = fopen(ruta,"rt");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", ruta);
        return 0;
    }

    while(fgets(linea, TAM_LINEA, pf))
    {
        aux = linea;
        ce = proximaPalabraProcesada(aux, &ini);
        while (ce !=0)
        {

            strncpy(palabra.palabra, ini, ce);
            strncpy(palabra.palabra + ce, "\0", 2);
            palabra.cantApariciones =1;

            insertarOrdenadoArbol(pa,  sizeof(tPalabra), &palabra, duplicadoPalabra, cmpPalabra);

            if(mayor->cantApariciones < palabra.cantApariciones)
                *mayor = palabra;


            aux = ini + ce;
            ce = proximaPalabraProcesada(aux, &ini);
        }
    }
    fclose(pf);
    return 1;
}

////////////

int cmpPalabra (const void* a, const void* b)
{
    tPalabra* palabra1 = (tPalabra*) a;
    tPalabra* palabra2 = (tPalabra*) b;

    return strcmpi(palabra1->palabra, palabra2->palabra);
}

void mostrarPalabra (void* info, void* cond)
{
    tPalabra* palabra = (tPalabra*) info;

    printf("%s, %d\n", palabra->palabra, palabra->cantApariciones);
}

void menorPalabra (void* info, void* cond)
{
    tPalabra* palabraInfo = (tPalabra*) info;
    tPalabra* palabraMenor = (tPalabra*) cond;

    if(palabraInfo->cantApariciones < palabraMenor->cantApariciones)
    {
        strcpy(palabraMenor->palabra, palabraInfo->palabra);
        palabraMenor->cantApariciones = palabraInfo->cantApariciones;
    }
}

void duplicadoPalabra (void* info, void* dato)
{
    tPalabra* palabraInfo = (tPalabra*) info;
    tPalabra* palabraDato = (tPalabra*) dato;

    palabraInfo->cantApariciones += 1;
    palabraDato->cantApariciones = palabraInfo->cantApariciones;
}

//void duplicadoPalabra (tArbol *pa, void* info, void* dato)
//{
//    tPalabra* palabraInfo = (tPalabra*) info;
//
//    palabraInfo->cantApariciones += 1;
//
//    eliminarRaiz(pa, sizeof(tPalabra), dato);
//}
