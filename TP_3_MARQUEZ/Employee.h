#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Employee* employee_newParametrosNoEsStr(int id, char* nombre, int horasTrabajadas, int sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int menuOpciones();
int mostrarEmpleado(Employee* this);
int menuOrdenar();
int menuModificar();

int employee_OrdenarPorNombre(void *nombreUno, void *nombreDos);
int employee_OrdenarPorHoras(void *horasUno, void* horasDos);
int employee_OrdenarPorSueldo(void *sueldoUno, void *sueldoDos);

#endif // employee_H_INCLUDED
