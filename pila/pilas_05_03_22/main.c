#include "pilas.h"

int main()
{
    crearLote();
    crearPilas("datos.txt",TAM_LINEA);
    remove("datos.txt");

    return 0;
}
