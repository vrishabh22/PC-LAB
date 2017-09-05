#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main()
{
	int N,a[1000][1000],b[1000][1000],i,j,k,c[1000][1000];
	printf("Enter size of matrix\n");
	scanf("%d",&N);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			c[i][j]=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];		
			}
		}
	}
	printf("Answer is \n");
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
}
