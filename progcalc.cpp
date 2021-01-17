#include<stdio.h>
#include<string.h> //gets,strcmp
#include<conio.h>//getch
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<locale.h>//CARACTERES ESPECIALES
#define USUARIO "admin"
#define CLAVE "password"
#define LONGITUD 80
#define set locale 
#define CANTIDAD 5
#define COLUMNAS 5
#define LARG 20

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct empresa{
	char nombre[20];
	char RUC[10];
	int zona;
}empresa;

struct rol{
	float horas_25;
	float horas_50;
	float Bonos;
	float Aporte_P;
	float Prestamo;
	float Anticipos;
	float Multas;
};

struct persona{
	char nombre[20];
	char apellido[20];
	char cedula[20];
	char descripcion[30];
	int sueldo;
	int horase;
	struct rol r;
	float extras;
	float bono;
	float totalingreso;
	float aportepersonal;
	float prestamoquirografario;
	float anticiposueldo;
	float multas;
	float totaldeduccion;
	float fondoreserva;
	float liquido;
};

struct sucursal{
	char nombre[20];
	char direccion[30];
	struct persona per[10];
}suc[2];


//PROTOTIPOS
void menu_principal(int *ptr);
void ingreso_sucursal(int *ptr, int v[10]);
void ingreso_datos(int c,int d);
void ingreso_cargo(int c,int d);
void datos_personales(int c,int d);
void ingreso_empresa();
void consulta_individual();
int validarcedula(char cedula[50]);
int validanombre(char nombre[50]);
void ingresos(int c,int d);
void egresos(int c,int d);

int main(int argc, char *argv[]) {
	
	system("color a");
	setlocale(LC_ALL,"spanish");//LOCALE LIBRERIA EN ESPAÑOL
	char usuario[LONGITUD + 1]; //cadena de longitud 80 + 1
	char clave[LONGITUD + 1];
	int intento = 0;
	int ingresa = 0;
	char caracter;
	char nombre[LONGITUD + 1];
	char apellido[LONGITUD + 1];
	char dni[LONGITUD - 70];
	char nombre_E[LONGITUD + 1];	
	int i2=0,op = 0,salida = 0,edad = 0,numero_doc = 0,op2=0;	
	do{
	system("cls");	
	printf("\n\t\t\t----------------");
	printf("\n\t\t\t INICIE SESIÓN\n");
	printf("\t\t\t----------------\n");
	printf("\n\tUSUARIO: ");
	gets(usuario); //funcion para leer la cadena de caracteres.
	printf("\tCLAVE:");
	while(caracter = getch()){
		if (caracter == 13) {
		clave[i2] = '\0';//marca el final de la cadena.	
		break;	
		}else if(caracter == 8){
			if(i2>0){
			i2--;
			printf("\b \b");//para borrar los caracteres.				
			}
			
		}else{
		printf("*");
		clave[i2] = caracter; //se guarda caracteres en clave posicion i.
		i2++;		
		}
	}
	
	if (strcmp(usuario,USUARIO)==0 && strcmp(clave,CLAVE)==0) {//compara y se define con strcmp por que se consideran punteros
		ingresa = 1; //si es 1 es verdadero	
			system("cls");	
	}else{
		printf("\nUsuario y/o clave incorrectos\n");
		intento ++;   //cuenta el numero de intentos en el login y controla el do while.
	}
		
	}while(intento<3 && ingresa == 0);
	int opc_P=0,opc1=1,cant=0;
	int vec_can[10];
	
	//ingreso_empresa();
	do{
		menu_principal(&opc_P);
		if(opc_P==1){
			
			ingreso_sucursal(&cant,vec_can);
			for(int j=0;j<vec_can[empresa.zona-1];j++){
				ingreso_datos(empresa.zona-1,j);
			}
		}else if(opc_P==2){
			while(opc1==1){
				consulta_individual();
				printf("Desea Realizar Otra Consulta?\n");
				printf("1.SI\t2.NO\n");
				do{
					scanf("%d",&opc1);
				}while(opc1<0 || opc1>2);
				
			}
			
		}
	}while(opc_P!=4);
	
}

void ingreso_empresa(){
	
	printf("Ingrese nombre de la empresa:");
	scanf("%s",&empresa.nombre);
	printf("Ingrese el numero de Ruc:");
	scanf("%s",&empresa.RUC);
}

void menu_principal(int *ptr){
	
	printf("\n\t\t\t======================================================================");		
	printf("\n\t\t\t\t\tBienvenido Al Sistema De Rol De Pagos\t\t\n");
	printf("\t\t\t======================================================================\n");
	printf("\n\t\t\t\tSeleccione una de las siguientes opciones:\n");
	printf("\n\t\t\t\t1.Ingreso de Empleados\n");
	printf("\n\t\t\t\t2.Reporte Individual\n");
	printf("\n\t\t\t\t3.Reporte General\n");
	printf("\n\t\t\t\t4.Salir\n");
	printf("\t\t\t======================================================================\n");	
	printf("Opción: ",162);
	do{
		scanf("%d",&*ptr);
	}while(*ptr<0 || *ptr>4);
	
}

void ingreso_sucursal(int *ptr, int v[10]){
	
	int aux=0, sw=0;
	
	printf("Ingrese zona de la sucursal:\n");
	printf("1. SUR\n");
	printf("2. NORTE\nopcion:");
	do{
		scanf("%d",&empresa.zona);
	}while(empresa.zona<0 || empresa.zona>2);
	system("clear");
	
	printf("_________SUCURSAL ");
	if(empresa.zona==1){
		printf("SUR__________\n\n");
		aux=0;
	}else{
		printf("NORTE__________\n\n");
		aux=1;
	}
		printf("Nombre de la Sucursal:");
		scanf("%s",&suc[aux].nombre);
			sw=validanombre(suc[aux].nombre);
			if(sw==1){
				do{
					printf("el dato esta mal ingresado por favor vuelva a ingresar\n");	
					scanf("%s",&suc[aux].nombre);
					sw=validanombre(suc[aux].nombre);
				}while(sw==1);
			}
		printf("Dirrección de la Sucursal:",162);
		scanf("%s",&suc[aux].direccion);
			sw=validanombre(suc[aux].direccion);
			if(sw==1){
				do{
					printf("el dato esta mal ingresado por favor vuelva a ingresar\n");	
					scanf("%s",&suc[aux].direccion);
					sw=validanombre(suc[aux].direccion);
				}while(sw==1);
			}
		printf("Ingrese el numero de trabajadores: ");
		scanf("%d",&*ptr);
		v[aux]=*ptr;
		system("clear");
}

void ingreso_datos(int c,int d){
	
	datos_personales(c,d);
	ingreso_cargo(c,d);
	ingresos(c,d);
	egresos(c,d);
	system("clear");
}

void consulta_individual(){
	
	int aux=0,aux1=0;
	
	printf("\nSucursal que desea consultar\n");
	printf("1. SUR\n");
	printf("2. NORTE\n");
	do{
		scanf("%d",&aux);
	}while(aux<0 || aux>2);
	
	aux=aux-1;
	
	printf("Numero de trabajador: ");
	do{
		scanf("%d",&aux1);
	}while(aux1<0);
	aux1=aux1-1;
	
	printf("\nNombre: %s\n",suc[aux].per[aux1].nombre);
	printf("Apellido: %s\n",suc[aux].per[aux1].apellido);
	printf("Cédula: %s\n",130,suc[aux].per[aux1].cedula);
	printf("Horas 25: %.0f\n",suc[aux].per[aux1].r.horas_25);
	printf("El sueldo de la persona es: %d\n\n",suc[aux].per[aux1].sueldo);
	
}

void datos_personales(int c,int d){
	int sw=0;
	
	printf("\n---------TRABAJADOR [%d]----------\n\n",d+1);
	printf("Ingrese el nombre :");
	scanf("%s",&suc[c].per[d].nombre);
	
		sw=validanombre(suc[c].per[d].nombre);
		if(sw==1){
			do{
				printf("el dato esta mal ingresado por favor vuelva a ingresar\n");	
				scanf("%s",&suc[c].per[d].nombre);
				sw=validanombre(suc[c].per[d].nombre);
			}while(sw==1);
		}
	
	printf("Ingrese el apellido :");
	scanf("%s",&suc[c].per[d].apellido);
	
		sw=validanombre(suc[c].per[d].apellido);
		if(sw==1){
			do{
				printf("el dato esta mal ingresado por favor vuelva a ingresar\n");	
				scanf("%s",&suc[c].per[d].apellido);
				sw=validanombre(suc[c].per[d].apellido);
			}while(sw==1);
		}
		
	printf("Ingrese la cédula :",130);
	scanf("%s",&suc[c].per[d].cedula);
	
		sw=validarcedula(suc[c].per[d].cedula);
		if(sw==1){
			do{
				printf("el dato esta mal ingresado por favor vuelva a ingresar\n");	
				scanf("%s",&suc[c].per[d].cedula);
				sw=validarcedula(suc[c].per[d].cedula);
			}while(sw==1);
		}
	printf("Ingrese las horas al 25% : ");
	scanf("%f",&suc[c].per[d].r.horas_25);
}

void ingresos(int c,int d)
{
	int bon,cargo,op;
printf("\nUsted Ha Laborado Horas Extras?\n1.si\n2.no\nopcion:");
		scanf("%i",&cargo);
		if(cargo == 1){
			printf("\nElija un valor:\n1.25 porciento\n2.50 porciento\nopcion:");
			scanf("%d",&op);
			if(op == 1){
			printf("\nIngrese el numero de horas Laboradas");
			scanf("%.2f",&suc[c].per[d].horase);
			suc[c].per[d].extras = (2.50*1.25)*suc[c].per[d].horase;				
			}else if(op == 2){
			printf("\nIngrese el numero de horas Laboradas");
			scanf("%.2f",&suc[c].per[d].horase);
			suc[c].per[d].extras = (2.50*1.50)*suc[c].per[d].horase;				
			}	
		}else{
			printf("\n");
		}
		//DIGITAMOS COMISIONES
		printf("\nUsted Posee Bonos u Comisiones?\n1.si\n2.no\nopcion:");
		scanf("%i",&bon);
		if(bon == 1){
			printf("\nIngrese el monto");
			scanf("%i",&suc[c].per[d].bono);
		}else{
			printf("\n");
		}
		suc[c].per[d].totalingreso =suc[c].per[d].sueldo+suc[c].per[d].extras+suc[c].per[d].bono;
	}	


void egresos(int c,int d)
{	
printf("=============ingreso de egresos============");
suc[c].per[d].aportepersonal=suc[c].per[d].sueldo*0.0935;

printf("ingrese el total de prestamos solicitados");
scanf("%.2f",&suc[c].per[d].prestamoquirografario);
printf("ingrese el total de anticipos solicitados");
scanf("%.2f",&suc[c].per[d].anticiposueldo);
printf("ingrese el total de  multas acumuladas");
scanf("%.2f",&suc[c].per[d].multas);
suc[c].per[d].totaldeduccion=suc[c].per[d].aportepersonal+suc[c].per[d].prestamoquirografario+suc[c].per[d].anticiposueldo+suc[c].per[d].multas;
suc[c].per[d].fondoreserva=suc[c].per[d].sueldo*0.0833;
suc[c].per[d].liquido=suc[c].per[d].sueldo-suc[c].per[d].totaldeduccion+suc[c].per[d].fondoreserva;	
}
void ingreso_cargo(int c,int d){
	
	int opc=0,sw=0;
	
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
	
	printf("\nEspecifique el cargo:");
	scanf("%s",&suc[c].per[d].descripcion);
		sw=validarcedula(suc[c].per[d].descripcion);
		if(sw==1){
			do{
				printf("el dato esta mal ingresado por favor vuelva a ingresar\n");	
				scanf("%s",&suc[c].per[d].descripcion);
				sw=validarcedula(suc[c].per[d].descripcion);
			}while(sw==1);
		}
	printf("\n");
}

int validanombre(char nombre[50]){
	
	int i=0,sw=0,j=0;
	
	j=strlen(nombre);
	
	while(i<j && sw==0){
		if(isalpha(nombre[i])!=0){
			i++;	
		}else{
			sw=1;	
		}	
	}
	return sw;	
}

int validarcedula( char cedula[50]){
	
	int i=0,sw=0,j=0;
	
	j=strlen(cedula);
	
	while(i<j && sw==0){
		if(isdigit(cedula[i])!=0){
			i++;	
		}else{
			sw=1;	
		}	
	}	
	return sw;
}


