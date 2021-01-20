#include<stdio.h>
#include<string.h> //gets,strcmp
#include<conio.h>//getch
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<locale.h>//CARACTERES ESPECIALES

//Valores Definidos Ingreso Usuario
#define USUARIO "admin"
#define CLAVE "password"
#define LONGITUD 80
#define set locale 
#define CANTIDAD 5
#define COLUMNAS 5
#define LARG 20

//DECLARAMOS LAS ESTRUCTURAS

//Datos Preestablecidos Para La Empresa
struct empresa{
	char nombre[30]="EL POLLO PROGRAMERO  SA"; // Declaramos los nombres
	char RUC[10]="001465579";
	char telef[11]="0995327865";
	int zona;
}empresa;

//Datos guardan variables contables
struct rol{
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
	float valor_h;
};

//Datos personales del trabajador
struct persona{
	char nombre[20];
	char apellido[20];
	char cedula[20];
	char descripcion[30];
	int sueldo;
	int horase;
	struct rol r;
	
};

//Datos de las diferentes sucursales
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
void consulta_individual();
int validarcedula(char cedula[50]);
int validanombre(char nombre[50]);
void ingresos(int c,int d);
void egresos(int c,int d);
void general(int v[10]);
int main(int argc, char *argv[]) {
////////////////////////////////////////////////////////////////////////////////// Login	
	system("color a");
	setlocale(LC_ALL,"spanish");//LOCALE LIBRERIA EN ESPAÑOL
	setlocale(LC_ALL,"spanish");//LOCALE LIBRERIA EN ESPAÑOL
	char usuario[LONGITUD + 1]; //cadena de longitud 80 + 1
	char clave[LONGITUD + 1];
	int intento = 0;
	int ingresa = 0;
	char caracter;
	char nombre[LONGITUD + 1];
	char dni[LONGITUD - 70];
	char nombre_E[LONGITUD + 1];	
	int i2=0,op = 0,salida = 0,edad = 0,numero_doc = 0,op2=0;	

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
         exit (-1); 
	}
	
	
	int opc_P=0,opc1=1,cant=0;
	int vec_can[10];
	
	
////////////////////////////////////////////////////////////       Menu     //////////////////////////////////////////////////////////////////	
	do{
		opc1=1;
		// El ciclo se repite hasta que se de una opcion valida
		do{
			menu_principal(&opc_P);// 4 opciones del menu  
		}while(opc_P<0 || opc_P>4);
		
		//OPCION NUMERO 1
		if(opc_P==1){
			
			ingreso_sucursal(&cant,vec_can);                        // ingreso de sucursales 
			for(int j=0;j<vec_can[empresa.zona-1];j++){		// El vec_can nos ayuda a controlar el numero de trabajadores
				ingreso_datos(empresa.zona-1,j);                // Ingreso De Todos Los Datos    
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
		}else if(opc_P==3){
			while(opc1==1){
				general(vec_can);
				printf("Desea Realizar Otra Consulta?\n");
				printf("1.SI\t2.NO\n");
				do{
					scanf("%d",&opc1);
				}while(opc1<0 || opc1>2);
			}
		}
	}while(opc_P!=4);
      system("cls");
	printf("\n\t\t\t======================================================================");		
	printf("\n\t\t\t\t\t GRACIAS POR USAR NUESTRO PROGRAMA \t\t\n");
	printf("\n\t\t\t\t\t\t GRUPO EXONERADO XD  \t\t\n");
	printf("\t\t\t======================================================================\n");
}
void menu_principal(int *ptr){  // Funcion Menu Principal
		system("cls");
	// Impresion en pantalla del menu principal
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
	scanf("%d",&*ptr); // Lectura de la opcion

	
}
void ingreso_sucursal(int *ptr, int v[10]){  // Definimos la sucursal y los trabajadores en ella
	
	int aux=0, sw=0;
	system("cls");
	printf("Ingrese zona de la sucursal:\n");
	printf("1. SUR\n");
	printf("2. NORTE\nopcion:");
	//Con el do verficamos que los valores que se ingresan son correctos
	do{
		scanf("%d",&empresa.zona);
		if(empresa.zona<0 || empresa.zona>2){
			printf("Opcion no valida\n");//caso de no ser valido saldra un mensaje de error
		}
	}while(empresa.zona<0 || empresa.zona>2);
	system("cls");
	
	printf("___ EL POLLO PROGRAMERO  ");
	if(empresa.zona==1){
		printf("SUR__\n\n");
		aux=0;
	}else{
		printf("NORTE__\n\n");
		aux=1;
	}
		
		printf("Ingrese el numero de trabajadores: ");
		scanf("%d",&*ptr); 	// con la direccion de memoria guardamos valores en el vector
		v[aux]=*ptr;		// de esta manera podemos definir cuantos trabajadores ingresan en cada sucursal
		system("cls");
}
void ingreso_datos(int c,int d){
	
	datos_personales(c,d);
	ingreso_cargo(c,d);
	ingresos(c,d);
	egresos(c,d);
	system("cls");
}
void consulta_individual(){
	
	int aux=0,aux1=0;
	system("cls");
	printf("\nSucursal que desea consultar\n");
	printf("1. SUR\n");
	printf("2. NORTE\n");
	do{
		scanf("%d",&aux);
		if(aux<0 || aux>2){
			printf("Opcion no valida\n");
		}
	}while(aux<0 || aux>2);
	
	aux=aux-1;
	
	printf("Numero de trabajador: ");
	do{
		scanf("%d",&aux1);
		if(aux1<0 || aux1>4){
			printf("Opcion no valida\n");
		}
	}while(aux1<0);
	aux1=aux1-1;
		system("cls");
	fflush(stdin);
	                      
	printf("\n\t\t\t======================================================================");		
	printf("\n\t\t\t\t\t ROL DE PAGOS INDIVIDUAL\t\t\n");
	printf("\t\t\t======================================================================\n");	
	printf("Cédula: %s\n",suc[aux].per[aux1].cedula);	
    printf("\nNombre: %s\t",suc[aux].per[aux1].nombre);
	printf("Apellido: %s\n",suc[aux].per[aux1].apellido);
	printf("\n\t\t\tEl sueldo de la persona es: %d\n\n",suc[aux].per[aux1].sueldo);
	printf("\n\t\t\tTotal Horas Extra: %d\n",suc[aux].per[aux1].horase);
	printf("\n\n\t\t\tValor Aporte personal: %.2f\n",suc[aux].per[aux1].r.aportepersonal);                         
    printf("\n\n\t\t\tEl efectivo destinado a fondos de reserva : %.2f\n\n",suc[aux].per[aux1].r.fondoreserva);
  	printf("\n\t\t\tEl total de  ingresos de efectivo : %.2f\n\n",suc[aux].per[aux1].r.totalingreso);
    printf("\n\t\t\tEl total de deduccion es : %.2f\n\n",suc[aux].per[aux1].r.totaldeduccion);
	printf("\n\t\t\tEl sueldo liquido es : %.2f\n\n",suc[aux].per[aux1].r.liquido);
		system("pause");
	system("cls");
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
	
}
void ingresos(int c,int d){
	int bon=0,cargo,op;
		printf("\nUsted Ha Laborado Horas Extras?\n1.si\n2.no\nopcion:");
		do{
			scanf("%i",&cargo);
			if(cargo<0 || cargo>2){
				printf("Opcion no valida\n");
			}
		}while(cargo<0 || cargo>2);
		
		if(cargo == 1){
			printf("\nElija un valor:\n1.25 porciento\n2.50 porciento\nopcion:");
			do{
				scanf("%d",&op);
				if(op<0 || op>2){
					printf("Opcion no valida\n");
				}
			}while(op<0 || op>2);
			if(op == 1){
			printf("\nIngrese el numero de horas Laboradas\n");
			scanf("%d",&suc[c].per[d].horase);
			suc[c].per[d].r.extras = ((suc[c].per[d].horase)*(suc[c].per[d].r.valor_h*1.25));
			}else if(op == 2){
			printf("\nIngrese el numero de horas Laboradas \n");
			scanf("%d",&suc[c].per[d].horase);
			suc[c].per[d].r.extras = ((suc[c].per[d].horase)*(suc[c].per[d].r.valor_h*1.50));
			}	
		}else{
			printf("\n");
		}
		//DIGITAMOS COMISIONES
		fflush(stdin);
		printf("\nUsted Posee Bonos u Comisiones?\n1.si\n2.no\nopcion: \n");
		do{
				scanf("%d",&bon);
				if(bon<0 || bon>2){
					printf("Opcion no valida\n");
				}
			}while(bon<0 || bon>2);
		if(bon == 1){
			printf("\nIngrese el monto\n ");
			scanf("%f",&suc[c].per[d].r.bono);
		}else{
			printf("\n");
			suc[c].per[d].r.bono=0;
		}
		suc[c].per[d].r.totalingreso =suc[c].per[d].sueldo+suc[c].per[d].r.extras+suc[c].per[d].r.bono;
		
}	
void egresos(int c,int d){	
printf("\n=============Ingreso de Egresos============ \n");
suc[c].per[d].r.aportepersonal=suc[c].per[d].sueldo*0.0935;
printf("\nIngrese el total de prestamos solicitados: \n");
scanf("%f",&suc[c].per[d].r.prestamoquirografario);
printf("\nIngrese el total de anticipos solicitados: \n");
scanf("%f",&suc[c].per[d].r.anticiposueldo);
printf("\nIngrese el total de  multas acumuladas: \n");
scanf("%f",&suc[c].per[d].r.multas);
suc[c].per[d].r.totaldeduccion=(suc[c].per[d].r.aportepersonal+suc[c].per[d].r.prestamoquirografario+suc[c].per[d].r.anticiposueldo+suc[c].per[d].r.multas);
suc[c].per[d].r.fondoreserva=suc[c].per[d].r.totalingreso*0.0833;
suc[c].per[d].r.liquido=suc[c].per[d].r.totalingreso-(suc[c].per[d].r.totaldeduccion); 	
}
void ingreso_cargo(int c,int d){
	
	int opc=0,sw=0;
	
	printf("\n.:Ingrese el tipo de cargo del trabajador:.\n");
	printf("1.Administrativo\n");
	printf("2.Operativo\n");
	printf("3.Base\n");
	do{
		scanf("%d",&opc);
		if(opc<0 || opc>3){
			printf("Opcion no valida\n");
		}
	}while(opc<0 || opc>2);
	
	
	switch(opc){
		
		case 1:
			suc[c].per[d].sueldo = 800;
			suc[c].per[d].r.valor_h=3.33;
			break;
			
		case 2:
			suc[c].per[d].sueldo = 600;
			suc[c].per[d].r.valor_h=2.50;
			break;
			
			
		case 3:
			suc[c].per[d].sueldo = 400;
			suc[c].per[d].r.valor_h=1.66;
			break;	
	}
	
	printf("\nDetalle su cargo:");
	scanf("%s",&suc[c].per[d].descripcion);
		sw=validanombre(suc[c].per[d].descripcion);
		if(sw==1){
			do{
				printf("El dato esta mal ingresado por favor vuelva a ingresar\n");	
				scanf("%s",&suc[c].per[d].descripcion);
				sw=validanombre(suc[c].per[d].descripcion);
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
void general(int v[10]){
	
	int aux=0;
	system("cls");
	printf("\nSucursal que desea consultar\n");
	printf("1. SUR\n");
	printf("2. NORTE\n");
	do{
		scanf("%d",&aux);
		if(aux<0 || aux>3){
			printf("Opcion no valida\n");
		}
	}while(aux<0 || aux>2);
	system("cls");
	aux=aux-1;
	printf("\n\t\t\t======================================================================");		
	printf("\n\t\t\t\t\t ROL DE PAGOS GENERAL \t\t\n");
	printf("\t\t\t======================================================================\n");
	printf("\n\t\t\t\t\t%s\n\n",empresa.nombre);
	printf("RUC: %s\tTELEFONO: %s\n",empresa.RUC,empresa.telef);
	printf("SUCURSAL: ");
	if(aux==0){
		printf("SUR\t");
		printf("DIRECCION: QUITUMBE\n\n");
	}else{
		printf("NORTE\t");
		printf("DIRECCION: CONDADO\n\n");
	}
	printf("Empleado\t\tCargo\t\t\tTotal Ingreso\t\tTotal Egreso\t\tSueldo o Liquido\n");
	for(int i=0;i<v[aux];i++){
		
		printf("%s %s\t\t",suc[aux].per[i].nombre,suc[aux].per[i].apellido);
		printf("%s\t\t",suc[aux].per[i].descripcion);
		printf("\t%.2f\t\t\t",suc[aux].per[i].r.totalingreso);
		printf("%.2f\t",suc[aux].per[i].r.totaldeduccion);
		printf("\t\t%.2f\n\n",suc[aux].per[i].r.liquido);
		
	}
	system("pause");
	system("cls");
}
