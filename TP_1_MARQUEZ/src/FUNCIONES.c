/*
 * FUNCIONES.c
 *
 *  Created on: 16 abr. 2021
 *      Author: gmarquez
 */
#include <stdio.h>
#include <stdlib.h>
#include "OPERACIONES.h"

int menu()
{
    int opcion;

    printf("\n---------------------------------------------------");
    printf("\n\n                Calculadora\n");
    printf("\n---------------------------------------------------");
    printf("\n1- Ingresar el primer operando");
    printf("\n2- Ingresar el segundo operando");
    printf("\n3- Calcular todas las operaciones");
    printf("\n           A.- Suma");
    printf("\n           B.- Resta");
    printf("\n           C.- Multiplicacion");
    printf("\n           D.- Division");
    printf("\n           E.- Factorial");
    printf("\n4- Informar resultados");
    printf("\n5- Salir\n");
    printf("\n\n Ingrese la Opcion que desea: ");
    scanf("%d", &opcion);
    printf("\n---------------------------------------------------\n");
    return opcion;
}

int pedirOperando(int* operando)
{
    int resultado = 0;
    if(operando != NULL)
    {
        printf("\n Ingrese un numero: ");
        resultado = scanf("%d", operando);
    }
    return resultado;
}

int realizamosLosCalculos(int operandoNumUno, int operandoNumDos, int *resultadoSuma, int *resultadoResta, int *resultadoMultiplicacion, float *resultadoDivision, int *factorialNumUno, int *factorialNumDos)
{
    int resultado = 0;
    if(resultadoSuma != NULL && resultadoResta != NULL && resultadoMultiplicacion != NULL && resultadoDivision != NULL && factorialNumUno != NULL && factorialNumDos != NULL)
    {
        *resultadoSuma = sumarOperandos(operandoNumUno, operandoNumDos);
        *resultadoResta = restarOperandos(operandoNumUno, operandoNumDos);
        *resultadoMultiplicacion = multiplicarOperandos(operandoNumUno, operandoNumDos);
        *resultadoDivision = dividirOperandos(operandoNumUno, operandoNumDos);
        *factorialNumUno = factoriarOperando(operandoNumUno);
        *factorialNumDos = factoriarOperando(operandoNumDos);
        resultado = 1;
    }
    return resultado;
}

int sumarOperandos(int operandoNumUno, int operandoNumDos)
{
    return operandoNumUno + operandoNumDos;
}
int restarOperandos(int operandoNumUno, int operandoNumDos)
{
    return operandoNumUno - operandoNumDos;
}
int multiplicarOperandos(int operandoNumUno, int operandoNumDos)
{
    return operandoNumUno * operandoNumDos;
}
float dividirOperandos(int operandoNumUno, int operandoNumDos)
{
    float resultado = 0;
    if(operandoNumDos !=0 )
    {
        resultado = (float) operandoNumUno / operandoNumDos;
    }
    return resultado;
}

int factoriarOperando(int operando)
{
    int factorial = 1;
    for (int i = 0; i < operando; i++)
    {
        factorial = factorial * (i + 1);
    }
    return factorial;
}

void mostrarResultados(int operandoNumUno, int operandoNumDos, int *resultadoSuma, int *resultadoResta, int *resultadoMultiplicacion, float *division, int *factorialNumUno, int *factorialNumDos)
{
    printf("\n                RESULTADOS");
    printf("\n---------------------------------------------------");
    printf("\nEl resultado de la suma %d+%d es: %d", operandoNumUno, operandoNumDos, *resultadoSuma);
    printf("\nEl resultado de la resta %d-%d es: %d", operandoNumUno, operandoNumDos, *resultadoResta);
    operandoNumDos != 0 ?
    printf("\nEl resultado de la division %d/%d es: %.2f", operandoNumUno, operandoNumDos, *division) :
    printf("\nEl resultado de %d/%d es: ERROR!", operandoNumUno, operandoNumDos);
    printf("\nEl resultado de la multiplicacion %d*%d es: %d", operandoNumUno, operandoNumDos, *resultadoMultiplicacion);
    operandoNumUno >= 0 && operandoNumUno <= 12 ? printf("\nEl factorial de %d es: %d ", operandoNumUno, *factorialNumUno) :
        printf("\nNo se puede mostrar el factorial del primer operando ");
    operandoNumDos >= 0 && operandoNumDos <= 12 ? printf("y el factorial de %d es: %d", operandoNumDos, *factorialNumDos) :
        printf("y no se puede mostrar el factorial del segundo operando");
    printf("\n---------------------------------------------------");
}


