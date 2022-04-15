/*
 * employee.h
 *
 *  Created on: 15 oct. 2021
 *      Author: ojose
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct {
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;// 1 disponible 0 ocupado
}eEmpleado;

int iniLista(eEmpleado arrayIni[],int tamano);
int unEspaLibre(eEmpleado arrayIni[], int tamano, int* auxEspacio);
int cargaEmpleado(eEmpleado arrayIni[], int tamano);
int buscarId(eEmpleado arrayEmpl[], int tamano, int auxId);
int modificarEmpleado(eEmpleado arrayIni[], int tamano, int id);
int bajaEmpleado(eEmpleado arrayIni[], int tamano, int id);
int impriEmpleado(eEmpleado arrayIni[], int tamano);
int ordenarEmpleado(eEmpleado arrayApe[],int tamno, int order);
float sumaSueldos(eEmpleado sumSuelEmp[],int tamno);
int CantidadEmpleado(eEmpleado promeEmple[],int tamno);
float promeSueldos(eEmpleado promeEmple[],int tamno);





#endif /* EMPLOYEE_H_ */
