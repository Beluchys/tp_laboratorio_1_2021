#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        option = menuOpciones();
        switch(option)
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("\nLa lista creo Correctamente como .csv\n\n");
            }
            else
            {
                printf("\nOcurrio un error al crear la Lista.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            if(controller_loadFromBinary("data.bin",listaEmpleados))
            {
                printf("\nLa lista creo Correctamente como .bin\n\n");
            }
             else
            {
                printf("\nOcurrio un error al crear la Lista.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
             if(controller_addEmployee(listaEmpleados))
                {
                    printf("El empleado se cargo con exito!\n\n");
                }
                else
                {
                    printf("Ocurrio un error al cargar al empleado.\n\n");
                }
                system("pause");
                system("cls");

            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            if(controller_removeEmployee(listaEmpleados))
            {
                printf("Se realizo la tarea correctamente.\n\n");
            }else
                {
                    printf("Ocurrio un error en la tarea.\n\n");
                }
                 system("pause");
                system("cls");

            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            system("pause");
            system("cls");
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            if(controller_saveAsText("data.csv", listaEmpleados))
            {
                printf("La lista se Guardo Correctamente como .csv.\n\n");
            }
            else
            {
                printf("Ocurrio un error al guardar la Lista.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 9:
            if(controller_saveAsBinary("data.bin", listaEmpleados))
            {
                printf("La lista se Guardo Correctamente como .bin\n\n");
            }
            else
            {
                printf("Ocurrio un error al guardar la Lista.\n\n");
            }
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 10);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

