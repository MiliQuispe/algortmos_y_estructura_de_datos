#include "articulos.h"

int main()
{
    float limite = 1600;
    if(crearLote())
    {
        printf("articulos.bin\n");
        verArchivoArticulo("articulos.bin");
        crearArchivos("articulos.bin", limite);

        printf("\narticulosSuperiorAlLimite\n");
        verArchivoArticulo("articulosSuperiorAlLimite");

        printf("\narticulosIgualInferiorAlLimite\n");
        verArchivoArticulo("articulosIgualInferiorAlLimite");

    }

    return 0;
}
