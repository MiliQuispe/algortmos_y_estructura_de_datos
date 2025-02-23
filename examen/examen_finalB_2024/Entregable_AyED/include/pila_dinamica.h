#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


#ifndef MINIMO
#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))
#endif // MINIMO


#ifndef OK
    #define OK 1
#endif // OK

#ifndef NO_PUDE_APILAR
#define NO_PUDE_APILAR 0
#endif // NO_PUDE_APILAR

#ifndef NO_PUDE_DESAPILAR
#define NO_PUDE_DESAPILAR 0
#endif // NO_PUDE_DESAPILAR

#ifndef NO_PUDE_VER_TOPE
#define NO_PUDE_VER_TOPE 0
#endif // NO_PUDE_VER_TOPE

#ifndef PILA_LLENA
#define PILA_LLENA 1
#endif // PILA_LLENA

#ifndef HAY_LUGAR
#define HAY_LUGAR 0
#endif // HAY_LUGAR

#ifndef T_NODO
#define T_NODO
typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;
#endif // T_NODO

typedef tNodo* tPila;

void crearPila( tPila* pp );

int apilar( tPila* pp, const void* pd, unsigned tam );
int desapilar( tPila* pp, void* pd, unsigned tam );

int pilaVacia( const tPila* pp );
int pilaLlena( const tPila* pp, unsigned tam );

int verTope( const tPila* pp, void* pd, unsigned tam );

void vaciarPila( tPila* pp );

/// Resueltas
void crearPila_res( tPila* pp );

int apilar_res( tPila* pp, const void* pd, unsigned tam );
int desapilar_res( tPila* pp, void* pd, unsigned tam );

int pilaVacia_res( const tPila* pp );
int pilaLlena_res( const tPila* pp, unsigned tam );

int verTope_res( const tPila* pp, void* pd, unsigned tam );

void vaciarPila( tPila* pp );

#endif // PILA_H_INCLUDED
