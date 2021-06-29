/*
 * OPERACIONES.h
 *
 *  Created on: 16 abr. 2021
 *      Author: gmarquez
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#endif /* OPERACIONES_H_ */

/** \brief MENU DE CALCULADORA
 *
 * \return int Mostramos el menu
 *
 */
int menu();

/** \brief PIDE LOS OPERANDO
 *
 * \param operando int* recibe los operando
 * \return int guarda el operando ok/ error
 *
 */
int pedirOperando(int* operando);

/** \brief REALIZA LOS CALCULOS DE LOS OPERANDOS GUARDADOS
 *
 * \param operandoNumUno int
 * \param operandoNumDos int
 * \param resultadoSuma int*
 * \param resultadoResta int*
 * \param resultadoMultiplicacion int*
 * \param resultadoDivision float*
 * \param factorialNumUno int*
 * \param factorialNumDos int*
 * \return int CALCULOS REALIZADOS
 *
 */
int realizamosLosCalculos(int operandoNumUno, int operandoNumDos, int *resultadoSuma, int *resultadoResta, int *resultadoMultiplicacion, float *resultadoDivision, int *factorialNumUno, int *factorialNumDos);

/** \brief REALIZA LA SUMA DE LOS DOS OPERANDO
 *
 * \param operandoNumUno int
 * \param operandoNumDos int
 * \return int RESULTADO DE SUMA
 *
 */
int sumarOperandos(int operandoNumUno, int operandoNumDos);

/** \brief REALIZA LA RESTA DE LOS OPERANDO
 *
 * \param operandoNumUno int
 * \param operandoNumDos int
 * \return int RESULTADO DE RESTA
 *
 */
int restarOperandos(int operandoNumUno, int operandoNumDos);

/** \brief MULTIPLICA LOS OPERANDO
 *
 * \param operandoNumUno int
 * \param operandoNumDos int
 * \return int RESULTADO DE LA MULTIPLICACION
 *
 */
int multiplicarOperandos(int operandoNumUno, int operandoNumDos);

/** \brief REALIZA LA DIVISION DE LA DIVISION
 *
 * \param operandoNumUno int
 * \param operandoNumDos int
 * \return float RESULTADO DE LA DIVISION
 *
 */
float dividirOperandos(int operandoNumUno, int operandoNumDos);

/** \brief REALIZA EL FACTORIAL
 *
 * \param operando int
 * \return int NOS DA EL FACTORIAL EN EL CASO DE SER POSIBLE
 *
 */
int factoriarOperando(int operando);

/** \brief MUESTRA LOS RESULTADOS
 *
 * \param operandoNumUno int
 * \param operandoNumDos int
 * \param resultadoSuma int*
 * \param resultadoResta int*
 * \param resultadoMultiplicacion int*
 * \param division float*
 * \param factorialNumUno int*
 * \param factorialNumDos int*
 * \return void NOS RETORNA TODOS LOS RESULTADOS
 *
 */
void mostrarResultados(int operandoNumUno, int operandoNumDos, int *resultadoSuma, int *resultadoResta, int *resultadoMultiplicacion, float *division, int *factorialNumUno, int *factorialNumDos);
