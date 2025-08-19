#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED


#define TODO_OK 0
#define SIN_MEM 1
#define ERROR_ARCHIVO 2
#define DUPLICADO 3
#define NO_EXISTE 4
#define VERDADERO 1
#define FALSO 0



typedef struct
{
	int dni;
	int anio;
	int periodo;
	char materia[10];
	int nota;
}t_materia;


typedef t_materia t_info;

typedef t_materia t_info_estruct;


#endif // TIPOS_H_INCLUDED
