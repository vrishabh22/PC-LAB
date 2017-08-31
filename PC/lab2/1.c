#include<omp.h>
 #include<stdio.h>
 #include<stdlib.h>
 #define CHUNKSIZE 10 
#define N 100

 int main (int argc, char *argv[]) 
 {
 int nthreads=5, tid, i, chunk=CHUNKSIZE;
 float a[N], b[N], c[N]; 
for (i=0; i < N; i++) 
a[i] = b[i] = i * 1.0; // initialize arrays chunk = CHUNKSIZE; 

#pragma omp parallel shared(a,b,c,nthreads,chunk) private(tid) num_threads(nthreads)
{ 
tid = omp_get_thread_num(); 
if (tid == 0) { 
//nthreads = omp_get_num_threads(); 
printf("Number of threads = %d\n", nthreads); 
}
 printf("Thread %d starting...\n",tid); 
#pragma omp for schedule(static,chunk) 
for (i=0; i<N;i++)
{
     c[i]=a[i]+b[i];
     printf("Thread %d:c[%d]=%f\n",tid,i,c[i]);
}// end of parallel section
}
}
