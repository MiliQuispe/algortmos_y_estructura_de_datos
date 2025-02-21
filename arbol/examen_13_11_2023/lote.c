#include "lote.h"

// especifica

int cmpLote (const void* a, const void* b)
{
    tLote* lote1 = (tLote*)a;
    tLote* lote2 = (tLote*)b;
    return lote1->superficie - lote2->superficie;
}

int cmpSuperficie (const void* a, const void* b)
{
    tSuperficie* Superficie1 = (tSuperficie*)a;
    tSuperficie* Superficie2 = (tSuperficie*)b;
    return Superficie1->superficie - Superficie2->superficie;
}

void* loteConMenorSuperficie (void* info, void* cond)
{
    tSuperficie* loteInfo = (tSuperficie*)info;
//    tSuperficie* loteDato = (tSuperficie*)dato;
    float* condicion = (float *) cond;
    void* sup = NULL;

    if(*condicion > loteInfo->superficie)
    {
        sup = (void*) (&(loteInfo->superficie));
    }
    return sup;
}

void pasarSuperficie (void* info, void* cond)
{
    tLote* loteInfo = (tLote*)info;
    tArbol* pa = (tArbol* )cond;
    tSuperficie aux;
    aux.provincia = loteInfo->provincia;
    aux.superficie= loteInfo->superficie;

    insertsarOrdenadoArbol(pa, sizeof(tSuperficie), &aux, cmpSuperficie);
}

void mostrarLote (void* info, void* cond)
{
    tLote* loteInfo = (tLote*)info;

    printf("%d, %s, %f, %d\n", loteInfo->provincia, loteInfo->localidad, loteInfo->superficie, loteInfo->habitantes);
}

///ejercicio 1

int crearLOte()
{
    tLote lotes[] = {
    {12, "La Matanza", 325.00, 1800000},
        {12, "Moron", 60.00, 340000},
        {5, "Ciudad de Mendoza", 72.00, 1150000},
        {15, "Rosario", 178.00, 1300000},
        {3, "Ushuaia", 212.00, 180000},
        {21, "San Miguel de Tucumán", 20.00, 1000000},
        {9, "Cordoba", 576.00, 1300000},
        {2, "Salta", 155.00, 500000},
        {3, "Rio Grande", 600.00, 150000},
        {1, "Resistencia", 100.00, 150000}
   };

    return crearArchBin("lotes.dat", lotes, sizeof(lotes));
}

int crearArchBin(const char* ruta, const void* datos, unsigned tamDatos)
{
    FILE* pf = fopen (ruta, "wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s\n", ruta);
        return 0;
    }
    fwrite(datos, tamDatos, 1, pf);

    fclose(pf);
    return 1;
}

int los5MayoresLocalidades(const char* ruta, tArbol* pa)
{
    tLote aux;
    int ce = 0, limite;

    FILE* pf = fopen (ruta, "rt");
    if(!pf)
    {
        printf("No se pudo abrir el archivo %s\n", ruta);
        return 0;
    }

    fread(&aux, sizeof(tLote), 1, pf);
    while(!feof(pf))
    {
        limite = insertsarOrdenadoNarbol(pa, sizeof(tLote), &aux, &ce, 5, cmpLote);
        if(limite == 2)
            eliminarMenor(pa, sizeof(tLote), &aux);
        fread(&aux, sizeof(tLote), 1, pf);
    }

    fclose(pf);
    return 1;
}

///ejercicio 2

float menorSuperficie(tArbol* pa, const void* cond) {
    float sup = 1;
    void* super = buscarCondicionArbol(pa, (void*)cond, loteConMenorSuperficie);

    if (super != NULL) {
        printf("\nSuperficie %f", *((float*)super));
        sup = *((float*)super);  // Asumiendo que super es un puntero a un float
    } else {
        printf("\nNo se encontró ninguna superficie que cumpla con la condición.");
    }

    return sup;
}



