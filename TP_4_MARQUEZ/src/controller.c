#include <stdio.h>
#include <stdlib.h>
#include "alumnos.h"
#include "../inc/LinkedList.h"
#include "validaciones_marquez.h"
#include "parser.h"


/** \brief Carga los datos de los Alumnos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListAlumnos LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListAlumnos)
{
    int todoOk = -1;
    FILE* f = NULL;

    if(path!=NULL && pArrayListAlumnos!=NULL)
    {
        f = fopen(path,"r");
        if(f != NULL)
        {
            parser_AlumnosFromText(f, pArrayListAlumnos);
            todoOk = 1;
            fclose(f);
        }
    }
    return todoOk;
}


/** \brief Alta de Alumno
 *
 * \param path char*
 * \param pArrayListAlumnos LinkedList*
 * \return int
 *
 */
int controller_addAlumno(LinkedList* pArrayListAlumnos)
{
    int todoOk=-1;
    int id;
    int materiasAprobadas;
    int horasCursadas;
    char nombre[128];
    Alumno* auxAlumno=NULL;

    if(pArrayListAlumnos!=NULL)
    {
        system("cls");
        printf("\n----------------------------------------------------------------\n");
        printf("                     ALTA DE ALUMNO\n");
        printf("----------------------------------------------------------------\n");
        if(utn_getNombre(nombre,128,"Ingrese nombre: ","Error en el Nombre, solo se permiten letras y hasta 20 caracteres\n",3) &&
                utn_getNumero(&materiasAprobadas,"Ingrese cantidad de Materias Aprobadas: ", "Error en las Materias. Vuelva a intentarlo (de 1 a 42)\n",0,42,3) &&
                utn_getNumero(&horasCursadas,"Ingrese Horas cursadas: ", "Error. (de 1 a 42)\n",1,42,3))
        {
            id = alumno_generateId(pArrayListAlumnos, ll_len(pArrayListAlumnos));
            auxAlumno = alumno_newParametrosNoEsStr(id, nombre, materiasAprobadas, horasCursadas);
            ll_add(pArrayListAlumnos, auxAlumno);
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }
    return todoOk;
}


/** \brief Listar Alumnos
 *
 * \param path char*
 * \param pArrayListAlumnos LinkedList*
 * \return int
 *
 */
int controller_ListAlumnos(LinkedList* pArrayListAlumnos)
{
    int todoOk = 0;

    if(pArrayListAlumnos != NULL)
    {
        system("cls");
        printf("-----------------------------------------------------------------------\n");
        printf("   CODIGO        NOMBRE       MATERIAS APROBADAS   HORAS CURSADAS\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i<ll_len(pArrayListAlumnos); i++)
        {
            mostrarAlumno((Alumno*) ll_get(pArrayListAlumnos, i));
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}


/** \brief Ordenar Alumnos
 *
 * \param path char*
 * \param pArrayListAlumnos LinkedList*
 * \return int
 *
 */
int controller_sortAlumnos(LinkedList* pArrayListAlumnos)
{
    int todoOk = 0;
    if (pArrayListAlumnos != NULL)
    {
        alumnos_OrdenarAlumnos(pArrayListAlumnos);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Carga un nuevo alumno, consulta en que posición lo quiere y lo coloca
 *
 * \param pArrayListAlumnos LinkedList*
 * \return int
 *
 */
int insertarUnAlumno(LinkedList* pArrayListAlumnos)
{
    int todoOk=-1;
    int index;
    int posicion;
    Alumno* auxAlumno = NULL;

    controller_addAlumno(pArrayListAlumnos);
    index = ll_len(pArrayListAlumnos);
    auxAlumno = (Alumno*)ll_get(pArrayListAlumnos, buscarPorId(pArrayListAlumnos, index));
    utn_getNumero(&posicion,"En que posición lo desea colocar? ", "Error - posicion Invalida. \n",0,ll_len(pArrayListAlumnos),3);
    ll_push(pArrayListAlumnos, posicion,auxAlumno);
    ll_remove(pArrayListAlumnos, index);
    controller_ListAlumnos(pArrayListAlumnos);

    return todoOk;
}
