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
#pragma pack (1)
typedef struct {    		          // Total: 54 bytes
  unsigned short  	type;             // Magic identifier: 0x4d42
  unsigned int  	size;             // File size in bytes
  unsigned short  	reserved1;        // Not used
  unsigned short  	reserved2;        // Not used
  unsigned int  	offset;           // Offset to image data in bytes from beginning of file (54 bytes)
  unsigned int  	dib_header_size;  // DIB Header size in bytes (40 bytes)
  int 				width_px;         // Width of the image
  int   			height_px;        // Height of image
  unsigned short  	num_planes;       // Number of color planes
  unsigned short  	bits_per_pixel;   // Bits per pixel
  unsigned int  	compression;      // Compression type
  unsigned int  	image_size_bytes; // Image size in bytes
  int   			x_resolution_ppm; // Pixels per meter
  int   			y_resolution_ppm; // Pixels per meter
  unsigned int  	num_colors;       // Number of colors  
  unsigned int  	important_colors; // Important colors 
} BMPHeader;


int main(void)
{	int teller=0;
	int array [54];
	FILE *pointer = fopen("bmpwatamote.bmp","rb");
	FILE *invers = fopen("invers.bmp","wb");

	int a = 0;
	printf("%d\n",sizeof(BMPHeader));
	 if(pointer == NULL)
    {
        
        printf("File werd niet geopend.\n");
        
        exit(EXIT_FAILURE);
    }


   
    printf("File werd geopend , karakters worden nu ingelezen\n\n");

    for (int i = 0; i < 54; i++)
	{
		teller++; 
       
        a = fgetc(pointer); // leest de karakters stukje per stukje
		array[i] = a ;
        fputc(a,invers); // zet de gelezen karakters in de nieuwe file
		printf("teller: %d\narray: %d\n",teller,array[i]);
    } 	
	printf("breedte: %d\nhoogte: %d\n");
	
	 for (int i = 54; i < LENGTE; i++)
	{
		
        
        a = fgetc(pointer);
		 
	a = ~a; // karakters worden eerst geinverteerd voordat ze in de file word gezet
		 
        fputc(a,invers);
		
    } 
	
	
    fclose(pointer);

	
    return 0;
}

	
	

