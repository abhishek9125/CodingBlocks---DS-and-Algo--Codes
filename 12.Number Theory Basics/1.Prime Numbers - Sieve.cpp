#include<iostream>
using namespace std;

void sieve(int* p)
{
	p[0] = p[1] = 0;
	p[2] = 1;
	for(int i=3;i<=10000;i+=2)
	{
		p[i] = 1;
	}
	
	for(long long i=3;i<=10000;i+=2)
	{
		if(p[i]==1)
		{
			for(long long j =i*i;j<=10000;j=j+i)
			{
				p[j] = 0;
			}
		}
	}	
}

int main()
{
	int n;
    cin>>n;
	int p[100000] = {0};
	sieve(p);
	for(int i=0;i<=n;i++)
	{
		if(p[i]==1)
		{
			cout<<i<<" ";
		}
	}
	
	return 0;
}
