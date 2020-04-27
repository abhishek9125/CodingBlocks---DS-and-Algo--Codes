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
	
	int sum;
	cin>>sum;
	
	int i = 0;
	int j = n-1;
	
	while(i<j)
	{
		int cs = a[i] + a[j];
		if(cs>sum)
		{
			j--;
		}
		else if(cs<sum)
		{
			i++;
		}
		else if(cs==sum)
		{
			cout<<a[i]<<" "<<a[j]<<endl;
		}
	}
	
	return 0;
}
