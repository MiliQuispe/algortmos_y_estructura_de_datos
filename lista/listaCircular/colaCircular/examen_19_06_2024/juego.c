#include "juego.h"

int crearLote()
{
    tParticipantes part[]=
    {
        {1,"uno"},
        {2,"dos"},
        {3,"tres"},
        {4,"cuatro"},
        {5,"cinco"},
        {6,"seis"}
    };
    return crearArchivoBinario("participantes.dat", part, sizeof(part), 6);
}

int crearArchivoBinario(const char* ruta, const void* datos, unsigned tamDatos, int ce)
{
    FILE* pf = fopen(ruta, "wb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s",ruta);
        return 0;
    }

    fwrite(&ce, sizeof(int), 1, pf);

    fwrite(datos, tamDatos, 1, pf);

    fclose(pf);
    return 1;
}

int juego(const char* participantes, int* cantPartidas)
{
    tJugador jugador;
    tParticipantes part;
    tLista pl;
    tCola pc;
    int ce;

    FILE* pf = fopen(participantes, "rb");
    if(!pf)
    {
        printf("No se pudo crear el archivo %s", participantes);
        return 0;
    }

    crearLista(&pl);
    crearCola(&pc);

    fread(&ce, sizeof(int),1,pf);

    fread(&part, sizeof(tParticipantes),1,pf);
    while(!feof(pf))
    {
        jugador.part.nroP= part.nroP;
        strcpy(jugador.part.nomM, part.nomM);
        jugador.cantRondas =0;
        jugador.posicion = rand() % ce + 1;

        insertarOrdenadoLista(&pl, sizeof(tJugador), &jugador, cmpJugador);
        fread(&part, sizeof(tParticipantes),1,pf);
    }

    while(!siEsListaVacia(&pl))
    {
        eliminarPrimeroLista(&pl, sizeof(tJugador), &jugador);
        ponerEnCola(&pc,sizeof(tJugador), &jugador);
    }

    empezarJuego(&pc, cantPartidas,ce);

    fclose(pf);
    return 1;
}

int cmpJugador (const void* a, const void* b)
{
    tJugador* jugador1 = (tJugador*)a;
    tJugador* jugador2 = (tJugador*)b;

    return jugador1->posicion - jugador2->posicion;
}


int empezarJuego(tCola *pcParticipantes, int* cantPartidas, int cantParticipantes)
{
    tJugador jugador, primerJugador;
    int cantRondas=1, dado;
    char ruta[TAM_RUTA];

    sprintf(ruta,"partida%d.txt", *cantPartidas);

    FILE* pf = fopen(ruta,"wt");
    if(!pf)
    {
        printf("No se pudo crear el archivo partida%d.txt", *cantPartidas);
        return 0;
    }

    primerJugador.cantRondas = -1;

    sacarEnCola(pcParticipantes, sizeof(tJugador), &jugador);

    while(!siEsColaVacia(pcParticipantes))
    {


        if(primerJugador.cantRondas ==-1)
            primerJugador = jugador;
        else
        {
            if(strcmp(jugador.part.nomM, primerJugador.part.nomM)==0)
                cantRondas++;
        }

        dado= 1+  rand() % 6;

        if(dado!=5)
            ponerEnCola(pcParticipantes, sizeof(tJugador), &jugador);
        else
        {
            jugador.posicion= cantParticipantes;
            jugador.cantRondas = cantRondas;
            fprintf(pf, "Posición: %d - Cantidad de rondas jugadas: %d - Jugador Nro.: %d - Nombre: %s\n", jugador.posicion, jugador.cantRondas, jugador.part.nroP, jugador.part.nomM);
            cantParticipantes--;

            if(strcmp(jugador.part.nomM, primerJugador.part.nomM)==0)
                primerJugador.cantRondas = -1;
        }

        sacarEnCola(pcParticipantes, sizeof(tJugador), &jugador);
    }

    fprintf(pf, "GANADOR - Jugador Nro: %d - Nombre: %s\n",jugador.part.nroP, jugador.part.nomM);
    fprintf(pf, "Cantidad total de rondas jugadas en esta partida: %d\n", cantRondas);

    *cantPartidas = *cantPartidas + 1;
    fclose(pf);
    return  1;
}
