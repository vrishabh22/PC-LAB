#include <stdio.h>

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
    
    int min=arr[0];
    for (i = 1;i<n;i++)
    {
        if (arr[i] < min)
        {
            min=arr[i];
        }
    }
    printf("\n%d\n",min);
 
    return 0;
}