#include<iostream>
using namespace std;

int maxSumSubMatrix(int **arr,int n,int m)
{
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-2;j>=0;j--)
		{
			arr[i][j] += arr[i][j+1];
		}
	}
	
	for(int i=n-2;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			arr[i][j] += arr[i+1][j];
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int result = INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			result = max(arr[i][j],result);
		}
	}
	
	return result;
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	int **arr = new int*[n];
	for(int i=0;i<m;i++)
	{
		arr[i] = new int[m];
	}
	
	int value = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			value++;
		}
	}


	cout<<maxSumSubMatrix(arr,n,m)<<endl;	
	return 0;
}
