/*
 ============================================================================
 Name        : TP_MARQUEZ.c
 Author      : MARQUEZ_GISELA_BELEN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "OPERACIONES.h"

#define INICIAL 0
#define SE_INGRESO_PRIMER_OPERANDO 1
#define SE_INGRESO_SEGUNDO_OPERANDO 2
#define SE_REALIZO_LAS_OPERACIONES 3

int main(void)
{
	setbuf(stdout, NULL);
    int flagOperadores = INICIAL;
    int operandoNumUno;
    int operandoNumDos;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int factorialNumUno;
    int factorialNumDos;
    float resultadoDivision;
    char seguir = 's';
    char confirmar;


    do
    {
        switch (menu())
        {
        case 1:
            pedirOperando(&operandoNumUno);
            flagOperadores = SE_INGRESO_PRIMER_OPERANDO;
            break;
        case 2:
            if(flagOperadores == SE_INGRESO_PRIMER_OPERANDO)
            {

                pedirOperando(&operandoNumDos);
                flagOperadores = SE_INGRESO_SEGUNDO_OPERANDO;
            }
            else
            {
                printf("ERROR - DEBE INGRESAR EL PRIMER OPERANDO. \n");
            }
            break;
        case 3:
            if(flagOperadores == SE_INGRESO_SEGUNDO_OPERANDO)
            {
                printf("\n    (A=%d) & (B=%d)\n\n", operandoNumUno, operandoNumDos);
                realizamosLosCalculos(operandoNumUno, operandoNumDos, &resultadoSuma, &resultadoResta, &resultadoMultiplicacion, &resultadoDivision, &factorialNumUno, &factorialNumDos);
                flagOperadores = SE_REALIZO_LAS_OPERACIONES;
                printf("Se realizaron todos los calculos con los Operadores Ingresados. \n");
            }
            else if(flagOperadores == SE_INGRESO_PRIMER_OPERANDO)
            {
            	system("cls");
                printf("ERROR - DEBE INGRESAR EL SEGUNDO OPERANDO. \n");
            }
            else
            {
                printf("ERROR - DEBE INGRESAR LOS DOS OPERANDO PARA PODER REALIZAR LOS CALCULOS. \n");
            }
            break;
        case 4:
            if(flagOperadores == SE_REALIZO_LAS_OPERACIONES)
            {
                mostrarResultados(operandoNumUno, operandoNumDos, &resultadoSuma, &resultadoResta, &resultadoMultiplicacion, &resultadoDivision, &factorialNumUno, &factorialNumDos);
            }
            else if(flagOperadores == SE_INGRESO_SEGUNDO_OPERANDO)
            {
                printf("ERROR - DEBE REALIZAR LOS CALCULOS. \n");
            }
            else
            {
                printf("ERROR - DEBE INGRESAR LOS DOS OPERANDOS. \n");
            }
            break;
        case 5:
            printf("Desea confirmar la salida?. \n");
            fflush(stdin);
            confirmar = getchar();
            if(confirmar == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("ERROR - OPCION INVALIDA");
            fflush(stdin);
            break;
        }
    }
    while(seguir == 's');

	return EXIT_SUCCESS;
}
