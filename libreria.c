#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>



#define FILES 3
#define COLUMNES 3

void inicialitzaMatriu(int graella[FILES][COLUMNES]){

	int i, j;
		for(i=0;i<FILES;i++)
			for(j=0;j<COLUMNES;j++)	
				graella[i][j]=0;
}
void menu(void){
int i;
//--------------------------MENU-------------------------------
	{
	_textcolor(13);
	printf("%c",218);

	for(i=0;i<48;i++)
		printf("%c",196);

	printf("%c\n",191);

	_textcolor (11);
	printf("\n   UAB  -  Fonaments d'Informactica 2022-2023   \n");
	printf("       3 en raya    -     por Aimara              \n");

	_textcolor(13);
	printf("%c",192);

	for(i=0;i<48;i++)
		printf("%c",196);
	
	printf("%c\n",217);
	_textcolor (7);
	}
//-------------------------SEPARADOR----------------------------
	{
	for(i=0;i<50;i++)
		printf("%c",196);
	printf("\n");
	}
}
void imprimeix(int graella[FILES][COLUMNES]){
	int i, j;
	for(i=0;i<FILES;i++){
		printf("\t---------------\n\t");
		for(j=0;j<COLUMNES;j++){	
			
			if(graella[i][j]==1)
				{
				printf("|");
				_textcolor(4);
				printf(" %c ", 155);
				_textcolor(7);
			}

			if(graella[i][j]==2){
				printf ("|");
				_textcolor(3);
				printf(" %c ", 111);
				_textcolor(7);
			}

			if(graella[i][j]==0){
				printf("|");
				printf(" %d ",graella[i][j]);
			}
			printf("|");
		}
		printf("\n");
	}	
	printf("\t---------------\n");
}
void transformador(int posicio,int*x,int*y){
int valor;
	valor=posicio-1;
	*x=valor%3;
	*y=valor/3;
}
int estaPlena(int graella[FILES][COLUMNES],int y, int x){

	if(graella[y][x]==1||graella[y][x]==2){
		
		return 1;

	}
	else{

		return 0;
	}
}
void cambia(int *torn){
	if(*torn==2)
		*torn=1;
	else
		*torn=2;
}
void introdueix(int graella[FILES][COLUMNES], int y, int x, int jugador){

	if(jugador==1){

		graella[y][x]=1;
	}
	else{
		graella[y][x]=2;
	}
}
int comprovaGuanyat(int graella[3][3], int jugador)
{
	int contador= 0;
	
	
	for(int i=0; i<3; i++)						//Contador Filas
	{
		for(int j=0; j<3;j++)
		{
			if (graella[i][j]==jugador)
			{
				contador ++;
			}
				
		}
			if (contador==3)
			{
				
				return 1;
			}
		contador=0;
	}
	for(int j=0; j<3; j++)  					//Contador Columnas
	{
		for(int i=0; i<3; i++)
		{
			if (graella[i][j]==jugador)
			{
				contador ++;
			}	
		}
			if (contador==3)
			{
				
				return 1;
			}
		contador=0;
	}

	for(int i=0; i<3; i++)					   //Contador diagonal 1
	{
		if(graella[i][i]==jugador)
		{
			contador ++;
		}
		if (contador==3)
		{	
			
			return 1;
		}

	}
	contador = 0;
		for(int i=0; i<3; i++)				//Contador diagonal 2 
		{
			if (graella[i][2-i]==jugador)
			{
				contador ++;
			}	
		}
			if (contador==3)
			{
				
				return 1;
			}
return 0;
		
		
}
int taules(int graella[FILES][COLUMNES])
{
	int posiciones=0;
			for(int i=0; i<3; i++)
				{
					for(int j=0; j<3; j++)
					{
						if(graella[i][j]==1 || graella[i][j]==2)
						{
							posiciones+=1;
						}
					}
				}
	if(posiciones==9)
		{
			return 1;
		}	
	return 0;
}	
