#include<iostream>
using namespace std;
//Contribution - Sum of all Sub Arrays

int subMatrix(int **arr,int n,int m)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int top = (i+1)*(j+1);
			int bottom = (n-i)*(m-j);
			sum += top*bottom*arr[i][j];
		}
	}
	return sum;
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
			arr[i][j] = value;
			value++;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
		
	cout<<subMatrix(arr,n,m)<<endl;	
	return 0;
}
