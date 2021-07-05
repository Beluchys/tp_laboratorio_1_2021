#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "alumnos.h"

int main(void)
{
    int option = 0;
    char confirma;
    int idFirst;
    int idSecond;
    int posicion;
    int index;
    int indexOf;
    Alumno* auxAlumno = NULL;
    Alumno* pAux = NULL;
    LinkedList* alumnos = NULL;
    LinkedList* alumnosClonados = NULL;
    LinkedList* alumnosDuplicados = NULL;


    do
    {
        option = menuOpciones();
        switch(option)
        {
        case 1:
            alumnos = ll_newLinkedList();
            if(alumnos != NULL)
            {
                printf("\nSe Creo el LinkedList correctamente.\n\n");
            }
            else
            {
                printf("Hubo un error al crear el LinkedList.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if(controller_loadFromText("data.csv",alumnos))
            {
                printf("\nLa lista creo Correctamente.\n\n");
            }
            else
            {
                printf("\nOcurrio un error al crear la Lista.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\nLa cantidad de Alumnos en el informe es de: %d \n\n", ll_len(alumnos));
            system("pause");
            system("cls");
            break;
        case 4:
            if(controller_addAlumno(alumnos))
            {
                printf("El Alumno se cargo con Exito.\n\n");
            }
            else
            {
                printf("Ocurrio un error al cargar el Alumno.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            if(ll_isEmpty(alumnos))
            {
                printf("\nLa lista de Alumnos esta vacia.\n\n");
            }
            else
            {
                printf("\nHay Alumnos cargados en la lista.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 6:
            controller_ListAlumnos(alumnos);
            system("pause");
            system("cls");
            break;
        case 7:
            if(eliminarAlumno(alumnos))
            {
                printf("Se realizo la tarea correctamente.\n\n");
            }
            else
            {
                printf("Ocurrio un error en la tarea.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 8:
            while(confirma!='n' && confirma!='s')
            {
                printf("\nDesea Eliminar a todos los Alumnos de la Lista? (n/s): ");
                fflush(stdin);
                scanf("%c", &confirma);
            }
            if(confirma=='s')
            {
                ll_clear(alumnos);
                printf("\nSe Eliminaron los Alumnos con Exito.\n\n ");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Tarea Cancelada.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 9:
            controller_sortAlumnos(alumnos);
            system("pause");
            system("cls");
            break;
        case 10:
            if(insertarUnAlumno(alumnos))
            {
                printf("\nSe Realizo la tarea Correctamente\n\n");
            }else{
            printf("\nHubo un error al realizar la tarea\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 11:
            system("cls");
            printf("\n-------------------------------------------------------------\n");
            printf("                   SACAR A UN ALUMNO DE LA LISTA\n");
            printf("----------------------------------------------------------------\n");
            utn_getNumero(&idFirst, "\nIngreses el CODIGO del alumno que desea sacar: ","Error - Codigo incorrecto. Vuelva a ingresarlo: \n", 1, ll_len(alumnos), 3);

            auxAlumno = (Alumno*)ll_get(alumnos, buscarPorId(alumnos, idFirst));
            indexOf = ll_indexOf(alumnos, auxAlumno);
            pAux = ll_pop(alumnos, indexOf);

            if(pAux!=NULL)
            {
                printf("\nSe elimino de la lista al siguiente Alumno:\n\n");
                mostrarAlumno(pAux);
                printf("\n\n");
            }
            else
            {
                printf("\nHubo un error a Eliminar de la lista al alumno.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 12:
            system("cls");
            printf("\n-------------------------------------------------------------\n");
            printf("                       DUPLICAR LISTA\n");
            printf("----------------------------------------------------------------\n");
            utn_getNumero(&idFirst, "\nIngreses el Codigo del Primer alumno de su Nueva Lista: ","Error - Codigo Incorrecto. Vuelva a ingresarlo: \n", 1, ll_len(alumnos), 3);
            utn_getNumero(&idSecond, "\nIngreses el Codigo del Ultimo alumno de su Nueva Lista (este ultimo no estara en la lista): ","Error - Codigo Incorrecto. Vuelva a ingresarlo: \n", 1, ll_len(alumnos), 3);

            auxAlumno = (Alumno*)ll_get(alumnos, buscarPorId(alumnos, idFirst));
            indexOf = ll_indexOf(alumnos, auxAlumno);
            pAux = (Alumno*)ll_get(alumnos, buscarPorId(alumnos, idSecond));
            index = ll_indexOf(alumnos, pAux);

            alumnosDuplicados = ll_subList(alumnos, indexOf, index);

            if(alumnosDuplicados != NULL)
            {
                printf("\nSe DUPLICO LA LISTA con Exito.\n\n ");
                controller_ListAlumnos(alumnosDuplicados);
            }
            else
            {
                printf("\nHubo un ERROR al Duplicar la Lista.\n\n ");
            }
            system("pause");
            system("cls");
            break;
        case 13:
            system("cls");
            printf("\n-------------------------------------------------------------\n");
            printf("            CORROBORRAR ALUMNO EN LA LISTA DUPLICADA\n");
            printf("----------------------------------------------------------------\n");

            utn_getNumero(&idFirst, "\n\nIngreses el Codigo del alumno que desea Corroborar: ","Error - Codigo Incorrecto. Vuelva a ingresarlo: \n", 1, ll_len(alumnos), 3);

            auxAlumno = (Alumno*)ll_get(alumnos, buscarPorId(alumnos, idFirst));

            if(ll_contains(alumnosDuplicados, auxAlumno))
            {
                printf("\n\nEl alumno: ");
                mostrarAlumno(auxAlumno);
                printf(" se encuentra en la Lista. \n\n");

            }
            else
            {
                printf("\n\nEl alumno NO se encuentra en la Lista. \n\n");
            }
            system("pause");
            system("cls");
            break;
        case 14:
            if(alumnosDuplicados != NULL)
            {
                if(ll_containsAll(alumnos, alumnosDuplicados))
                {
                    printf("\n\nTodos los elementos de lista Duplicada estan en lista de Alumnos Original.\n\n");
                }
                else
                {
                    printf("\n\nSus elementos no estan en lista.\n\n");
                }
            }
            system("pause");
            system("cls");
            break;
        case 15:
            while(confirma!='n' && confirma!='s')
            {
                printf("\nDesea Clonar la lista de Alumnos? (n/s): ");
                fflush(stdin);
                scanf("%c", &confirma);
            }
            if(confirma=='s')
            {
                alumnosClonados = ll_clone(alumnos);
                printf("\nSe Clono la Lista con Exito.\n\n ");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Tarea Cancelada.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 16:

            utn_getNumero(&idFirst, "\nIngreses el CODIGO del Alumno: ","Error - CODIGO incorrecto. Vuelva a ingresarlo: \n", 1, ll_len(alumnos), 3);
            auxAlumno = (Alumno*)ll_get(alumnos, buscarPorId(alumnos, idFirst));
            indexOf = ll_indexOf(alumnos, auxAlumno);
            if(indexOf!=-1)
            {
                printf("Se busco el indice del Alumno: ");
                mostrarAlumno(auxAlumno);
                printf("\nSu indice es: %d\n\n",indexOf);
            }
            system("pause");
            system("cls");
            break;
        case 17:
            while(confirma!='n' && confirma!='s')
            {
                printf("\nDesea Eliminar el LinkedList? (n/s): ");
                fflush(stdin);
                scanf("%c", &confirma);
            }
            if(confirma=='s')
            {
                ll_deleteLinkedList(alumnos);
                printf("\nSe Elimino el LinkedList con Exito.\n\n ");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Tarea Cancelada.\n\n");
                system("pause");
                system("cls");
            }
            break;
        }
    }
    while(option != 18);

    return 0;
}

