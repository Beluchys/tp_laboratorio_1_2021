#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#include "../inc/LinkedList.h"
#include "validaciones_marquez.h"
#include "controller.h"

// MENUS

int menuOpciones()
{
    int opcion=-1;
    printf("    ------------------------------------------------------------------\n");
    printf("                              MENU PRINCIPAL                           \n");
    printf("    ------------------------------------------------------------------\n");
    printf("1- Crea un LinkedList 'Alumnos'.\n"); //Función ll_newLinkedList
    printf("2- Cargar los datos de los Alumnos desde el archivo Informes (csv).\n"); //Funcion controller_loadFromText
    printf("3- Mostrar la cantidad de alumnos que hay en total en el Informe.\n"); //Función ll_len
    printf("4- Agrega un Alumno al Informe.\n"); //Función ll_add
    printf("5- Verifica si la lista esta Vacia.\n"); //Función ll_isEmpty
    printf("6- Listar Alumnos.\n"); //Función ll_get
    printf("7- Eliminar Alumno por CODIGO.\n"); //Función ll_remove
    printf("8- Eliminar todos los Alumnos del Informe. \n"); //Función ll_clear
    printf("9- Ordenar Alumnos.\n"); //Función ll_sort
    printf("10- Agregar a un alumno a una posicion Especifica*.\n");//Función ll_push
    printf("11- Sacar a un Alumno de la Lista y guardarlo aparte.\n"); //Función ll_pop
    printf("12- Duplicar Lista de Alumnos con posiciones especificas (from - to).\n");//Función ll_sublist
    printf("13- Corrobora si un Alumno esta en la lista Duplicada.\n"); //Función ll_contains
    printf("14- Comparar Listas\n"); //Función ll_containsAll
    printf("15- Clonar la Lista Completa de Alumnos.\n"); //Función ll_clone
    printf("16- Conseguir el Indice de un Alumno.\n"); // Función ll_indexOf
    printf("17- Eliminar el LinkedList.\n"); //Función ll_deleteLinkedList
    printf("18- Salir.\n");
    printf("    ----------------------------------------------------------------\n");

    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 18, 3);
    return opcion;
}

int menuOrdenar()
{
    int opcion;
    printf("\n\n    ---------------------  MENU PARA ORDENAR  ----------------------\n");
    printf("    ----------------------------------------------------------------\n");
    printf("1- Ordenar por Nombre: \n");
    printf("2- Ordenar por Materias Aprobadas: \n");
    printf("3- Ordenar por Horas Cursadas: \n");
    printf("4- Salir\n");
    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 4, 5);
    return opcion;
}

Alumno* alumno_new()
{
    Alumno* newAlumno;
    newAlumno = (Alumno*) calloc(sizeof(Alumno), 1);

    if (newAlumno != NULL)
    {
        newAlumno->codigo = 0;
        strcpy(newAlumno->nombre, " ");
        newAlumno->materiasAprobadas = 0;
        newAlumno->horasCursadas = 0;
    }
    return newAlumno;
}

Alumno* alumno_newParametros(char* codigoStr,char* nombreStr,char* materiasAprobadasStr, char* horasCursadasStr)
{
    Alumno *newAlumno;
    newAlumno = alumno_new();

    int auxCodigo;
    int auxMateriasAprobadas;
    int auxhorasCursadas;

    auxCodigo = atoi(codigoStr);
    auxMateriasAprobadas = atoi(materiasAprobadasStr);
    auxhorasCursadas = atoi(horasCursadasStr);

    if (newAlumno != NULL && codigoStr != NULL && nombreStr != NULL && materiasAprobadasStr != NULL && horasCursadasStr != NULL)
    {
        Alumno_setId(newAlumno, auxCodigo);
        Alumno_setNombre(newAlumno, nombreStr);
        Alumno_setmateriasAprobadas(newAlumno, auxMateriasAprobadas);
        Alumno_setHorasCursadas(newAlumno, auxhorasCursadas);

    }
    return newAlumno;
}

Alumno* alumno_newParametrosNoEsStr(int codigo, char* nombre, int materiasAprobadas, int horasCursadas)
{
    Alumno* newAlumno = alumno_new();

    if(newAlumno!=NULL)
    {
        Alumno_setId(newAlumno, codigo);
        Alumno_setNombre(newAlumno, nombre);
        Alumno_setmateriasAprobadas(newAlumno, materiasAprobadas);
        Alumno_setHorasCursadas(newAlumno, horasCursadas);
    }

    return newAlumno;
}
void alumno_delete(Alumno *this)
{
    if (this != NULL)
    {
        free(this);
    }
}



// FUNCIONES ID //

int Alumno_setId(Alumno* this,int codigo)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (codigo >= 0)
        {
            this->codigo = codigo;
            todoOk = 1;
        }
    }
    return todoOk;
}

int Alumno_getId(Alumno* this,int* codigo)
{
    int todoOk = 0;

    if (this != NULL && codigo != NULL)
    {
        *codigo = this->codigo;
        todoOk = 1;
    }
    return todoOk;

}

//  FUNCIONES NOMBRE

int Alumno_setNombre(Alumno* this,char* nombre)
{
    int todoOk = 0;

    if (this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int Alumno_getNombre(Alumno* this,char* nombre)
{
    int todoOk = 0;

    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

//FUNCIONES MATERIAS
int Alumno_setmateriasAprobadas(Alumno* this,int materiasAprobadas)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (materiasAprobadas >= 0)
        {
            this->materiasAprobadas = materiasAprobadas;
            todoOk = 1;
        }
    }
    return todoOk;

}
int Alumno_getmateriasAprobadas(Alumno* this,int* materiasAprobadas)
{
    int todoOk = 0;

    if (this != NULL && materiasAprobadas != NULL)
    {
        *materiasAprobadas = this->materiasAprobadas;
        todoOk = 1;
    }
    return todoOk;
}

// FUNCIONES HORAS CURSADAS
int Alumno_setHorasCursadas(Alumno* this,int horasCursadas)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if(horasCursadas>=0)
        {
            this->horasCursadas = horasCursadas;
            todoOk = 1;
        }
    }
    return todoOk;
}
int Alumno_getHorasCursadas(Alumno* this,int* horasCursadas)
{
    int todoOk = 0;

    if (this != NULL && horasCursadas != NULL)
    {
        *horasCursadas = this->horasCursadas;
        todoOk = 1;
    }
    return todoOk;
}

// GENERAR ID

/** \brief Genera el Id para cada dato, siempre suma uno mas al mayor
 *
 * \param pArrayListAlumnos LinkedList*
 * \param len int
 * \return int
 *
 */
int alumno_generateId(LinkedList* pArrayListAlumnos, int len)
{
    int idMax=0;
    int idActual;
    Alumno* auxAlumno;

    if(!ll_isEmpty(pArrayListAlumnos))
    {
        for(int i=0; i<ll_len(pArrayListAlumnos); i++)
        {
            auxAlumno = (Alumno*) ll_get(pArrayListAlumnos, i);
            Alumno_getId(auxAlumno, &idActual);
            if(idActual>idMax || i==0)
            {
                idMax=idActual;
            }
        }
    }
    return idMax+1;
}

/** \brief Elimina al alumno por codigo
 *
 * \param pArrayListAlumnos LinkedList*
 * \return int
 *
 */
int eliminarAlumno(LinkedList* pArrayListAlumnos)
{
    int todoOk = -1;
    int id;
    int index;
    char confirma;
    Alumno* auxAlumno=NULL;

    if(pArrayListAlumnos!=NULL)
    {
        printf("\n-------------------------------------------------------------\n");
        printf("                   ELIMINAR ALUMNO POR CODIGO\n");
        printf("----------------------------------------------------------------\n");
        todoOk=1;

        controller_ListAlumnos(pArrayListAlumnos); //Muestro la lista de alumnos

        utn_getNumero(&id, "\nIngreses el CODIGO del Alumno eliminar: ","Error - CODIGO incorrecto. Vuelva a ingresarlo: \n", 1, ll_len(pArrayListAlumnos), 3);
        index = buscarPorId(pArrayListAlumnos, id);
        if(index!=-1)
        {
            auxAlumno = (Alumno*)ll_get(pArrayListAlumnos, index);
            printf("\n\n");
            mostrarAlumno(auxAlumno);

            while(confirma!='n' && confirma!='s')
            {
                printf("\nConfirma la baja? (n/s): ");
                fflush(stdin);
                scanf("%c", &confirma);
            }
            if(confirma=='s')
            {
                ll_remove(pArrayListAlumnos,index);
                printf("\nSe Elimino al ALUMNO con Exito.\n\n ");
                todoOk=1;
                system("pause");
                system("cls");
            }
            else
            {
                printf("Tarea Cancelada.\n\n");
                todoOk=0;
                system("pause");
                system("cls");
            }
        }
        else
        {
            printf("No se encontro al ALUMNO.\n\n");
            todoOk=0;
            system("pause");
            system("cls");
        }
    }
    return todoOk;
}

// BUSCAR CODIGO

/** \brief Busca al alumno por CODIGO
 *
 * \param pArrayListAlumnos LinkedList*
 * \param id int
 * \return int
 *
 */
int buscarPorId(LinkedList* pArrayListAlumnos, int id)
{
    int retorno = -1;
    int idAux;
    Alumno* pAlumno;

    for(int index = 0; index < ll_len(pArrayListAlumnos); index++)
    {
        pAlumno = ll_get(pArrayListAlumnos, index);
        if(Alumno_getId(pAlumno, &idAux) == 1 && idAux == id)
        {
            retorno = index;
        }
    }
    return retorno;
}

// SHOW

/** \brief muestra solo un Alumno
 *
 * \param this Alumno*
 * \return int
 *
 */
int mostrarAlumno(Alumno* this)
{
    int retorno = 0;
    int id;
    char nombre[128];
    int materiasAprobadas;
    int horasCursadas;

    if(this!=NULL &&
            Alumno_getId(this, &id) &&
            Alumno_getNombre(this, nombre) &&
            Alumno_getmateriasAprobadas(this, &materiasAprobadas) &&
            Alumno_getHorasCursadas(this, &horasCursadas))
    {
        printf(" %4d   %14s        %8d            %10d\n",id,nombre,materiasAprobadas,horasCursadas);
        retorno=1;
    }
    return retorno;
}


// ORDENAMIENTO

/** \brief llama a cada funcion de ordenamiento y la ejecuta
 *
 * \param pArrayListAlumnos LinkedList*
 * \return int
 *
 */
int alumnos_OrdenarAlumnos(LinkedList *pArrayListAlumnos)
{
    int todoOk = 0;
    system("cls");

    if (pArrayListAlumnos != NULL)
    {
        switch (menuOrdenar())
        {
        case 1: /* NOMBRE */
            system("cls");
            printf("\n\n    ---------------------  ORDENADO POR NOMBRE  --------------------\n");
            printf("    ----------------------------------------------------------------\n");
            ll_sort(pArrayListAlumnos, alumnos_OrdenarPorNombre, 1);
            controller_ListAlumnos(pArrayListAlumnos);
            todoOk = 1;
            break;
        case 2: /* HORAS */
            system("cls");
            printf("\n\n    --------------- ORDENADO POR MATERIAS APROBADAS  --------------------\n");
            printf("    ----------------------------------------------------------------\n");
            ll_sort(pArrayListAlumnos, alumnos_OrdenarPorMaterias, 1);
            controller_ListAlumnos(pArrayListAlumnos);
            todoOk = 1;
            break;
        case 3: /* SUELDO */
            system("cls");
            printf("\n\n    ------------------  ORDENADO POR HORAS CURSADAS  ----------------\n");
            printf("    ----------------------------------------------------------------\n");
            ll_sort(pArrayListAlumnos, alumnos_OrdenarPorHoras, 1);
            controller_ListAlumnos(pArrayListAlumnos);
            todoOk = 1;
            break;
        case 4: /* SALIR */
            printf("\nNo se Realiza ningun Ordenamiento.\n\n");
            todoOk = 0;
            break;
        default:
            printf("\nOpcion Invalida\n");
        }
    }
    system("pause");
    system("cls");
    return todoOk;
}


// POR NOMBRE

/** \brief Ordena por nombre, de A a Z
 *
 * \param nombreUno void*
 * \param nombreDos void*
 * \return int
 *
 */
int alumnos_OrdenarPorNombre(void *nombreUno, void *nombreDos)
{
	char alumnoUno[128];
	char alumnoDos[128];
	int todoOk = 0;

	Alumno_getNombre(nombreUno, alumnoUno);
	Alumno_getNombre(nombreDos, alumnoDos);

	if (strcmp(alumnoUno, alumnoDos) > 0) {
		todoOk = 1;
	} else if (strcmp(alumnoUno, alumnoDos) < 0) {
		todoOk = -1;
	}

	return todoOk;
}

// POR MATERIAS

/** \brief ordena por cantidad de Materias Aprobadas de menor a mayor
 *
 * \param materiaUno void*
 * \param materiaDos void*
 * \return int
 *
 */
int alumnos_OrdenarPorMaterias(void *materiaUno, void* materiaDos)
 {
	int alumnoUno;
	int alumnoDos;
	int todoOk = 0;

	Alumno_getmateriasAprobadas(materiaUno, &alumnoUno);
	Alumno_getmateriasAprobadas(materiaDos, &alumnoDos);

	if (alumnoUno > alumnoDos) {
		todoOk = 1;
	} else if (alumnoUno < alumnoDos) {
		todoOk = -1;
	}

	return todoOk;
}

// POR HORAS CURSADAS

/** \brief ordena por horas cursadas de menor a mayor
 *
 * \param horasUno void*
 * \param horasDos void*
 * \return int
 *
 */
int alumnos_OrdenarPorHoras(void *horasUno, void *horasDos)
{
	int alumnoUno;
	int alumnoDos;
	int todoOk = 0; // si las horas son iguales, devuelve 0

	Alumno_getHorasCursadas(horasUno, &alumnoUno);
	Alumno_getHorasCursadas(horasDos, &alumnoDos);

	if (alumnoUno > alumnoDos) {
		todoOk = 1;
	} else if (alumnoUno < alumnoDos) {
		todoOk = -1;
	}
	return todoOk;
}
