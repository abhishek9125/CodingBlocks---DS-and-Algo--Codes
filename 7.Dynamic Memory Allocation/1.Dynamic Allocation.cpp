#include<iostream>
using namespace std;
int main()
{
	int b[100];
	cout<<sizeof(b)<<endl;
	
	int n;
	cin>>n;
	
	int *a = new int[n];
	cout<<sizeof(a)<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cout<<a[i]<<" ";
	}
	cout<<endl;
	delete []a;

	return 0;
}
