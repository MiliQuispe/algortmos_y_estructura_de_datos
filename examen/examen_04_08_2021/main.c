#include "maraton.h"



int main()
{
//    tParticipante par[]=
//    {
//        {123,"AAA", "1", 12.23},
//        {456,"BBB", "2", 12.12},
//        {789,"CCC", "3", 12.12},
//        {912,"DDD", "4", 12.13},
//        {912,"FFF", "4", 12.11},
//        {345,"EEE", "5", 12.10}
//    };
//    int i;
//    unsigned ce=0;
//
//    tLista pl;
//
//    crearLista(&pl);
//
//    for(i=0; i<6; i++)
//    {
//        insertarNordenadoLista(&pl, sizeof(tParticipante), par+i , &ce, 1, cmpParticipantes);
//    }
//    mapLista(&pl,NULL,mostrarParticipante);
//    vaciarLista(&pl);

    tLista pl;

    crearLista(&pl);
    crearLote();

    losNmejoresMaraton("maraton.txt", &pl, 3);

    mapLista(&pl,NULL,mostrarParticipante);
    vaciarLista(&pl);

    return 0;
}
