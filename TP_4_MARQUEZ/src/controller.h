#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pArrayListAlumnos);
int controller_sortAlumnos(LinkedList* pArrayListAlumnos);
int controller_addAlumno(LinkedList* pArrayListAlumnos);
int controller_ListAlumnos(LinkedList* pArrayListAlumnos);
int insertarUnAlumno(LinkedList* pArrayListAlumnos);

#endif // CONTROLLER_H_INCLUDED
