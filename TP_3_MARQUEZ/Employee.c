#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"


/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo Employee
 *
 * \return Employee* retorna un puntero al lugar de la memoria asignado
 *
 */
Employee* employee_new()
{
    Employee *newEmployee;
    newEmployee = (Employee*) calloc(sizeof(Employee), 1);

    if (newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }

    return newEmployee;
}

/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo Employee cargando en todos sus campos los datos pasados como parametros en formato de array de caracteres
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldo char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee *newEmployee;
    newEmployee = employee_new();

    int auxId;
    int auxHoras;
    int auxSueldo;

    auxId = atoi(idStr);
    auxHoras = atoi(horasTrabajadasStr);
    auxSueldo = atoi(sueldo);

    if (newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL)
    {
        employee_setId(newEmployee, auxId);
        employee_setNombre(newEmployee, nombreStr);
        employee_setSueldo(newEmployee, auxSueldo);
        employee_setHorasTrabajadas(newEmployee, auxHoras);
    }
    return newEmployee;
}


/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo Employee cargando en todos sus campos los datos pasados como parametros en los formatos correspondientes
 *
 * \param id int
 * \param nombre char*
 * \param horasTrabajadas int
 * \param sueldo int
 * \return Employee*
 *
 */
Employee* employee_newParametrosNoEsStr(int id, char* nombre, int horasTrabajadas, int sueldo)
{
    Employee* newEmployee = employee_new();

    if(newEmployee!=NULL)
    {
        employee_setId(newEmployee, id);
        employee_setNombre(newEmployee, nombre);
        employee_setHorasTrabajadas(newEmployee, horasTrabajadas);
        employee_setSueldo(newEmployee, sueldo);
    }

    return newEmployee;
}


/** \brief Libera el espacio en memoria apuntado por "this"
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee *this)
{
    if (this != NULL)
    {
        free(this);
    }
}


// FUNCIONES ID //

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (id >= 0)
        {
            this->id = id;
            todoOk = 1;
        }
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if (this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;

}

//  FUNCIONES NOMBRE

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if (this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

//FUNCIONES HORAS
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if (horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            todoOk = 1;
        }
    }
    return todoOk;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

// FUNCIONES SUELDO
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if (this != NULL)
    {
        if(sueldo>=0)
        {
            this->sueldo = sueldo;
            todoOk = 1;
        }
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}



// MOSTRAR UN EMPLEADO
/** \brief muestra solo un empleado
 *
 * \param this Employee*
 * \return int
 *
 */
int mostrarEmpleado(Employee* this)
{
    int retorno = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(this!=NULL &&
            employee_getId(this, &id) &&
            employee_getNombre(this, nombre) &&
            employee_getHorasTrabajadas(this, &horasTrabajadas) &&
            employee_getSueldo(this, &sueldo))
    {
        printf(" %4d   %16s     %8d     %10d\n",id,nombre,horasTrabajadas,sueldo);
        retorno=1;
    }
    return retorno;
}

// GENERAR ID

/** \brief Genera el Id para cada dato, siempre suma uno mas al mayor
 *
 * \param pArrayListEmployee LinkedList*
 * \param len int
 * \return int
 *
 */
int employee_generateId(LinkedList* pArrayListEmployee, int len)
{
    int idMax=0;
    int idActual;
    Employee* auxEmpleado;

    if(!ll_isEmpty(pArrayListEmployee))
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmpleado, &idActual);
            if(idActual>idMax || i==0)
            {
                idMax=idActual;
            }
        }
    }
    return idMax+1;
}

// BUSCAR ID

/** \brief Busca al empleado por ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
int buscarPorId(LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    int idAux;
    Employee* pEmployee;

    for(int index = 0; index < ll_len(pArrayListEmployee); index++)
    {
        pEmployee = ll_get(pArrayListEmployee, index);
        if(employee_getId(pEmployee, &idAux) == 1 && idAux == id)
        {
            retorno = index;
        }
    }
    return retorno;
}

// MENUS

int menuOpciones()
{
    int opcion=-1;
    printf("    -----------------------  MENU PRINCIPAL  -----------------------\n");
    printf("    ----------------------------------------------------------------\n");
    printf("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3- Alta de empleado.\n");
    printf("4- Modificar datos de empleado.\n");
    printf("5- Baja de empleado.\n");
    printf("6- Listar empleados.\n");
    printf("7- Ordenar empleados.\n");
    printf("8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9- Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10- Salir.\n");
    printf("    ----------------------------------------------------------------\n");

    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 10, 3);
    return opcion;
}

int menuModificar()
{
    int opcion;
    printf("\n\n    ---------------------  MENU PARA MODIFICAR  --------------------\n");
    printf("    ----------------------------------------------------------------\n");
    printf("1- Modificar nombre: \n");
    printf("2- Modificar Horas trabajadas: \n");
    printf("3- Modificar Sueldo: \n");
    printf("4- Salir\n");
    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 4, 5);
    return opcion;
}

int menuOrdenar()
{
    int opcion;
    printf("\n\n    ---------------------  MENU PARA ORDENAR  ----------------------\n");
    printf("    ----------------------------------------------------------------\n");
    printf("1- Ordenar por Nombre: \n");
    printf("2- Ordenar por Horas trabajadas: \n");
    printf("3- Ordenar por Sueldo: \n");
    printf("4- Salir\n");
    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 4, 5);
    return opcion;
}


// ORDENAMIENTO

/** \brief llama a cada funcion de ordenamiento y la ejecuta
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_OrdenarEmpleados(LinkedList *pArrayListEmployee)
{
    int todoOk = 0;
    system("cls");

    if (pArrayListEmployee != NULL)
    {
        switch (menuOrdenar())
        {
        case 1: /* NOMBRE */
            system("cls");
            printf("\n\n    ---------------------  ORDENADO POR NOMBRE  --------------------\n");
            printf("    ----------------------------------------------------------------\n");
            ll_sort(pArrayListEmployee, employee_OrdenarPorNombre, 1);
            controller_ListEmployee(pArrayListEmployee);
            todoOk = 1;
            break;
        case 2: /* HORAS */
            system("cls");
            printf("\n\n    ---------------------  ORDENADO POR HORAS  --------------------\n");
            printf("    ----------------------------------------------------------------\n");
            ll_sort(pArrayListEmployee, employee_OrdenarPorHoras, 1);
            controller_ListEmployee(pArrayListEmployee);
            todoOk = 1;
            break;
        case 3: /* SUELDO */
            system("cls");
            printf("\n\n    ---------------------  ORDENADO POR SUELDO  --------------------\n");
            printf("    ----------------------------------------------------------------\n");
            ll_sort(pArrayListEmployee, employee_OrdenarPorSueldo, 1);
            controller_ListEmployee(pArrayListEmployee);
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
int employee_OrdenarPorNombre(void *nombreUno, void *nombreDos)
{
	char empleadoA[128];
	char empleadoB[128];
	int todoOk = 0;

	employee_getNombre(nombreUno, empleadoA);
	employee_getNombre(nombreDos, empleadoB);

	if (strcmp(empleadoA, empleadoB) > 0) {
		todoOk = 1;
	} else if (strcmp(empleadoA, empleadoB) < 0) {
		todoOk = -1;
	}

	return todoOk;
}

// POR HORAS

/** \brief ordena por horas de menor a mayor
 *
 * \param horasUno void*
 * \param horasDos void*
 * \return int
 *
 */
int employee_OrdenarPorHoras(void *horasUno, void* horasDos)
 {
	int empleadoA;
	int empleadoB;
	int todoOk = 0;

	employee_getHorasTrabajadas(horasUno, &empleadoA);
	employee_getHorasTrabajadas(horasDos, &empleadoB);

	if (empleadoA > empleadoB) {
		todoOk = 1;
	} else if (empleadoA < empleadoB) {
		todoOk = -1;
	}

	return todoOk;
}

// POR SUELDO

/** \brief ordena por sueldo de menor a mayor
 *
 * \param sueldoUno void*
 * \param sueldoDos void*
 * \return int
 *
 */
int employee_OrdenarPorSueldo(void *sueldoUno, void *sueldoDos)
{
	int empleadoA;
	int empleadoB;
	int todoOk = 0; // si los salarios son iguales, devuelve 0

	employee_getSueldo(sueldoUno, &empleadoA);
	employee_getSueldo(sueldoDos, &empleadoB);

	if (empleadoA > empleadoB) {
		todoOk = 1;
	} else if (empleadoA < empleadoB) {
		todoOk = -1;
	}
	return todoOk;
}
