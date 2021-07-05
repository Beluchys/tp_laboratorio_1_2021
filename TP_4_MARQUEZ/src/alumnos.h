#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
#include "../inc/LinkedList.h"
typedef struct
{
    int codigo;
    char nombre[128];
    int materiasAprobadas;
    int horasCursadas;
}Alumno;

Alumno* alumno_new();
Alumno* alumno_newParametros(char* codigoStr,char* nombreStr,char* materiasAprobadasStr, char* horasCursadasStr);
Alumno* alumno_newParametrosNoEsStr(int codigo, char* nombre, int materiasAprobadas, int horasCursadas);
void alumno_delete();

int menuOpciones();
int menuOrdenar();

int Alumno_setId(Alumno* this,int codigo);
int Alumno_getId(Alumno* this,int* codigo);
int Alumno_setNombre(Alumno* this,char* nombre);
int Alumno_getNombre(Alumno* this,char* nombre);
int Alumno_setmateriasAprobadas(Alumno* this,int materiasAprobadas);
int Alumno_getmateriasAprobadas(Alumno* this,int* materiasAprobadas);
int Alumno_setHorasCursadas(Alumno* this,int horasCursadas);
int Alumno_getHorasCursadas(Alumno* this,int* horasCursadas);

int alumno_generateId(LinkedList* pArrayListAlumnos, int len);
int eliminarAlumno(LinkedList* pArrayListAlumnos);
int buscarPorId(LinkedList* pArrayListAlumnos, int id);
int mostrarAlumno(Alumno* this);

int alumnos_OrdenarAlumnos(LinkedList *pArrayListAlumnos);
int alumnos_OrdenarPorNombre(void *nombreUno, void *nombreDos);
int alumnos_OrdenarPorMaterias(void *materiaUno, void* materiaDos);
int alumnos_OrdenarPorHoras(void *horasUno, void *horasDos);

#endif // ALUMNOS_H_INCLUDED
