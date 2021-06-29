/*
 * arrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: gmarquez
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

typedef struct
{
    int id;
    char descripcion[20];
} eSectors;


#endif /* ARRAYEMPLOYEES_H_ */
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param lista[] Employee Pointer to array of employees
* \param tam int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee lista[], int tam);
//******************************************************************************//
/** \brief alta de empleado
 *
 * \param lista[] eEmployee Es el array
 * \param tam int es el tamaño del array
 * \param pId int* recibe el Id de empleado
 * \param sectores[] eSectors recibe el array de sectores
 * \param tamSec int el tamaño del array de sectores
 * \return int retorna -1 si hubo error, o retorna 1 si esta todo ok!
 *
 */
int altaEmpleado(eEmployee lista[], int tam, int* pId, eSectors sectores[], int tamSec);
//******************************************************************************//
/** \brief Busca un lugar en el array de empleados
 *
 * \param lista[] eEmployee array de empleado
 * \param tam int tamaño del array
 * \return int retorna -1 si no hay lugar / sino la posición disponible
 *
 */
int buscarLugar(eEmployee lista[], int tam);
//******************************************************************************//
/** \brief Muestra los sectores
 *
 * \param sectores[] eSectors array de sectores
 * \param tamSec int tamaño de array
 * \return void
 *
 */
void mostrarSectores(eSectors sectores[], int tamSec);
//******************************************************************************//
/** \brief muestra un sector
 *
 * \param unSector eSectors array de sectores
 * \return void
 *
 */
void mostrarSector(eSectors unSector);
//******************************************************************************//
/** \brief Carga la descripción del sector
 *
 * \param id int recibe el ID del sector
 * \param sectores[] eSectors array de sectores
 * \param tam int tamaño del array
 * \param descripcion[] char la cadena con el detalle para la descripción
 * \return int retorna 1 si salio ok! o 0 si no pudo realizar la funcion
 *
 */
int cargarDescripcionSector(int id, eSectors sectores[], int tam, char descripcion[]);
//******************************************************************************//
/** \brief Modifica los datos de los empleados
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \param sectores[] eSectors array de sectores
 * \param tamSec int tamaño del array
 * \return int devuelve 1 si se realizo la modificación | 0 si no
 *
 */
int modificarDatos(eEmployee lista[], int tam, eSectors sectores[], int tamSec);
//******************************************************************************//
/** \brief Submenu para modificar datos
 *
 * \return int retorna la opción seleccionada
 *
 */
int subMenuModificar();
//******************************************************************************//
/** \brief Muestra un empleado
 *
 * \param unEmpleado eEmployee array de empleado
 * \param sectores[] eSectors array de sectores
 * \param tam int tamaño del array
 * \return void
 *
 */
void mostrarEmpleado(eEmployee unEmpleado, eSectors sectores[], int tam);
//******************************************************************************//
/** \brief Muestra los empleados en lista
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \param sectores[] eSectors array de sectores
 * \param tamSec int tamaño del array de sectores
 * \return void
 *
 */
void mostrarEmpleados(eEmployee lista[], int tam, eSectors sectores[], int tamSec);
//******************************************************************************//
/** \brief busca empleado
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \param id int el id del empleado a buscar
 * \return int devuelve la posición donde se encuentra el empleado si se encuentra o -1 si no logro realizar la operación
 *
 */
int buscarEmpleado(eEmployee lista[], int tam, int id);
//******************************************************************************//
/** \brief realiza la baja del empleado
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \param sectores[] eSectors array de sectores
 * \param tamSec int tamaño del array de sectores
 * \return int devuelve 1 si se realizo la baja, 0 si no
 *
 */
int bajaEmpleado(eEmployee lista[], int tam, eSectors sectores[], int tamSec);
//******************************************************************************//
/** \brief submenu de informes
 *
 * \return int retorna la opcion
 *
 */
int subMenuInformes();
//******************************************************************************//
/** \brief Ordena los empleados
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \param order int el parametro como desea que se ordene la lista
 * \return int devuelve -1 sino se realizo, o 0 si se realizo la tarea
 *
 */
int sortEmployees(eEmployee lista[], int tam, int order);
//******************************************************************************//
/** \brief sub menu del orden de los empleados
 *
 * \return int la opción 1 o 0 segun como se desea ordenar
 *
 */
int menuDeOrden();
//******************************************************************************//
/** \brief Reporte de Salarios
 *
 * \param lista[] eEmployee array de empleados
 * \param tam int tamaño del array
 * \return int retorna 0 si se realizo el informe oke, o -1 si algo salio mal
 *
 */
int reporte(eEmployee lista[], int tam);
//******************************************************************************//
/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \param mensaje char* El mensaje a ser mostrado
 * \param mensajeError char* El mensaje de error a ser mostrado
 * \param minimo int El numero minimo a ser aceptado
 * \param maximo int El numero maximo a ser aceptado
 * \param reintentos int Cantidad de reintentos permitidos
 * \return int Retorna 0 si se obtuvo el numero o -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
//******************************************************************************//
/** \brief verifica si es un entero
 *
 * \param pResultado int* recibe el parametro por puntero
 * \return int retorna 0 si es entero o -1 si no lo es
 *
 */
int getInt(int* pResultado);
//******************************************************************************//
/** \brief
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
int myGets(char* cadena, int longitud);
//******************************************************************************//
/** \brief verifica si es una cadena numerica
 *
 * \param cadena char* recibe la cadena como puntero
 * \return int retorna 0 si es numerica | 1 si no lo es
 *
 */
int esNumerica(char* cadena);
//******************************************************************************//
