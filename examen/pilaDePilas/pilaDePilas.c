#include "pilaDePilas.h"

void crearLote(tPilaE* p)
{
    int mat[][4]=
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    }, i,j;
    tPilaD paux;

    for(i=0; i<3; i++)
    {
        crearPilaD(&paux);
        for(j=0; j<4.; j++)
        {
            ponerEnPilaD(&paux, sizeof(int), &mat[i][j]);
        }
        ponerEnPilaE(p, sizeof(tPilaD), &paux);
    }


}

void vaciarYmostrarPPE(tPilaE* p)
{
    tPilaD paux;
    int aux;

    crearPilaD(&paux);

    while(!siEsPilaEvacia(p))
    {
        sacarEnPilaE(p,sizeof(tPilaD), &paux);
        while(!siEsPilaDvacia(&paux))
        {
            sacarEnPilaD(&paux, sizeof(int),&aux);
            printf("%d\t",aux);
        }
        printf("\n");
    }
}

