#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<sys/time.h>
int main(int argc, char const *argv[])
{
	struct timeval TimeValue_Start;
	struct timezone TimeZone_Start;
	struct timeval TimeValue_Final;
	struct timezone TimeZone_Final;
	long time_start,time_end;
	double time_overhead;
	int m1,n2,m2,n1,n;
	printf("enter the no of rows and columns of mat1 and mat2: ");
	scanf("%d",&n);
	//if(n1!=m2)
	//	printf("cannot multiply\n");
	//else
	//{
		int a[n][n], b[n][n], c[n][n];
		int i,j,k;
		//printf("Enter mat 1: ");
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]=rand()%100;
		//printf("Entr matrix 2: ");
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				b[i][j]=rand()%100;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				c[i][j]=0;

		int chunk,nthreads;
		printf("Enter the chunksize and no of threads: ");
		scanf("%d%d",&chunk,&nthreads);
		gettimeofday(&TimeValue_Start,&TimeZone_Start);
		#pragma omp parallel shared(a,b,c,n) private(i,j,k) num_threads(nthreads)
		#pragma omp for collapse(3) schedule(static,chunk) ordered
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					c[i][j] += a[i][k]*b[k][j];
	gettimeofday(&TimeValue_Final,&TimeZone_Final);
	time_start=TimeValue_Start.tv_sec*1000000+TimeValue_Start.tv_usec;
	time_end=TimeValue_Final.tv_sec*1000000+TimeValue_Final.tv_usec;
	time_overhead=(time_end-time_start)/1000000.0;
	printf("\nTime in Seconds(t)  :%lf\n",time_overhead);
		/*printf("Multiplied Matrix\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d\t",c[i][j]);
			printf("\n");
		}*/

	//}

	return 0;
}
