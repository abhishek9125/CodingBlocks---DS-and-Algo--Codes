#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	return b==0? a : gcd(b,a%b);
}

int lcm(int a,int b)
{
	int g = gcd(a,b);
	return (a*b)/g;
}

int main()
{
	//gvd*lcm = a*b;
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	cout<<lcm(a,b)<<endl;
	return 0;
}
