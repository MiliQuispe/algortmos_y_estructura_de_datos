#include "lote.h"

int main()
{
    tArbol pa, pcv;
    float cond = 500;

    crearArbol(&pa);
    crearArbol(&pcv);
    crearLOte();

    los5MayoresLocalidades("lotes.dat", &pa);

    mapInOrden(&pa, NULL, mostrarLote);
    mapInOrden(&pa, &pcv,pasarSuperficie);

    menorSuperficie(&pcv, &cond);

    vaciarArbol(&pa);
    vaciarArbol(&pcv);



    return 0;
}
