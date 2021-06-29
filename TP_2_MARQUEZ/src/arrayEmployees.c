/*
 * arrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: gmarquez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#define AUX_CHAR 50

int initEmployees(eEmployee lista[], int tam)
{
    int retorno = -1;
    if(lista != NULL && tam > 0)
    {
        retorno = 0;
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
    }
    return retorno;
}
//******************************************************************************//
int altaEmpleado(eEmployee lista[], int tam, int* pId, eSectors sectores[], int tamSec)
{
    system("cls");
    printf("    **** ALTA EMPLEADO ****   \n\n");
    printf("Legajo: %d \n", *pId);
    int indice;
    char auxChar[AUX_CHAR];

    int todoOk = -1; //false
    eEmployee nuevoEmpleado;

    if(lista !=NULL && tam > 0 && pId != NULL)
    {
        indice = buscarLugar(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el Sistema. \n");
        }
        else
        {
            nuevoEmpleado.id = *pId;


    printf("Ingrese Nombre del Empleado: ");
          fflush(stdin);
          gets(auxChar);

          while(strlen(auxChar) <= 2 || strlen(auxChar)>=51)
                      {
                          printf("Nombre demasiado Corto / Largo, vuelva a ingresarlo: ");
                          fflush(stdin);
                          gets(auxChar);
                      }
                      strcpy(nuevoEmpleado.name, auxChar);

            printf("Ingrese Apellido del Empleado: ");
            fflush(stdin);
            gets(auxChar);

            while(strlen(auxChar) <= 2 || strlen(auxChar)>=51)
                        {
                            printf("Apellido demasiado Corto / Largo, vuelva a ingresarlo: ");
                            fflush(stdin);
                            gets(auxChar);
                        }
                        strcpy(nuevoEmpleado.lastName, auxChar);

            printf("Ingrese sueldo del empleado: ");

            scanf("%f", &nuevoEmpleado.salary);
            mostrarSectores(sectores, tamSec);
            todoOk = utn_getNumero(&nuevoEmpleado.sector,"Ingrese el sector: ", "Sector Invalido. ",500,504,10);

            nuevoEmpleado.isEmpty = 0;
            lista[indice] = nuevoEmpleado;

            *pId = (*pId)+1; //ACTUALIZAMOS EL PROXIMO ID
            todoOk=1;
        }
    }
    return todoOk;
}
//******************************************************************************//
int buscarLugar(eEmployee lista[], int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
//*************************************************************//
void mostrarSectores(eSectors sectores[], int tamSec)
{
    printf("\n\n     **** LISTA DE SECTORES ****   \n\n");
    printf(" ID      DESCRIPCION SECTOR\n\n");
    for(int i=0 ; i < tamSec ; i++)
    {
        mostrarSector(sectores[i]);
    }
    printf("\n\n");
}
//*************************************************************//
void mostrarSector(eSectors unSector)
{
    printf(" %d           %10s\n", unSector.id, unSector.descripcion);

}
//**************************************************************//
int cargarDescripcionSector(int id, eSectors sectores[], int tam, char descripcion[])
{
    int todoOk = 0;
    if(id >= 500 && id <=504 && sectores != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i=0 ; i<tam ; i++)
        {
            if(sectores[i].id == id)
            {
                strcpy(descripcion, sectores[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
//*************************************************************//
int modificarDatos(eEmployee lista[], int tam, eSectors sectores[], int tamSec)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;
    char auxChar[AUX_CHAR];

    system("cls");
    printf("    **** MODIFICAR DATOS DEL EMPLEADO **** \n\n");
    mostrarEmpleados(lista, tam, sectores, tamSec);
    printf("\n\n Ingrese Legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista,tam,legajo);

    if(indice == -1)
    {
        printf("ERROR - NO EXISTE ESE EMPLEADO.\n");
    }
    else
    {

        printf("\n\n\n      ****  EMPLEADO ENCONTRADO  ****\n\n");
        printf("    ID           NOMBRE     APELLIDO    SUELDO    SECTOR\n");
        mostrarEmpleado(lista[indice], sectores, tamSec);

        do
        {

            switch(subMenuModificar())
            {
            case 1:
                printf("Ingrese el nuevo Nombre: ");
                fflush(stdin);
                gets(auxChar);

                while(strlen(auxChar) <= 2 || strlen(auxChar)>=51)
                      {
                      printf("Nombre demasiado Corto / Largo, vuelva a ingresarlo: ");
                      fflush(stdin);
                      gets(auxChar);
                      }
                     strcpy(lista[indice].name, auxChar);
                todoOk = 1;
                printf("\n");
                mostrarEmpleado(lista[indice], sectores, tamSec);

                break;
            case 2:
                printf("Ingrese el nuevo Apellido: ");
                fflush(stdin);
                gets(auxChar);

           while(strlen(auxChar) <= 2 || strlen(auxChar)>=51)
            {
             printf("Apellido demasiado Corto / Largo, vuelva a ingresarlo: ");
             fflush(stdin);
             gets(auxChar);
             }
            strcpy(lista[indice].lastName, auxChar);


                todoOk = 1;
                printf("\n");
                mostrarEmpleado(lista[indice], sectores, tamSec);
                break;
            case 3:
                printf("Ingrese sueldo del empleado: ");
                scanf("%f", &lista[indice].salary);
                todoOk = 1;
                printf("\n");
                mostrarEmpleado(lista[indice], sectores, tamSec);
                break;
            case 4:
                mostrarSectores(sectores,tamSec);
                todoOk = utn_getNumero(&lista[indice].sector,"Ingrese el sector: ", "Sector Invalido. ",500,504,10);
                printf("\n");
                mostrarEmpleado(lista[indice], sectores, tamSec);
                break;
            case 5:
                printf("Desea Salir?: ");
                fflush(stdin);
                confirma = getchar();
                if(confirma == 's')
                {
                    confirma='n';
                }
                break;
            default:
                printf("Opcion incorrecta.");
            }
        }
        while(confirma=='s');
    }
    return todoOk;
}
//*************************************************************//
int subMenuModificar()
{
    int opcion;
    printf("\n\n MODIFICAR DATOS DEL EMPLEADO\n\n ");
    printf("1.- Modificar Nombre del Empleado. \n");
    printf("2.- Modifica Apellido del Empleado. \n");
    printf("3.- Modificar Sueldo del Empleado. \n");
    printf("4.- Modificar Sector del Empleado. \n");
    printf("5.- Nada - Salir. \n");
    printf("\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
//*************************************************************//
void mostrarEmpleado(eEmployee unEmpleado, eSectors sectores[], int tam)
{

    printf("   %d      %10s    %10s       %9.2f     %d \n",
           unEmpleado.id,
           unEmpleado.name,
           unEmpleado.lastName,
           unEmpleado.salary,
           unEmpleado.sector
          );
}
//*************************************************************//
void mostrarEmpleados(eEmployee lista[], int tam, eSectors sectores[], int tamSec)
{
    int flag = 1;

    printf("                       ****LISTA DE EMPLEADOS****       \n");
    printf("\n");
    printf("    ID           NOMBRE       APELLIDO        SUELDO     SECTOR\n");
    for(int i=0 ; i < tam ; i++)
    {
        if( !lista[i].isEmpty  )  //SI NO ESTA VACIA ENTRA ---
        {
            mostrarEmpleado(lista[i], sectores, tamSec);
            flag=0;
        }
    }
    if(flag ==1)
    {
        printf("No hay empleados para Mostrar. \n");
    }
    printf("\n");
}
//*************************************************************//
int buscarEmpleado(eEmployee lista[], int tam, int id)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i=0 ; i<tam ; i++)
        {
            if(!lista[i].isEmpty && lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
//*************************************************************//
int bajaEmpleado(eEmployee lista[], int tam, eSectors sectores[], int tamSec)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;


    system("cls");
    printf("    **** BAJA EMPLEADO **** \n\n");

    mostrarEmpleados(lista, tam, sectores, tamSec);
    printf("\n\n Ingrese el ID del empleado: ");
    scanf("%d", &legajo);


    indice = buscarEmpleado(lista, tam, legajo);

    if(indice == -1)
    {
        printf("El empleado que desea buscar NO EXISTE EN EL SISTEMA.\n\n");
    }
    else
    {
        mostrarEmpleado(lista[indice], sectores, tamSec);
        printf("Confirma la baja? \n");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            lista[indice].isEmpty = 1;
            todoOk = 1;
            printf("SE REALIZO LA BAJA DE FORMA CORRECTA.\n");
        }
        else
        {
            printf("BAJA CANCELADA POR EL USUARIO.\n");
        }
    }
    return todoOk;
}
//*************************************************************************************//
int subMenuInformes()
{
    int opcion;
    system("cls");
    printf("            **** INFORMES **** \n");
    printf("\n");
    printf("1.- Lista de empleados. \n");
    printf("2.- Informe sueldos y el Total de Sueldos. \n");
    printf("3.- Salir. \n");
    printf("\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
//*************************************************************************************//
int sortEmployees(eEmployee lista[], int tam, int order)
{
    int retorno=-1;
    eEmployee auxEmpleado;

    if(lista!=NULL && tam>0)
    {
        retorno=0;
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(!order && ((strcmp(lista[i].lastName, lista[j].lastName)<0) || (strcmp(lista[i].lastName, lista[j].lastName)==0 && lista[i].sector<lista[j].sector)))
                {
                    auxEmpleado=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxEmpleado;
                }
                else if(order && ((strcmp(lista[i].lastName, lista[j].lastName)>0) || (strcmp(lista[i].lastName, lista[j].lastName)==0 && lista[i].sector>lista[j].sector)))
                {
                    auxEmpleado=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxEmpleado;
                }
            }
        }
    }
    return retorno;
}
//***********************************************************************//
int menuDeOrden()
{
    int opcion;
    system("cls");
    printf("            **** COMO DESEA ORDENARLO **** \n");
    printf("\n");
    printf("0.- Descendente. \n");
    printf("1.- Ascendente. \n");
    printf("3.- Salir. \n");
    printf("\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
//*******************************************************************************//
int reporte(eEmployee lista[], int tam)
{
    int retorno=-1;
    int contadorEmpleados=0;
    int empleadosSalarioMayor=0;
    float acumuladorSalario=0;
    float salarioPromedio;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                acumuladorSalario+=lista[i].salary;
                contadorEmpleados++;
            }
        }
        salarioPromedio = acumuladorSalario/contadorEmpleados;

        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].salary > salarioPromedio)
            {
                empleadosSalarioMayor++;
            }
        }

        printf("El total de los salarios es de $%.2f\n",acumuladorSalario);
        printf("El promedio de los salarios es de $%.2f\n",salarioPromedio);
        printf("La cantidad de empleados que superan el salario promedio es de: %d\n",empleadosSalarioMayor);
        retorno=0;
    }
    return retorno;
}
//***************************************************************************
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;
	while(reintentos > 0)
        {
		reintentos--;
		printf("%s",mensaje);
		fflush(stdin);
		if(getInt(&bufferInt) == 0){
			if(bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 1;
				break;
			}
		}
        printf("%s",mensajeError);
	}
	return retorno;
}
//***************************************************************************

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[50];
	if(pResultado != NULL){
		if( myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer) ){
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
//***************************************************************************
int myGets(char* cadena, int longitud)
{
    int retorno = -1;

	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena )
    {
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno=0;
	}
	return retorno;
}
//***************************************************************************
int esNumerica(char* cadena)
{
	int i = 0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0){
		while(cadena[i] != '\0'){
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

