#include<iostream>
#include<cmath>
using namespace std;

int multiply(int a,int b)
{
	if(b==0)
	{
		return 0;
	}
	int ans = a + multiply(a,b-1);
	return ans;
}

int main()
{
	int a,b;
	cin>>a>>b;
	int ans = multiply(a,abs(b));
	cout<<ans*(b/abs(b))<<endl;
	
	return 0;
}
