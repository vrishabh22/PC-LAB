#include<bits/stdc++.h>
#include<omp.h>
#include<chrono>

using namespace std;

int search(int tree[],int n,int pos,int num)
{
	int fl=0;
	int fr=0;
	int l=2*pos+1;
	int r=2*pos+2;
	if(pos>=n)
		return 0;
	#pragma omp task firstprivate(tree,n,l) shared(fl)
	  {
	  		fl=search(tree,n,l,num);
	  }
	#pragma omp task firstprivate(tree,n,r) shared(fr)
	  {
	  	fr=search(tree,n,r,num);
	  }
	 #pragma omp taskwait
	  {
	  	if(tree[pos]==num)
	  		{    
	  			return 1;
	  		}
	  	else if(fl || fr)
	  	    return 1;
	  	else 
	  	    return 0; 

	  }
}
int main()
{
	int tree[]={1,2,3,4,5,6,7};
	int n=7;
	int found=0;
	int num=6;
	#pragma omp parallel shared(n,tree,found) 
	{
		#pragma omp single 
		{
			found=search(tree,n,0,num);
		}
	}
	if(found)
		cout<<"Number found\n";
	else 
		cout<<"Number not found\n";
	return 0;
}