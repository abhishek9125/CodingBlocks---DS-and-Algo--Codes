#include<iostream>
using namespace std;

int power(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	int ans = a*power(a,b-1);
	return ans;
}

int fastPower(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	
	int smallAns = fastPower(a,b/2);
	smallAns *= smallAns;
	if(b&1)
	{
		return a*smallAns;
	}
	return smallAns;
}

int main()
{
	int a,b;
	cin>>a>>b;
	
	
	cout<<fastPower(a,b)<<endl;
	cout<<power(a,b)<<endl;
	return 0;
}
