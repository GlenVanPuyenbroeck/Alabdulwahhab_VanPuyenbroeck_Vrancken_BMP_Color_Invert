/*
* auteur 1: Alabdulwahhab Ali
* auteur 2: Van Puyenbroeck Glen
* auteur 3: Wesley Vrancken
* Link to github repository: https://github.com/GlenVanPuyenbroeck/Alabdulwahhab_VanPuyenbroeck_Vrancken_BMP_Color_Invert
*
*Bron vermeldingen: 
*http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm
*https://gitlab.com/cp2_arduino_8x8ledmatrix/cp2_bmp_edit
*https://stackoverflow.com/questions/31608867/about-bmp-file-how-can-i-write-change-a-pixel-color-in-c
*https://image.online-convert.com/convert-to-bmp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Data(FILE*,FILE*,int*,int*);  				// Deze functie koppieërd de header naar de nieuwe file.
void InversData(FILE*,FILE*,int); 				// Deze functie inverteerd de kleuren.
void GrooteAfbeelding(FILE*,FILE*,int*,int*); 	// Deze functie berekend de oppervlakte van de BMP file.

int main(void)
{	
	int teller=0;
	int lengte = 0;
	int *d = NULL;
	int *e = NULL;
	
	FILE *pointer = fopen("download.bmp","rb"); // Deze opent de input file. 
	FILE *invers = fopen("invers.bmp","wb"); 	// Zal het geïnverteerde bestand aanmaken met de naam "invers". 

	int a = 0;

			if(pointer == NULL) 	// Als de file pointer een null geeft zal de programma stoppen met werken.
			{
				printf("File werd niet geopend.\n");
				exit(EXIT_FAILURE);
			}

		printf("File werd geopend , karakters worden nu ingelezen\n\n");

	Data(pointer,invers,d,e); 		// verwijzing naar de functie data
	
    return 0;
}


void Data(FILE *bestand,FILE *nieuwebestand, int *y, int *w)
{
	int teller = 0;
	int a = 0;
	int array[54];
	
	int *g = NULL ; 
	int *h = NULL ; 
	
			g = (int*)malloc(sizeof(int)); 			// De pointers hebben nu een plaats gereserveerd in de heap memory.
			h = (int*)malloc(sizeof(int)); 
	
		for (int i = 0; i < 54; i++)
				{
							a = fgetc(bestand); 	// Leest de karakters één per één.
							fputc(a,nieuwebestand); // Zet de gelezen karakters in de nieuwe file.	
								
					teller++; 
					array[i] = a;	
			    }
		printf("De eerste 2 waardes zijn %c en %c \n",array[0],array[1]); 
		if (array[0] != 66 && array[1] != 77) 		// Als de waardes van de arrays niet 66 en 77 zijn is het geen BMP file.
		{
			printf("Type file klopt niet. Einde programma\n");
			exit(EXIT_FAILURE);
		}
		
				else if(array[18] == 44 && array[22] == 44)
				{
				printf("Breedte en lengte is te klein, verander het alstublieft\nEinde programma.\n");
				exit(EXIT_FAILURE);
				}
				
						else
						{
							printf("Het is een BMP file.\n");
						}
				
		g = &array[18]; // De string op plaats 18 en 22 zitten nu in de heap memory.
		h = &array[22]; 
	
	
	GrooteAfbeelding(bestand ,nieuwebestand,g,h);				
	fclose(bestand);
	fclose(nieuwebestand);
	free(g);// Deallocatie geheugen van de pointer.
	free(h);
	
}

void GrooteAfbeelding(FILE*originele,FILE* hallo ,int *c , int *z)
{
	int lengte =0;
	
	printf("Breedte pixels is %d\n",*c);
	printf("Hoogte pixels is %d\n",*z);
	lengte = ((*c)*(*z)*4)+54;
	printf("Oppervlakte afbeelding = %d\n",lengte); // Standaard formule voor het berekenen van de omtrek.
    InversData(originele,hallo,lengte);
}

void InversData(FILE *origineel,FILE* nieuw, int lang)
{
	int a = 0;
	int *d = NULL;
	
					 for (int i = 54; i < lang; i++)
					{
						d = (int*)malloc(sizeof(int));
						
						a = fgetc(origineel);
						
						a = ~a; // Karakters worden eerst geïnverteerd voordat ze in de file gezet wordt.
						d = &a;
						fputc(a,nieuw);
					} 
	free(d);
	
	fclose(origineel);
	fclose(nieuw);
	printf("De afbeelding is met succes aangemaakt. Einde programma\n");
}

/*
*Deze programma veranderd de kleuren van een BMP file;
*@param = FILE *pointer.
*@return = is void.
*/	