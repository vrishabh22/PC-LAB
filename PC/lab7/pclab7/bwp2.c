#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/time.h>
#include<stdlib.h>

int main(){

FILE *input,*I2,*I3,*I4, *output,*o2,*o3,*o4;
//unsigned char get_char,new_char;

struct timeval TimeValue_Start;
struct timezone TimeZone_Start;
struct timeval TimeValue_Final;
struct timezone TimeZone_Final;
long time_start, time_end;
double time_overhead;

input = fopen("lena.bmp", "rb");
output = fopen("jena2.bmp", "wb");


fseek(input,0,2);
int count=ftell(input),i=0,i2,i3,i4;
printf("%d\n",count);
fseek(input,0,0);

unsigned char get_char[count],new_char;


if(fread(&get_char,sizeof(char),count,input)==EOF)
	return 0;
gettimeofday(&TimeValue_Start, &TimeZone_Start);




#pragma omp parallel for \
default(shared) \
num_threads(16)
for(i=0;i<count;i++)
{
	
		
		if(i>=1078)
		{
			if((unsigned int)get_char[i]>127)
			  	get_char[i]=255;
			else
			  	get_char[i]=0;
		}
		
}

fwrite(&get_char,sizeof(char),count,output);

gettimeofday(&TimeValue_Final, &TimeZone_Final);
time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
printf("\n\n\t\t Time in Seconds (T) : %lf\n",time_overhead);

//fseeko(output,-53,SEEK_END);
//ftruncate(fileno(output), ftello(output));
fclose(input);
fclose(output);

return 0;
}
