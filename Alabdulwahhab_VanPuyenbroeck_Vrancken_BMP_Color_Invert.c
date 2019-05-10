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
*/

#include <stdio.h>
#include <stdlib.h>

void Data(FILE*,FILE*,int*,int*);  				// Deze functie koppieërd de header naar de nieuwe file.
void InversData(FILE*,FILE*,int); 				// Deze functie inverteerd de kleuren.
void GrooteAfbeelding(FILE*,FILE*,int*,int*); 			// Deze functie berekend de oppervlakte van de BMP file.

int main(void)
{             
                int teller=0;
                int lengte = 0;
                int *d = NULL;
                int *e = NULL;
               
                FILE *pointer = fopen("download.bmp","rb"); 	      // Deze opent de input file.
                FILE *invers = fopen("invers.bmp","wb");              // Zal het geïnverteerde bestand aanmaken met de naam "invers".
 
                int a = 0;
 
                              if(pointer == NULL)   		      // Als de file pointer een null geeft zal de programma stoppen met werken.
                               {
                                     printf("File werd niet geopend.\n");
                                     exit(EXIT_FAILURE);
                               }
 
                                printf("File werd geopend , karakters worden nu ingelezen\n\n");
 
                Data(pointer,invers,d,e);                              // verwijzing naar de functie data
               
    return 0;
}
    printf("File werd geopend , karakters worden nu ingelezen\n\n");

    for (int i = 0; i < 54; i++)
	{
		teller++; 
		
		
		
		d = (int*)malloc(sizeof(BMPHeader));
		
        a = fgetc(pointer); // leest de karakters stukje per stukje
		
		d = &a;
		
        fputc(a,invers); // zet de gelezen karakters in de nieuwe file
		
		*array[i] = d ; 
		
		free(d);
			
    } 
	printf("Breedte pixels is %d\n",*array[19]);
	printf("Hoote pixels is %d\n",*array[23]);


	 for (int i = 54; i < LENGTE; i++)
	{
		
        
        a = fgetc(pointer);
		 
		a = ~a; // karakters worden eerst geinverteerd voordat ze in de file word gezet
		 
        fputc(a,invers);
		
    } 
	
	free(d);
    fclose(pointer);
	fclose(invers);

	
    return 0;
}


