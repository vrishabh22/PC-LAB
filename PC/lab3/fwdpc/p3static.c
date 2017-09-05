#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<sys/time.h>
#include<omp.h>
void main()
{
	struct timeval TimeValue_Start;
	struct timezone TimeZone_Start;
	struct timeval TimeValue_Final;
	struct timezone TimeZone_Final;
	long time_start,time_end;
	double time_overhead;
	int i,N,a[100000],min=INT_MAX;
	printf("Enter n: ");
	scanf("%d",&N);
	for(i=0;i<N;i++)
		a[i]=rand()%10000;
	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
	printf("\n");
	gettimeofday(&TimeValue_Start,&TimeZone_Start);
	#pragma omp parallel shared(min)
	{
	#pragma omp for schedule(static)
	for(i=0;i<N;i++)
	{
		if(a[i]<min)
			min=a[i];
	}
	}	
	gettimeofday(&TimeValue_Final,&TimeZone_Final);
	time_start=TimeValue_Start.tv_sec*1000000+TimeValue_Start.tv_usec;
	time_end=TimeValue_Final.tv_sec*1000000+TimeValue_Final.tv_usec;
	time_overhead=(time_end-time_start)/1000000.0;
	printf("\nTime in Seconds(t)  :%lf\n",time_overhead);
	printf("Min is %d\n",min);
}
