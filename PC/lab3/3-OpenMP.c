#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <limits.h>



int main()
{
    int n,i;
    printf("Enter size\n");
    scanf("%d",&n);
    int arr[n];
    for (i = 0;i<n;i++)
    {
    	arr[i]=rand();
    }
    
    int min=INT_MIN;
    #pragma omp parallel private(i){
minl = INT_MAX;
#pragma omp for
for (i=0;i<N;i++)
  if (A[i]<minl)
    minl=A[i];
#pragma omp critical{
if (minl<min)
  min=minl;
}
    printf("\n%d\n",min);
 
    return 0;
}




