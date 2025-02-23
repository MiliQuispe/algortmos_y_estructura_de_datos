#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<stdio.h>
#include<arbol.h>

#define TAM_NOMBRE_ARCH 75

int alta_res (t_arbol* pa);
int alta (t_arbol* pa);

int baja_res (t_arbol* pa);
int baja (t_arbol* pa);

void ingresar_materia_nota(t_materia* mat);
void ingresar_materia_nota_res(t_materia* mat);
void ingresar_materia(t_materia* mat);
void ingresar_materia_res(t_materia* mat);
void ingresar_dni_anio_periodo(t_materia* mat);
void ingresar_dni_anio_periodo_res(t_materia* mat);
void imprimir_materia_res(t_materia* alu,void* datos);

void mostrar_clave_res(const t_materia* r);

void imprimir_listado_res(const t_arbol *pa);
void imprimir_listado(const t_arbol *pa);

void validar_arbol_res(const t_arbol *pa);///Imprime si el arbol es completo, balanceado, AVL o ninguna
void validar_arbol(const t_arbol *pa);

int informe_materias_aprobadas_res(const t_arbol *pa);
int informe_materias_aprobadas(const t_arbol *pa);

///////

int cmpDNI(const t_info*a, const t_info*b);
void guardarMateriasAprobadas (t_info* pinfo, void* datos_accion);
void grabarMateriasAprobadas (t_info* pinfo, void* datos_accion);
int cmpMateria(const t_info*a, const t_info*b);

#endif // UTILITARIAS_H_INCLUDED
