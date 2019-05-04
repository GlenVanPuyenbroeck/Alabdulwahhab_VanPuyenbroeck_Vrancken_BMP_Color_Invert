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
#define LENGTE  270054 


int main(void)
{
	FILE *pointer = fopen("bmpwatamote.bmp","rb");
	FILE *invers = fopen("invers.bmp","wb");

	char a = 0;
	
	 if(pointer == NULL)
    {
        
        printf("File werd niet geopend.\n");
        
        exit(EXIT_FAILURE);
    }


   
    printf("File werd geopend , karakters worden nu ingelezen\n\n");

    for (int i = 0; i < 54; i++)
	{
       
        a = fgetc(pointer); // leest de karakters stukje per stukje

        fputc(a,invers); // zet de gelezen karakters in de nieuwe file
		
    } 
	
	 for (int i = 54; i < LENGTE; i++)
	{
		
        
        a = fgetc(pointer);
		 
	a = ~a; // karakters worden eerst geinverteerd voordat ze in de file word gezet
		 
        fputc(a,invers);
		
    } 
	
	
    fclose(pointer);

	
    return 0;
}

	
	

