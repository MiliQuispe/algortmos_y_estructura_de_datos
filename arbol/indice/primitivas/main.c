#include "ejercicio_6_6.h"

int main()
{
    tArbol pa;
    int pos=0;

    crearArbol(&pa);

    crearLote();
    cargarArbolArchivoBin("personas.dat", &pa, sizeof(tPersona), &pos, cmpPersonas, extraerArchivoBinPersonas);

    cargarArchiboBinDesdeArbol("personas.idx", &pa, grabarArchivoBinDNI);

    vaciarArbol(&pa);
    crearArbol(&pa);

    cargarArbolArchivoBinOrdenado("personas.idx", &pa, sizeof(tDni), leerRgistroArchivoBin);

    mapInOrdenArbol(&pa, NULL,NULL,mostrarDni);

    vaciarArbol(&pa);

    return 0;
}
