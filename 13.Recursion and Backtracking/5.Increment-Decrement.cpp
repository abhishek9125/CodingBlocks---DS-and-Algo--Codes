#include<iostream>
using namespace std;
void dec(int n)
{
	if(n==0)
	{
		return;
	}
	cout<<n<<" ";
	dec(n-1);
	return;
}

void inc(int n)
{
	if(n==0)
	{
		return;
	}
	
	inc(n-1);
	cout<<n<<" ";
	return;
}

int main()
{
	int n;
	cin>>n;
	
	dec(n);
	cout<<endl;
	inc(n);
	cout<<endl;
	
	return 0;
}
