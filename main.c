#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>


#define FILES 3
#define COLUMNES 3

void menu(void);
void inicialitzaMatriu(int graella[FILES][COLUMNES]);
void imprimeix(int graella[FILES][COLUMNES]);
int estaPlena(int graella[FILES][COLUMNES],int y, int x);
void introdueix(int graella[FILES][COLUMNES], int y, int x, int jugador);
int comprovaGuanyat(int graella[FILES][COLUMNES], int jugador);
void cambia(int *jugador);
void transformador(int posicio,int*x,int*y);
int taules(int graella[FILES][COLUMNES]);

int main(int argc, char *argv[])
{
    int matriu [FILES][COLUMNES];
	int condicio1=1, condicio2=1, condicio3=1;
	int joc1=1, joc2=1, joct=1; //joct (joc total) ser� un bucle para que cuente los ciclos de juego
	int x, y; //esto ser�n coordenadas
	int posicio;
	int estaple; //est� ple, nada que ver con staples (grapas)
	int jugador=2,guanya=0, empat=0;
	char mode,altre;

	inicialitzaMatriu(matriu);
	menu();
	imprimeix(matriu);

	while (condicio1==1){
		printf("\nModo de juego:\nC: coordenadas \n\tEjemplo: Fila 1-3, Columna 1-3\nV: valores de casilla\n\tEjemplo: Casilla 1-9\n0: cerrar el juego\n");
		scanf(" %c",&mode); //se coloca el espacio para prevenir un error que ha surgido (poniendo un enter y salt�ndose todo el c�digo: evitas que se tome el enter como car�cter)

		switch(mode){
			case 'c':
			case 'C':
				printf("Entendido. Se jugara con coordenadas.\n");
				condicio1=0;
				_clrscr();
				menu();
				imprimeix(matriu);
			break;
			case 'v':
			case 'V':
				printf("Entendido. Se jugara con valores.\n");
				condicio1=0;
				_clrscr();
				menu();
				imprimeix(matriu);
			break;

			case '0':
				printf("Hasta la proxima.\n");
				condicio1=0;
				joct=0;
				return 0;
			
			default:
				printf("Creo que no has entendido como va eso de los modos...\n");
				system("pause");
				_clrscr();
				menu();
				imprimeix(matriu);
		}
	}

	joct=1;

	do{
		cambia(&jugador);
		_clrscr();
		menu();
		imprimeix(matriu);

		printf("Turno del jugador %d.\n",jugador);
	
		joc1=1;
		joc2=1;

		do{
			condicio1=1;
			condicio2=1;
			condicio3=1;

			if(mode=='c'||mode=='C'){ //juego con coordenadas

				while(condicio1==1){
					printf("Selecciona la fila donde colocar tu ficha: ");
					scanf(" %d",&y);
						
						if(y==0){ //literalmente creammos un atajo para rage quit :)
							_clrscr();
							menu();
							imprimeix(matriu);
							printf("Se acabo.\n");
							condicio1=0;
							condicio2=0;
							joc1=0;
							return 0;
						}

						else if(y<1||y>3){
	             		   printf("Fila no reconocida: fuera de parametros.\n");
	                	   system("pause");
	                 	  _clrscr();
	                  	 menu();
	                  	 imprimeix(matriu);
	               		}

						else if(y>=1||y<=3){
							printf("Fila guardada.\n");
							condicio1=0;
						}

						else{
							printf("Entrada desconocida.\n");		
						}

				}

				while (condicio2==1){
					printf("Selecciona la columna donde colocar tu ficha: ");
					scanf(" %d",&x);
					
						if(x==0){
							_clrscr();
							menu();
							imprimeix(matriu);
							printf("Se acabo.\n",133);
							condicio2=0;
							joc1=0;
						}
					else if(x<1||x>3){
						printf("Columna no reconocida: fuera de parametros.\n",133,133);
						system("pause");
						_clrscr();
						menu();
						imprimeix(matriu);
					}
					else if(x>=1||x<=3){
						printf("Fila guardada.\n");
						condicio2=0;
						_clrscr();
						menu();
						printf("\nCoordenadas de la ficha: %d , %d\n",y,x);
					}
					else{
						printf("Entrada desconocida.\n");
					}
				}
				x=x-1;
				y=y-1;
			}

			else{

				while(condicio3==1){

					printf("Selecciona la posicion de la ficha:");
						scanf(" %d",&posicio);

					if(posicio==0){
						_clrscr();
						menu();
						imprimeix(matriu);
						printf("Hasta luego.\n");
						condicio3=0;
						joc1=0;
					}

					else if(posicio<1||posicio>9){
						printf("Error: posicion desconocida.\n");
						system("pause");
						_clrscr();
						menu();
						imprimeix(matriu);

					}

					else if(posicio>=1||posicio<=9){
						printf("Valor registrado.");
						system("pause");
						_clrscr();
						transformador(posicio,&x,&y);
						menu();
						imprimeix(matriu);				
						condicio3=0;
					}

					else{
						printf("Entrada desconocida.\n");
					}	
				}
			}

			estaple=estaPlena(matriu,y,x);
			
			if(estaple==1){
				printf("Error: posicion llena.\n");
				system("pause");
				_clrscr();
				menu();
				imprimeix(matriu);

			}
			else{
				printf("Ficha colocada.\n");
				system("pause");
				joc1=0;
			}
		}while (joc1==1);

		introdueix(matriu,y,x,jugador);
		imprimeix(matriu);

		guanya = comprovaGuanyat(matriu,jugador);
		empat = taules(matriu);

		if(guanya==1){
			printf("El jugador %d ha ganado.\n",jugador);
		
			printf("Otra partida? (S: si/N:no)\n");
			scanf(" %c",&altre);

				switch(altre){
					case 's':
					case 'S':
						inicialitzaMatriu(matriu);
						jugador=2;					
						_clrscr();
						guanya=0;
					break;

					case 'n':
					case 'N':
						printf("Hasta la proxima.\n");
						return 0;

					default:
						printf("Te has equivocado de tecla, prueba de nuevo:\n");
						scanf(" %c",&altre);
				}
		}
		
		else if (empat==1){
			printf("Ha habido un empate.\n");
		
			printf("Otra partida? (S: si/N:no)\n");
			scanf(" %c",&altre);

				switch(altre){
					case 's':
					case 'S':
						inicialitzaMatriu(matriu);
						jugador=2;					
						_clrscr();
						guanya=0;
					break;

					case 'n':
					case 'N':
						printf("Hasta la proxima.\n");
						return 0;

					default:
						printf("Te has equivocado de tecla, prueba de nuevo:\n");
						scanf(" %c",&altre);
				}
		}

		else{
			printf ("De momento no hay ganador\n");
		}

		system("pause");

	}while(guanya!=1);


}




	
