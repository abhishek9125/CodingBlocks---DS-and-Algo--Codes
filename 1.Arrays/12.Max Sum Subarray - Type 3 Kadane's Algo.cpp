#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int *arr = new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int ms = 0;
	int cs = 0;
	
	for(int i=0;i<n;i++)
	{
		cs = cs + arr[i];
		if(cs<0)
		{
			cs = 0;
		}
		
		if(ms<cs)
		{
			ms = cs;	
		}	
	}

	cout<<"Maximum Sum : "<<maximumSum<<endl;
	
	return 0;
}
