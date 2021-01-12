#include<stdio.h>
#include<string.h> //gets,strcmp
#include<conio.h>//getch
#include<stdlib.h>
#define USUARIO "admin"
#define CLAVE "password"
#define LONGITUD 80


int main(){
	system("color a");
	char usuario[LONGITUD + 1]; //cadena de longitud 80 + 1
	char clave[LONGITUD + 1];
	int intento = 0;
	int ingresa = 0;
	char caracter;
	int i=0;
	
	do{
	i=0;
	system("cls");	
	printf("\n\t\t\t----------------");
	printf("\n\t\t\t INICIE SESION\n");
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
				
	}else{
		printf("\n\t HA SOBREPASADO EL NUMERO MAXIMO DE INTENTOS PERMITIDOS\n");
	}

	return 0;
}
