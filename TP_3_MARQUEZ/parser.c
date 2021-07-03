#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char buffer[4][40];
    Employee* auxEmpleado = NULL;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        auxEmpleado=employee_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(auxEmpleado!=NULL)
        {
            while(!feof(pFile))
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3])<4)
                {
                    break;
                }
                else
                {
                    auxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                    ll_add(pArrayListEmployee, auxEmpleado);
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
 int todoOk = -1;
    int cant;
	Employee* auxEmpleado;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            auxEmpleado = employee_new();
            if(auxEmpleado!=NULL)
            {
                cant = fread(auxEmpleado, sizeof(Employee), 1, pFile);
                if(cant)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    todoOk = 1;
                }
                else
                {
                    if(feof(pFile))
                    {
                        break;
                    }
                    else
                    {
                        printf("Error al leer el archivo.\n");
                        todoOk = -1;
                        break;
                    }
                }
            }
        }
    }
    return todoOk;
}
