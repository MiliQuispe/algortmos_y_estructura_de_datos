#include "cola.h"

void crearCola(tCola *pc)
{
    pc->pri = TAM_COLA/2;
    pc->ult = TAM_COLA/2;
    pc->tamInfo = TAM_COLA;
}

int siEsColaLLena(const tCola *pc, unsigned tamDato)
{
    return pc->tamInfo < (sizeof(unsigned) + tamDato);
}

int siEsColaVacia(const tCola *pc)
{
    return pc->tamInfo == TAM_COLA;
}

int ponerEnCola(tCola *pc, unsigned tamDato, const void* dato)
{
    unsigned iniInfo, finInfo;

    if(pc->tamInfo < (sizeof(unsigned) + tamDato))
        return 0;

    if((iniInfo = MIN( sizeof(unsigned), TAM_COLA - pc->ult)) !=0)
        memcpy(pc->cola + pc->ult, &tamDato, iniInfo);

    if((finInfo = sizeof(unsigned) - iniInfo) !=0)
        memcpy(pc->cola, (char*)(&tamDato)+ iniInfo, finInfo);

    pc->ult = finInfo ? finInfo : pc->ult + iniInfo;

    if((iniInfo = MIN( tamDato, TAM_COLA - pc->ult)) !=0)
        memcpy(pc->cola + pc->ult, dato, iniInfo);

    if((finInfo = tamDato - iniInfo) !=0)
        memcpy(pc->cola, (char*)(dato)+ iniInfo, finInfo);


    pc->ult = finInfo ? finInfo : pc->ult + iniInfo;
    pc->tamInfo -= sizeof(unsigned) + tamDato;
    return 1;
}

int sacarEnCola(tCola *pc, unsigned tamDato, void* dato)
{
    unsigned ini, fin,tamInfo;

    if(pc->tamInfo == TAM_COLA)
        return 0;

    if((ini = MIN(sizeof(unsigned), TAM_COLA - pc->pri)) !=0)
        memcpy(&tamInfo,pc->cola + pc->pri, ini);

    if((fin = sizeof(unsigned) - ini) !=0)
        memcpy((char*)(&tamInfo) + ini, pc->cola, fin);

    tamInfo = MIN(tamDato,tamInfo);
    pc->pri = fin ? fin : pc->pri + ini;

    if((ini = MIN(tamInfo, TAM_COLA - pc->pri)) !=0)
        memcpy(dato, pc->cola + pc->pri, ini);
    if((fin = tamInfo - ini) !=0)
        memcpy((char*)(dato) + ini, pc->cola, fin);

    pc->pri = fin ? fin : pc->pri + ini;
    pc->tamInfo += tamInfo + sizeof(unsigned);
    return 1;
}

void vaciarCola(tCola *pc)
{
    pc->tamInfo = TAM_COLA;
}
