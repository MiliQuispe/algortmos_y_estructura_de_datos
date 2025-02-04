#include "cola.h"

void crearCola(tCola *pc)
{
    pc->tamInfo=TAM_COLA;
    pc->pri = TAM_COLA/2;
    pc->ult =TAM_COLA /2;
}

int siEsColaVacia(const tCola *pc)
{
    return pc->tamInfo == TAM_COLA;
}
int siEsColaLLena(const tCola *pc, unsigned tamDato)
{
    return pc->tamInfo < (tamDato + sizeof(unsigned));
}

int ponerEnCola(tCola *pc, unsigned tamDato, const void* dato)
{
    unsigned iniInfo, finInfo;
    // se debe verificar si hay espacio

    if(pc->tamInfo < (tamDato + sizeof(unsigned)))
        return 0;

    //se debe verificar si hay que cortar la informacion

    ///Primero si se puede poner el tamaño

        /// - Este condicional analiza si la posicion del ultimo al que apunta la cola
        ///  (donde se debe insertar, se ubica al final del arreglo), ahora si no es el final
        ///   se debe insertar solo la parte que entre, por eso se busca el minimo.

    if((iniInfo = MIN(sizeof(unsigned), TAM_COLA- pc->ult)) !=0)
        memcpy(pc->cola + pc->ult, &tamDato, iniInfo);

        /// - Este condicional verifica  si quedo informacion a insertar, por lo cual se busca si
        ///   se inserto la cantidad justa de informacion indicado en iniInfo, de lo contrario
        ///   se inserta al principio.

    if((finInfo = sizeof(unsigned) - iniInfo) !=0)
        mempcpy(pc->cola, (char*)(&tamDato) + iniInfo, finInfo);

            /// (char*)(&tamDato + ini) en esta parte se lo convierte a char* para pasarlo a bytes
            /// y poder desplazarme hasta donde se copio anteriormente

    pc->ult = finInfo ? finInfo : pc->ult + iniInfo;

    ///Segundo si se puede el dato y se aplica la misma logica
    if((iniInfo = MIN(tamDato, TAM_COLA - pc->ult)) !=0)
        memcpy(pc->cola + pc->ult, dato , iniInfo);

    if((finInfo = tamDato - iniInfo) !=0)
        mempcpy(pc->cola, (dato) + iniInfo, finInfo);

    pc->ult = finInfo ? finInfo : pc->ult + iniInfo;

    pc->tamInfo -= sizeof(unsigned) + tamDato;
    return 1;

}

int sacarEnCola(tCola *pc, unsigned tamDato, void* dato)
{
    unsigned iniInfo, finInfo, tamInfo;

    if(pc->tamInfo == TAM_COLA)
        return 0;

    ///Tamanio
    if((iniInfo = MIN(sizeof(unsigned), TAM_COLA - pc->pri)) !=0)
        memcpy(&tamInfo, pc->cola + pc->pri, iniInfo);
    if((finInfo = sizeof(unsigned) - iniInfo) !=0)
        memcpy((char*)(&tamDato) + iniInfo, pc->cola, finInfo);

    //ubicar el primimero
    pc->pri = finInfo ? finInfo : pc->pri + iniInfo;

    pc->tamInfo += sizeof(unsigned) + tamInfo;

    tamInfo = MIN(tamDato,tamInfo);

    ///Dato
    if((iniInfo = MIN(tamDato, TAM_COLA - pc->pri)) !=0)
        memcpy(dato, pc->cola + pc->pri, iniInfo);
    if((finInfo = tamInfo - iniInfo) !=0)
        memcpy((char*)(dato) + iniInfo, pc->cola, finInfo);


    //ubicar el primimero
    pc->pri = finInfo ? finInfo : pc->pri + iniInfo;
    return 1;
}

void vaciarCola(tCola *pc)
{
    pc->tamInfo = TAM_COLA;
}

int verPrimero(tCola *pc, unsigned tamDato, void* dato)
{
    unsigned iniInfo, finInfo, tamInfo, pos;

    if(pc->tamInfo == TAM_COLA)
        return 0;

    ///Tamanio
    if((iniInfo = MIN(sizeof(unsigned), TAM_COLA - pc->pri)) !=0)
        memcpy(&tamInfo, pc->cola + pc->pri, iniInfo);
    if((finInfo = sizeof(unsigned) - iniInfo) !=0)
        memcpy((char*)(&tamDato) + iniInfo, pc->cola, finInfo);

    //ubicar el primimero
    pos = finInfo ? finInfo : pc->pri + iniInfo;

    tamInfo = MIN(tamDato,tamInfo);

    ///Dato
    if((iniInfo = MIN(tamDato, TAM_COLA - pos)) !=0)
        memcpy(dato, pc->cola + pos, iniInfo);
    if((finInfo = tamInfo - iniInfo) !=0)
        memcpy((char*)(dato) + iniInfo, pc->cola, finInfo);


    return 1;
}
