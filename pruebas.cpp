#include<stdio.h>


struct empresa{
	char nombre[20];
	char RUC[10];
	char direccion[20];
}empresa;

struct persona{
	char nombre[20];
	char apellido[20];
	char cedula[20];
	int sueldo;
};

struct sucursal{
	char nombre[20];
	char direccion[30];
	struct persona per[10];
}suc[3];


//PROTOTIPOS
void ingreso_datos(int c,int d);
void ingreso_cargo(int c,int d);
void datos_personales(int c,int d);
void ingreso_empresa();

int main(){
	
	int cant=0;
	
	ingreso_empresa();
	
	for(int i=0;i<3;i++){
		printf("_________SUCURSAL [%d]__________\n\n",i+1);
		printf("Nombre de la Sucursal:");
		scanf("%s",&suc[i].nombre);
		printf("Dirrecci%cn de la Sucursal:",162);
		scanf("%s",&suc[i].direccion);
		printf("Ingrese el numero de trabajadores: ");
		scanf("%d",&cant);
		for(int j=0;j<cant;j++){
			ingreso_datos(i,j);
		}
	}

	for(int i=0;i<3;i++){
		printf("_________SUCURSAL [%d]__________\n\n",i+1);
		for(int j=0;j<cant;j++){
			printf("\nNombre: %s\n",suc[i].per[j].nombre);
			printf("Apellido: %s\n",suc[i].per[j].apellido);
			printf("C%cdula: %s\n",130,suc[i].per[j].cedula);
			printf("El sueldo de la persona es: %d\n",suc[i].per[j].sueldo);
		}
		
	}
	
	
	return 0;
}

void ingreso_empresa(){
	
	printf("Ingrese nombre de la empresa:");
	scanf("%s",&empresa.nombre);
	printf("Ingrese el numero de Ruc:");
	scanf("%s",&empresa.RUC);
	printf("Ingrese la direccion:");
	scanf("%s",&empresa.direccion);
	
}

void ingreso_datos(int c,int d){
	
	datos_personales(c,d);
	ingreso_cargo(c,d);
}

void datos_personales(int c,int d){
	printf("\n---------TRABAJADOR [%d]----------\n\n",d+1);
	printf("Ingrese el nombre :");
	scanf("%s",&suc[c].per[d].nombre);
	printf("Ingrese el apellido :");
	scanf("%s",&suc[c].per[d].apellido);
	printf("Ingrese la c%cdula :",130);
	scanf("%s",&suc[c].per[d].cedula);
}

void ingreso_cargo(int c,int d){
	
	int opc=0;
	
	printf("\n.:Ingrese el tipo de cargo del trabajador:.\n");
	printf("1.Administrativo\n");
	printf("2.Operativo\n");
	printf("3.Base\n");
	scanf("%d",&opc);
	
	switch(opc){
		
		case 1:
			suc[c].per[d].sueldo = 800;
			break;
			
		case 2:
			suc[c].per[d].sueldo = 500;
			break;
			
		case 3:
			suc[c].per[d].sueldo = 300;
			break;
			
		}
	}
