#include<stdio.h>
#include<string.h> //gets,strcmp
#include<conio.h>//getch
#include<stdlib.h>
#include<math.h>
#include<locale.h>//CARACTERES ESPECIALES
#define USUARIO "admin"
#define CLAVE "password"
#define LONGITUD 80
#define set locale 
#define CANTIDAD 5
#define COLUMNAS 5
#define LARG 20

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
	
	if(ingresa == 1){
		printf("\n\t\t\t======================================================================");		
		printf("\n\t\t\t\t\tBienvenido Al Sistema De Rol De Pagos\t\t\n");
		printf("\t\t\t======================================================================\n");
		//ingrese codigo aqui
		do{//gerente y sub gerente, administrativo y personal base
			printf("\t------------------------------------------------------------------------------------------------------\n");			
			printf("\n\t\t\t [Escoja un valor]\n\n");
			printf("\n\t\t\t\t 1.Gerencia y Subgerencia\n");
			printf("\n\t\t\t\t 2.Personal Administrativo\n");
			printf("\n\t\t\t\t 3.Personal Base\n");
			printf("\n\t\t\t\t 4.Datos Rol de Pagos\n");
			printf("\n\t\t\t\t 5.Rol Individual\n");
			printf("\n\t\t\t\t 6.Rol general\n");
			printf("\n\t\t\t\t 7.SALIR.\n");			
						
							
			printf("\n\t------------------------------------------------------------------------------------------------------\n");	
			printf("\nopcion:");			
			scanf("%d",&salida);
			switch(salida){
			if(salida == 7){
				break;
			}
			case 1:
			system("cls");		
			typedef enum{
			Nombreg, //columna 0
			Cantidadg, //columna 1
			preciog, //columna2
			Codigog //columna 3
			}columnas_g;

			unsigned char datosg[2][CANTIDAD][COLUMNAS][LARG],i3;
			columnas_g columnasg;
	
			printf("Bienvenido Ingrese los productos\n\r");
			for(i3=0;i3<CANTIDAD;i3++){
				for(columnasg = 0; columnasg < COLUMNAS; columnasg++){
					switch(columnasg){
						case Nombreg:
							printf("\n\t\t\tIngrese el Nombre:");
							break;
						case Cantidadg:
							printf("\n\t\t\tIngrese la cantidad del producto:"); //
							break;
						case preciog:
							printf("\n\t\t\tIngrese el precio del producto: ");
							break;
						case Codigog:
							printf("\n\t\t\tIngrese el codigo del producto: ");	
							break;
					}		
					scanf("%s",&datosg[i3][columnasg]);
				}
			}					
			system("cls");				
			break;
			case 2:
			system("cls");		
			typedef enum{
			Nombrep, //columna 0
			Cantidadp, //columna 1
			preciop, //columna2
			Codigop //columna 3
			}columnas_p;

			unsigned char datosp[2][CANTIDAD][COLUMNAS][LARG],i1;
			columnas_p columnasp;
	
			printf("Bienvenido Ingrese los productos\n\r");
			for(i1=0;i1<CANTIDAD;i1++){
				for(columnasp = 0; columnasp < COLUMNAS; columnasp++){
					switch(columnasp){
						case Nombrep:
							printf("\n\t\t\tIngrese el Nombre:");
							break;
						case Cantidadp:
							printf("\n\t\t\tIngrese la cantidad del producto:"); //
							break;
						case preciop:
							printf("\n\t\t\tIngrese el precio del producto: ");
							break;
						case Codigop:
							printf("\n\t\t\tIngrese el codigo del producto: ");	
							break;
					}		
					scanf("%s",&datosp[i1][columnasp]);
				}
			}					
			system("cls");				
			break;			
			case 3:
			system("cls");		
			typedef enum{
			Nombrepb, //columna 0
			Cantidadpb, //columna 1
			preciopb, //columna2
			Codigopb //columna 3
			}columnas_pb;

			unsigned char datospb[3][CANTIDAD][COLUMNAS][LARG],i4;
			columnas_pb columnaspb;
	
			printf("Bienvenido Ingrese los productos\n\r");
			for(i4=0;i4<CANTIDAD;i4++){
				for(columnaspb = 0; columnaspb < COLUMNAS; columnaspb++){
					switch(columnaspb){
						case Nombrepb:
							printf("\n\t\t\tIngrese el Nombre:");
							break;
						case Cantidadpb:
							printf("\n\t\t\tIngrese la cantidad del producto:"); //
							break;
						case preciopb:
							printf("\n\t\t\tIngrese el precio del producto: ");
							break;
						case Codigopb:
							printf("\n\t\t\tIngrese el codigo del producto: ");	
							break;
					}		
					scanf("%s",&datospb[3][i4][columnaspb]);
				}
			}					
			system("cls");				
			break;	
			case 4:
			system("cls");		
			printf("\n\t\t\t----------------");
			printf("\n\t\t\t Ingrese Nombre de la empresa\n");
			scanf("%s",&nombre_E);	
			printf("\n\t\t\t----------------");
			printf("\n\t\t\t Ingrese Cedula\n");				
			scanf("%s",&dni);	
			printf("\n\t\t\t----------------");			
			printf("\n\t\t\t Numero de platos\n");
			scanf("%d",&numero_doc);								
			system("cls");				
			break;	
			case 5:
			system("cls");		
			printf("\n\t\t\t\t\t\t ----------------");
			
			printf("\n\t\t\t\t\t\t\t Escoja un Número\n:");
			printf("\n\t\t\t\t\t\t\t 1.Gerencia y Subgerencia\n");
			printf("\n\t\t\t\t\t\t\t 2.Personal Administrativo\n");	
			printf("\n\t\t\t\t\t\t\t 3.Personal Base\n");									
			scanf("%d",&op2);
			if(op2 == 1){
			printf("\n\t\t=======================================================================================\n");  
			//imprime matriz
			printf("\n\rNombre\t\tCantidad\tPrecio\t      Codigo");
			for(i3=0;i3<CANTIDAD;i3++){
				printf("\n\r");
				for(columnasg = 0;columnasg < COLUMNAS; columnasg++){
					printf("%s\t\t",datosg[i3][columnasg]);
				}
			}
			printf("\n\t\t=======================================================================================\n");			
			}else if(op2 == 2){
			printf("\n\t\t=======================================================================================\n");  
			//imprime matriz
			printf("\n\rNombre\t\tCantidad\tPrecio\t      Codigo");
			for(i1=0;i1<CANTIDAD;i1++){
				printf("\n\r");
				for(columnasp = 0;columnasp < COLUMNAS; columnasp++){
					printf("%s\t\t",datosp[i1][columnasp]);
				}
			}
			printf("\n\t\t=======================================================================================\n");				
			}else if(op2 == 3){
			printf("\n\t\t=======================================================================================\n");  
			//imprime matriz
			printf("\n\rNombre\t\tCantidad\tPrecio\t      Codigo");
			for(i4=0;i4<CANTIDAD;i4++){
				printf("\n\r");
				for(columnasg = 0;columnasg < COLUMNAS; columnasg++){
					printf("%s\t\t",datospb[i4][columnaspb]);
				}
			}
			printf("\n\t\t=======================================================================================\n");				
			}
			system("pause");
			system("cls");				
			break;	
			case 6:
			system("cls");	
    	int cont,c,f;
    	float sumafila,promedio;
    	int m[3][4]={{10,8,8,7},{9,7,5,10},{10,9,6,8}};
    	//se define la estructura e impresion de la matriz.
		printf("\n\t\t\t=======================================================================================");  
		printf("\n\t\t\tROL GENERAL:\n");
    	//se crea un bucle con contador para definir la estructura [].
    	for(cont=0;cont<=3;cont++){
        printf("                [%d]",cont);
    	}
    	//dentro este for se hace la matriz 3*4 e imprime en orden.
    	for(f=0;f<3;f++){//se aprovecha este if como contador para los estudiantes y definir las columnas.
    	printf("\nPERSONAL[%d]",f);
    	for(c=0;c<4;c++){//este if se encarga de las filas y muestra el resultado en pantalla.
    	printf("\t%d\t",m[f][c]);//se concatenan los valores dentro la matriz m.
   	 	}
    	printf("\n");//se da el salto de linea para dar forma a la matriz
    	}
    	printf("\nCalificaci%cn m%cs baja:5\n",162,160);
    	printf("Calificaci%cn m%cs alta:10\n",162,160);
    	//se realiza la operacion suma con los valores declarados.
    	for(f=0;f<3;f++){
        sumafila = 0;
        for(c=0;c<4;c++){
            sumafila=sumafila+m[f][c];
        }
    	}
    	//se realiza las operaciones para averiguar el promedio mediante los valores declarados.
    	for(f=0;f<3;f++){
        sumafila = 0;
        for(c=0;c<4;c++){
            sumafila=sumafila+m[f][c];
            promedio=sumafila/4;
        }
        printf("\nel promedio del estudiante [%d] es: %.2f\n",f,promedio);
    	}
		printf("\n\t\t\t=======================================================================================");  
		system ("pause");
		system("cls");   	
			break;											
		}
					
		}while(salida != 7);
		}else{
		printf("\n\t HA SOBREPASADO EL NUMERO MAXIMO DE INTENTOS PERMITIDOS\n");
		}	
	return 0;
}
