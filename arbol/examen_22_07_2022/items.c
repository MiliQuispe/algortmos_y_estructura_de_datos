#include "items.h"

/// item A

int pruebaItemA ()
{
    tPedido pedidos[]=
    {
        {"BBB33", 'B', 35},
        {"AAA11", 'A', 13},
        {"DDD22", 'A', 45},
        {"AAA11", 'C', 82},
        {"BBB33", 'B', 39},
        {"AAA11", 'A', 27},
        {"DDD22", 'D', 53}
    };

    tArbol pa;
    int i,nivel = 4;

    crearArbol(&pa);

    for(i=0; i<7; i++ )
    {
        insertarOdenadoArbolBinarioDeBusqueda(&pa, sizeof(tPedido), pedidos+i, cmpCantidad);
    }

    mapNivelArbolBinarioDeBusqueda(&pa, NULL, nivel,mostrarPedidos);

    vaciarArbolBinarioDeBusqueda(&pa);

    return 1;
}


/// item B

int crearLote()
{
    tPedido pedidos[]=
    {
        {"BBB33", 'B', 35},
        {"AAA11", 'A', 13},
        {"DDD22", 'A', 45},
        {"AAA11", 'C', 82},
        {"BBB33", 'B', 39},
        {"AAA11", 'A', 27},
        {"DDD22", 'D', 53}
    };
    return crearArchivoBinario("pedido.dat", pedidos, sizeof(pedidos));
}

int crearArchivoBinario(const char *ruta, const void* dato, unsigned tamdatos)
{
    FILE *pf = fopen(ruta, "wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", ruta);
        return 0;
    }

    fwrite(dato, tamdatos, 1, pf);

    fclose(pf);
    return 1;
}

int cargarListaDobleArchiBin (const char* ruta, tLista *pl, unsigned tamDato)
{
    void* aux = malloc(tamDato);
    if(!aux)
        return 0;

    FILE *pf = fopen(ruta, "rb");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s", ruta);
        free(aux);
        return 0;
    }

    fread(aux, tamDato, 1, pf);
    while(!feof(pf))
    {
        insertarAlfinalListaDoblementeEnlazada(pl, tamDato, aux);
        fread(aux, tamDato, 1, pf);
    }

    fclose(pf);
    free(aux);
    return 1;
}

int listaXpedidos(tLista *pl)
{
    tLista paux;
    crearListaDoblementeEnlazada(&paux);

    mapListaDoblementeEnlazadaD(pl, &paux , reduciApedidos);

    VaciarListaDoblementeEnlazada(pl);
    crearListaDoblementeEnlazada(pl);
    *pl = paux;

    return 1;

}

int guardarListaDobleArchTXT (const char* ruta, tLista *pl, Accion accion)
{
    FILE *pf = fopen(ruta, "wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", ruta);
        return 0;
    }

    mapVaciarListaDoblementeEnlazadaD(pl, pf, accion);

    fclose(pf);
    return 1;
}

int cmpPedidos (const void* a, const void* b)
{
    tPedido* ped1 = (tPedido*) a;
    tPedido* ped2 = (tPedido*) b;

    return strcmp(ped1->cod, ped2->cod);
}

int cmpCantidad(const void* a, const void* b)
{
    tPedido* ped1 = (tPedido*) a;
    tPedido* ped2 = (tPedido*) b;

    return ped1->cant - ped2->cant;
}

void duplicadosPedidos (void* info, const void *dato)
{
    tPedido* pedInfo = (tPedido*) info;
    tPedido* pedDato = (tPedido*) dato;

    pedInfo->cant += pedDato->cant;

}
void mostrarYgrabarPedidos (void* info, void* cond)
{
    tPedido* pedInfo = (tPedido*) info;
    FILE* pf = (FILE*) cond;

    printf("\n%s %d\n", pedInfo->cod, pedInfo->cant);

    fprintf(pf, "%s|%d\n", pedInfo->cod, pedInfo->cant);
}

void mostrarPedidos (void* info, void* cond)
{
    tPedido* pedInfo = (tPedido*) info;

    printf("\n%s %d\n", pedInfo->cod, pedInfo->cant);
}

void reduciApedidos (void* info, void* cond)
{
    tPedido* pedInfo = (tPedido*) info;
    tLista *pl = (tLista *) cond;

    insertarAlfinalListaDoblementeEnlazadaNoDuplicado(pl,  sizeof(tPedido), pedInfo, cmpPedidos, duplicadosPedidos);
}

int pruebaItemB ()
{
    tLista pl;
    crearListaDoblementeEnlazada(&pl);

    crearLote();
    cargarListaDobleArchiBin("pedido.dat", &pl, sizeof(tPedido));

    listaXpedidos(&pl);

    guardarListaDobleArchTXT("pedido_cod.txt", &pl, mostrarYgrabarPedidos);

    return 1;

}
