/*
 ============================================================================
 Name        : tp2_marquez.c
 Author      : MARQUEZ_GISELA_BELEN
 Version     :
 Copyright   : MARQUEZ_GISELA_BELEN
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"


#define INICIAL 0
#define SE_HIZO_ALTA 1
#define TAM 1001
#define TAMSEC 5
#define NAMES 50


int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    char confirma;

    int nextId = 1001;
    int flag = INICIAL;
    int flagEmployees = 0;
    eEmployee empleados[TAM];
    eSectors sectores[TAMSEC] = {{500, "Sistemas"},{501, "RRHH"},{502, "Cobranzas"},{503, "Legales"},{504, "Ventas"}};

    do
    {
        if(flagEmployees == 0)
        {
            initEmployees(empleados,TAM);
            flagEmployees = 1;
        };

        switch(menu())
        {
        case 1:
            if(altaEmpleado(empleados,TAM,&nextId,sectores,TAMSEC))
            {
                flag = SE_HIZO_ALTA;
                printf("\n\nALTA EXITOSA!\n\n");
            }
            else
            {
                printf("\n\nHUBO UN PROBLEMA EN EL ALTA.\n");
            }
            break;
        case 2:
            if(flag == SE_HIZO_ALTA)
            {
                if (modificarDatos(empleados,TAM,sectores,TAMSEC))
                {
                    printf("\n MODIFICACION EXITOSA!.\n");
                }
                else
                {
                    printf("\n HUBO UN PROBLEMA EN LA MODIFICACION.\n");
                }
            }
            else
            {
                printf("ERROR - Primero se debe hacer el alta de un Empleado. \n");
            }
            break;
        case 3:
            if(flag == SE_HIZO_ALTA)
            {
                bajaEmpleado(empleados,TAM,sectores,TAMSEC);
            }
            else
            {
                printf("ERROR - Primero se debe hacer el alta de un Empleado. \n");
            }
            break;
        case 4:
            if(flag == SE_HIZO_ALTA)
            {
                system("cls");
                switch(subMenuInformes())
                {
                case 1:
                    switch(menuDeOrden())
                    {
                    case 0:
                        sortEmployees(empleados,TAM,0);
                        mostrarEmpleados(empleados,TAM,sectores,TAMSEC);
                        break;
                    case 1:
                        sortEmployees(empleados,TAM,1);
                        mostrarEmpleados(empleados,TAM,sectores,TAMSEC);
                        break;
                    case 3:
                        printf("Desea Salir?: ");
                        fflush(stdin);
                        confirma = getchar();
                        if(confirma == 's')
                        {
                            menu();
                        }
                        break;
                    }
                        break;
                    case 2:
                        reporte(empleados,TAM);
                        break;
                    case 3:
                        printf("Desea Salir?: ");
                        fflush(stdin);
                        confirma = getchar();
                        if(confirma == 's')
                        {
                            menu();
                        }
                        break;
                    }
                }
                else
                {
                    printf("ERROR - Primero se debe hacer el alta de un Empleado. \n");
                }
                break;
            case 5:
                printf("Desea Salir?: ");
                fflush(stdin);
                confirma = getchar();
                if(confirma == 's')
                {
                    seguir = 'n';
                }
                break;
            default:
                printf("Opcion incorrecta.");
            }
            system("pause");
        }
        while(seguir == 's');
        return 0;
    }
//*****************************************************************//
    int menu()
    {
        int opcion;
        system("cls");
        printf("----------------------------------------\n");
        printf("        **** ABM EMPLEADOS **** \n");
        printf("----------------------------------------\n");
        printf("\n\n");
        printf("1.- Alta Empleado. \n");
        printf("2.- Modificar Empleado. \n");
        printf("3.- Baja Empleado. \n");
        printf("4.- Informes. \n");
        printf("5.- Salir. \n");
        printf("\n");
        printf("----------------------------------------\n");
        printf("Ingrese Opcion: ");
        scanf("%d", &opcion);

        return opcion;
    }
