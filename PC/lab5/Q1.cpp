#include<bits/stdc++.h>
#include<omp.h>
#include<chrono>

using namespace std;

int fib(int n)
{
	if(n<=2)
		return n;
    int l,r,ans;
    #pragma omp task shared(l) firstprivate(n)
    {
    	l=fib(n-1);
    }
    #pragma omp task shared(r) firstprivate(n)
    { 
		r=fib(n-2);  
    }
    #pragma omp taskwait
    {
    	ans=(l+r);
    	return ans;
    }
}
int main()
{
	int n,ans=0;
	cin>>n;
	auto t1=std::chrono::system_clock::now();
	#pragma omp parallel shared(n)
	{
		#pragma omp single
		{
             ans=fib(n);
		} 
	}
	auto t2=std::chrono::system_clock::now();
	cout<<"\nthe answer is "<<ans<<endl;
	cout<<"Time taken is "<<(t2-t1).count()*1.0/(1e9*1.0)<<endl;

	return 0;
}