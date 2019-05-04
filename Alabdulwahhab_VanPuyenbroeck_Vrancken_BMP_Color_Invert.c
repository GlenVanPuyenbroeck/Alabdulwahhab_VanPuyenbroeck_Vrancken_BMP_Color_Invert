//bronvermeldingen: 
/*http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm
/*https://gitlab.com/cp2_arduino_8x8ledmatrix/cp2_bmp_edit
/*https://stackoverflow.com/questions/31608867/about-bmp-file-how-can-i-write-change-a-pixel-color-in-c
*/

#include <stdio.h>
#include <stdlib.h>
#define LENGTE  270054 


int main(void)
{
	FILE *pointer = fopen("watamote.bmp","rb");
	FILE *invers = fopen("invers.bmp","wb");

	char a = 0;
	
	char R = 0;
	char B = 0;
	char G = 0 ; 
	
	 if(pointer == NULL)
    {
        /* Unable to open file hence exit */
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }


    /* File open success message */
    printf("File opened successfully. Reading file contents character by character. \n\n");

    for (int i = 0; i < 54; i++)
	{
        /* Read single character from file */
        a = fgetc(pointer);

        /* Print character read on console */
        fputc(a,invers);
		
		
		
		
    } 
	
	for(int i = 54 ; i < LENGTE; i++)
	{
		
		R= ~R;
		B= ~B;
		G= ~G;
		
		 R = fgetc(pointer);
		 B = getc(pointer);
		 G = getc(pointer);

        /* Print character read on console */
		
        fputc(R,invers);
		fputc(B,invers);
		fputc(G,invers);
	}
    fclose(pointer);

	
    return 0;
}

	
	

