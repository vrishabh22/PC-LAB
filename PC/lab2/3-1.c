#include <omp.h>
#include <stdio.h>
void main()
{
int j, k, a;
#pragma omp parallel num_threads(2)
{
#pragma omp for ordered private(j,k) schedule(static,3)
for (k=1; k<=3; k++)
for (j=1; j<=2; j++)
{
#pragma omp ordered
printf("%d %d %d\n", omp_get_thread_num(), k, j);
/* end ordered */
}
}
}