#include<iostream>
using namespace std;
//Brute Force
int main()
{
	int arr[10][10];
	int n;
	cin>>n;
	int value = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j] = value;
			value++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=i;k<n;k++)
			{
				for(int l=j;l<n;l++)
				{
					int sum = 0;
					for(int m=i;m<=k;m++)
					{
						for(int n=j;n<=l;n++)
						{
							sum = sum + arr[m][n];
						}
					}
					cout<<"Top : ("<<i<<","<<j<<")"<<" "<<"Bottom : ("<<k<<","<<l<<") "<<"Sum : "<<sum<<endl;
				}
			}
		}
	}
	
	return 0;
}
