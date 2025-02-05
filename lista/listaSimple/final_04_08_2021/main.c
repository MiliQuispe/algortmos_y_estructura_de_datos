#include "cuenta.h"

int main()
{
    tLista pl;

    crearLista(&pl);
    if(crearLote())
    {
        crearListaOrdenadaConArchivoTXT("cuentas.txt",&pl, sizeof(tCuenta), formatoCuentaR, cmpCuentas);
        mapLista(&pl, NULL, mostrarCuenta);

        eliminarUltimosNdelaLista(&pl,4);

//        printf("\n");
//        mapLista(&pl, NULL, mostrarCuenta);

        crearArchivoBINConLista("resultadoCuentas.bin", &pl, guardarCuenta);
    }

    vaciarLista(&pl);

    return 0;
}
