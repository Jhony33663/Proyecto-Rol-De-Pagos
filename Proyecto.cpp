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


int main(){
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
	int i=0,op = 0,salida = 0,edad = 0,numero_doc = 0;	
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
		clave[i] = '\0';//marca el final de la cadena.	
		break;	
		}else if(caracter == 8){
			if(i>0){
			i--;
			printf("\b \b");//para borrar los caracteres.				
			}
			
		}else{
		printf("*");
		clave[i] = caracter; //se guarda caracteres en clave posicion i.
		i++;		
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
			printf("\n\t\t\t----------------");
			printf("\n\t\t\t Ingrese Nombre\n");
			scanf("%s",&nombre);
			printf("\n\t\t\t Ingrese apellido\n");
			scanf("%s",&apellido);
			printf("\t\t\t----------------\n");	
			printf("\n\t\t\t Ingrese Dni\n");
			scanf("%s",&dni);
			printf("\t\t\t----------------\n");	
			printf("\n\t\t\t Ingrese edad\n");
			scanf("%s",&edad);
			printf("\t\t\t----------------\n");					
			system("cls");				
			break;
			case 2:
			system("cls");		
			printf("\n\t\t\t----------------");
			printf("\n\t\t\t Ingrese Nombre\n");
			scanf("%s",&nombre);
			printf("\n\t\t\t Ingrese apellido\n");
			scanf("%s",&apellido);
			printf("\t\t\t----------------\n");	
			printf("\n\t\t\t Ingrese Dni\n");
			scanf("%s",&dni);
			printf("\t\t\t----------------\n");	
			printf("\n\t\t\t Ingrese edad\n");
			scanf("%s",&edad);
			printf("\t\t\t----------------\n");					
			system("cls");				
			break;			
			case 3:
			system("cls");		
			printf("\n\t\t\t----------------");
			printf("\n\t\t\t Ingrese Nombre\n");
			scanf("%s",&nombre);
			printf("\n\t\t\t Ingrese apellido\n");
			scanf("%s",&apellido);
			printf("\t\t\t----------------\n");	
			printf("\n\t\t\t Ingrese Dni\n");
			scanf("%s",&dni);
			printf("\t\t\t----------------\n");	
			printf("\n\t\t\t Ingrese edad\n");
			scanf("%s",&edad);
			printf("\t\t\t----------------\n");					
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
			printf("\n\t\t\t\t\t\t Ingrese Cedula\n:");				
			scanf("%s",&dni);
		printf("\n\t\t=======================================================================================");  
		printf("\n\t\t\tROL INDIVIDUAL:\n");												
		if(dni == 0 /*se encuentra en el espacio o vector*/){
			printf("\n\t\t\t [SUELDO %d]\n\n");
		}else{
			printf("\n\t\t\t NO EXISISTEN REGISTROS.\n");
		}
		printf("\n\t\t=======================================================================================\n");		
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
