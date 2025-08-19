#include "cuentas.h"


int main()
{
    tLista pl;
    crearLista(&pl);

    crearLote();
    cargarListaArchivoTxt("cuentas.txt", &pl, sizeof(tCuenta), cmpCuenta, leerCuenta);

    mapLista(&pl, NULL,mostrarCuenta);printf("\n");

    eliminarUltimoNdeLaLista(&pl, 2);

    mapLista(&pl, NULL,mostrarCuenta);

    guardarListaArchivoBin("resultadoCuentas.bin", &pl, sizeof(tCuenta));

    vaciarLista(&pl);


    return 0;
}
