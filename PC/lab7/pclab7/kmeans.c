#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int a[1000000000];

void main()
{
	FILE *input,*output;
	int get_char;

	
	input = fopen("lena.bmp", "rb");
	output= fopen("black-white_parallel.bmp", "wb");
	
	int c=0;


	while((get_char=fgetc(input))!= EOF)
	{
		printf("%d\n",get_char);
		a[c]=get_char;

		c++;

	}

	printf("Count:%d\n",c);
	int i;

	fclose(input);
	input = fopen("lena.bmp", "rb");


	#pragma omp parallel private(get_char)
	#pragma omp for ordered 
	for(i=0;i<c;i++)
	{
		get_char=a[i];
		
		if(i<=54)
			;
		else
		{
			if(get_char>128)
				get_char=255;
			else
				get_char=0;
		}

		#pragma omp ordered
		fprintf(output, "%c", get_char);
	}
	
	fclose(input);
	fclose(output);
}
