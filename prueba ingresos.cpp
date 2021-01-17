#include <stdio.h>
#include <stdlib.h>

struct trabajadores{  //se define una estructura para almacenar los datos
	
	char nombre[20];
	char cargot[20];
	int sueldo;
	int horase;
	int c;
	int total;
	int extras;	
}
trabajadores[20]; // se define un limite para la cantidad de los mismos


int main()
{
	// ALMACENAMOS LA CANTIDAD DE EMPLEADOS
	int cantidad,cargo = 0,op = 0;
	
	// GUARDAMOS DENTRO DE LA VARIABLE
	printf("\nDigite la cantidad de Empleados a Registrar: ");
	scanf("%i", &cantidad);
	
	// ITERADOR PARA NUESTRO BUCLE
	int i;
	
	// CREAMOS UN BUCLE DE TIPO FOR PARA DARLE VALOR A LAS VARIABLES DE NUESTRA ESTRUCTURA
	for (i=0; i<cantidad; i++)
	{
		// LIMPIAR LA MEMORIA DE NUESTRO BUFFER
		fflush(stdin);
		
		
		// GUARDAMOS EL NOMBRE
		printf("\n Trabajador[%i] - Digite su nombre: " , i);
		gets(trabajadores[i].nombre);
		
		// GUARDAMOS LA EDAD
		printf("\n Trabajador[%i] - Digite su cargo:" , i);
		scanf("%s" ,&trabajadores[i].cargot );
		
		//CARGO
		printf("\n Escoja su cargo:\n 1.Gerente u Subgerente.\n 2.Personal Administrativo.\n 3.Personal Base.\n opcion:");
		scanf("%d",&cargo);
		if(cargo == 1){
			printf("\n su sueldo es de 800 digite el valor del mismo para confirmar\n");
			scanf("%i",&trabajadores[i].sueldo);
		}else if(cargo == 2){
			printf("\n su sueldo es de 600 digite el valor del mismo para confirmar\n");
			scanf("%i",&trabajadores[i].sueldo);
		}else if(cargo == 3){
			printf("\n su sueldo es de 400 digite el valor del mismo para confirmar\n");
			scanf("%i",&trabajadores[i].sueldo);			
		}else{
			printf("Numero Fuera de Rango");
		}
		//DIGITAMOS HORAS EXTRAS
		printf("\nUsted Ha Laborado Horas Extras?\n1.si\n2.no\nopcion:");
		scanf("%i",&cargo);
		if(cargo == 1){
			printf("\nElija un valor:\n1.25 porciento\n2.50 porciento\nopcion:");
			scanf("%d",&op);
			if(op == 1){
			printf("\nIngrese el numero de horas Laboradas");
			scanf("%i",&trabajadores[i].horase);
			trabajadores[i].extras = (2.50*1.25)*trabajadores[i].horase;				
			}else if(op == 2){
			printf("\nIngrese el numero de horas Laboradas");
			scanf("%i",&trabajadores[i].horase);
			trabajadores[i].extras = (2.50*1.50)*trabajadores[i].horase;				
			}	
		}else{
			printf("\n");
		}
		//DIGITAMOS COMISIONES
		printf("\nUsted Posee Bonos u Comisiones?\n1.si\n2.no\nopcion:");
		scanf("%i",&cargo);
		if(cargo == 1){
			printf("\nIngrese el monto");
			scanf("%i",&trabajadores[i].c);
		}else{
			printf("\n");
		}
		trabajadores[i].total = trabajadores[i].sueldo+trabajadores[i].extras+trabajadores[i].c;
	}

	
			
	system("clear");
	// IMPRIMIR LOS RESULTADOS DE NUESTRA ESTRUCTURA
		printf("\t\t\t\t                         ----------INGRESOS----------\n");
	for (i=0; i<cantidad; i++)
	{
		

	// IMPRIMIMOS TODOS LOS DATOS

	printf("\n Trabajador[%i] - Nombre: %s - Cargo: %s - Sueldo: %i - Horas Extras: %i - Comisiones: %i - TOTAL: %i",i, trabajadores[i].nombre ,trabajadores[i].cargot,trabajadores[i].sueldo,trabajadores[i].horase,trabajadores[i].c,trabajadores[i].total);
		
		
	}
	

	
	return 0;
	
}
