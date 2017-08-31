#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
int main(void){
double pi,x;
int i,N;
pi=0.0;
N=1000;
#pragma omp parallel for
for(i=0;i<=N;i++)
{
	x=(double)i/N;
pi+=4/(1+x*x);
}
pi=pi/N;
printf("Pi is %f\n",pi);
}