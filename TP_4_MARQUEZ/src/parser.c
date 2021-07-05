#include <stdio.h>
#include <stdlib.h>
#include "alumnos.h"
#include "../inc/LinkedList.h"

/** \brief Parsea los datos los datos de los Alumnos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListAlumnos LinkedList*
 * \return int
 *
 */
int parser_AlumnosFromText(FILE* pFile , LinkedList* pArrayListAlumnos)
{
    int todoOk = 0;
    char buffer[4][40];
    Alumno* auxAlumno = NULL;

    if(pFile!=NULL && pArrayListAlumnos!=NULL)
    {
        auxAlumno=alumno_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(auxAlumno!=NULL)
        {
            while(!feof(pFile))
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3])<4)
                {
                    break;
                }
                else
                {
                    auxAlumno = alumno_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                    ll_add(pArrayListAlumnos, auxAlumno);
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;
}
