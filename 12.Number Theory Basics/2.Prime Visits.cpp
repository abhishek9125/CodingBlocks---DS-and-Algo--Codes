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
	int p[100000] = {0};
	sieve(p);
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		int count = 0;
		for(int i=a;i<=b;i++)
		{
			if(p[i]==1)
			count++;
		}
		cout<<count<<endl;
	}
	//Method 2
//	int csum[100000] = {0};
//	for(int i=1;i<=10000;i++)
//	{
//		csum[i] = csum[i-1] + p[i];
//	}
//	cout<<csum[b]-csum[a-1]<<endl;
	return 0;
}
