#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    FILE* f = NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f = fopen(path,"r");
        if(f != NULL)
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
            todoOk = 1;
            fclose(f);
        }
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* f = NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f = fopen(path,"rb");
        if(f!= NULL)
        {
            if(parser_EmployeeFromBinary(f, pArrayListEmployee))
            {
                todoOk = 1;
            }
            fclose(f);
        }
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];
    Employee* auxEmpleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("\n----------------------------------------------------------------\n");
        printf("                     ALTA DE EMPLEADO\n");
        printf("----------------------------------------------------------------\n");
        if(utn_getNombre(nombre,128,"Ingrese nombre: ","Error en el Nombre, solo se permiten letras y hasta 20 caracteres\n",3) &&
                utn_getNumero(&horasTrabajadas,"Ingrese cantidad de horas trabajadas: ", "Error en las horas. Vuelva a intentarlo (de 0 a 5000)\n",0,5000,3) &&
                utn_getNumero(&sueldo,"Ingrese sueldo: ", "Error. (de 1 a 500000)\n",1,500000,3))
        {
            id = employee_generateId(pArrayListEmployee, ll_len(pArrayListEmployee));
            auxEmpleado = employee_newParametrosNoEsStr(id, nombre, horasTrabajadas, sueldo);
            ll_add(pArrayListEmployee, auxEmpleado);
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmployee;
    int todoOk = 0;
    int idEmp;
    int sueldoEmp;
    int horasEmp;
    int index;

    char opcion = 'y';
    char nombre[100];

    system("cls");

    if (pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee); //Muestro la lista de empleados

        utn_getNumero(&idEmp, "\nIngreses el ID del empleado a modificar: ","Error - ID incorrecto. Vuelva a ingresarlo: \n", 1, 50000, 3);

        index = buscarPorId(pArrayListEmployee,idEmp); //Busco el empleado por ID

        if (index == -1)
        {
            printf("El empleado que busca no existe.\n\n");
            system("pause");
            system("cls");
        }
        else
        {
            pEmployee = ll_get(pArrayListEmployee, index);
            system("cls");
            mostrarEmpleado(pEmployee);

            do
            {
                switch (menuModificar())
                {
                case 1:
                    system("cls");
                    mostrarEmpleado(pEmployee);
                    if(utn_getNombre(nombre, sizeof(nombre),"Ingrese el Nuevo Nombre: ","Nombre Incorrecto, vuelva a ingresarlo: \n", 3))
                    {
                        employee_setNombre(pEmployee, nombre);
                        printf("El nombre se modifico con Exito\n\n");
                        todoOk = 1;
                        opcion = 'n';
                    }
                    break;
                case 2:
                    system("cls");
                    mostrarEmpleado(pEmployee);
                    if(utn_getNumero(&horasEmp,"Ingrese la nueva cantidad de horas: ","Error. Vuelva a ingresar la cantidad de horas\n", 1, 5000, 3))
                    {
                        employee_setHorasTrabajadas(pEmployee, horasEmp);

                        printf("Se modifico las horas correctamente. \n\n");
                        todoOk = 1;
                        opcion = 'n';
                    }
                    break;
                case 3:
                    system("cls");
                    mostrarEmpleado(pEmployee);
                    if(utn_getNumero(&sueldoEmp,"Ingrese el nuevo sueldo: ","ERROR - Vuelva a ingresar el nuevo sueldo: \n", 1, 500000, 3))
                    {
                        employee_setSueldo(pEmployee, sueldoEmp);
                        printf("Se modifico el sueldo Correctamente. \n\n");
                        todoOk = 1;
                        opcion = 'n';
                    }
                    break;
                case 4:
                    printf("\nNo se realiza ninguna modificacion.\n\n");
                    opcion = 'n';
                    todoOk = 0;
                    break;
                default:
                    printf("Opcion invalida. \n");
                }
                system("pause");
                system("cls");
            }
            while (opcion == 'y');
        }
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int id;
    int index;
    char confirma;
    Employee* auxEmpleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        printf("\n-------------------------------------------------------------\n");
        printf("                     BAJA DE EMPLEADOS\n");
        printf("----------------------------------------------------------------\n");
        todoOk=1;

        controller_ListEmployee(pArrayListEmployee); //Muestro la lista de empleados

        utn_getNumero(&id, "\nIngreses el ID del empleado a eliminar: ","Error - ID incorrecto. Vuelva a ingresarlo: \n", 1, 50000, 3);
        index = buscarPorId(pArrayListEmployee, id);
        if(index!=-1)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee, index);
            printf("\n\n");
            mostrarEmpleado(auxEmpleado);

            while(confirma!='n' && confirma!='s')
            {
                printf("\nConfirma la baja? (n/s): ");
                fflush(stdin);
                scanf("%c", &confirma);
            }
            if(confirma=='s')
            {
                ll_remove(pArrayListEmployee,index);
                printf("\nSe Elimino el Empleado con Exito.\n\n ");
                todoOk=1;
                system("pause");
                system("cls");
            }
            else
            {
                printf("Baja cancelada.\n\n");
                todoOk=0;
                system("pause");
                system("cls");
            }
        }
        else
        {
            printf("No se encontro al empleado.\n\n");
            todoOk=0;
            system("pause");
            system("cls");
        }
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("-----------------------------------------------------\n");
        printf("   Id            Nombre     Horas Trabajadas   Sueldo\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, i));
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    if (pArrayListEmployee != NULL)
    {
        employee_OrdenarEmpleados(pArrayListEmployee);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];

    Employee* auxEmpleado = NULL;

    FILE* f = NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f = fopen(path, "w");
        if(f ==NULL)
        {
            todoOk = 0;
        }
        else
        {
            fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");
            for(int i=0; i < ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmpleado!=NULL &&
                        employee_getId(auxEmpleado, &id) &&
                        employee_getNombre(auxEmpleado, nombre) &&
                        employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas) &&
                        employee_getSueldo(auxEmpleado, &sueldo))
                {
                    fprintf(f, "%d,%s,%d,%d\n", id,nombre,horasTrabajadas,sueldo);
                }
            }
            todoOk = 1;
            fclose(f);
        }
    }
    return todoOk;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    Employee* auxEmpleado=NULL;

    FILE* f = NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f = fopen(path, "wb");
        if(f == NULL)
        {
            todoOk = 0;
        }
        else
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                if(fwrite(auxEmpleado, sizeof(Employee), 1, f)!=1)
                {
                    todoOk = -1;
                    break;
                }
            }
            fclose(f);
        }
    }
    return todoOk;

}


