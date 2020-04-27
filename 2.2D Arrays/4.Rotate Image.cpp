#include<bits/stdc++.h>
using namespace std;

void rotate(int a[][100], int n)
{
	//Reverse Each Row
	for(int row=0;row<n;row++)
	{
		int start = 0;
		int end = n-1;
		while(start<end)
		{
			swap(a[row][start],a[row][end]);
			start++;
			end--;
		}
	}
	
	//Taking Transpose
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<j)
			{
				swap(a[i][j],a[j][i]);
			}
		}
	}
	
	return;
	
}

void rotate_stl(int a[][100],int n)
{
	for(int i=0;i<n;i++)
	{
		reverse(a[i],a[i] + n);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<j)
			{
				swap(a[i][j],a[j][i]);
			}
		}
	}
	
	return;
}

int main()
{
	int a[100][100];
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	rotate(a,n);
	cout<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	rotate_stl(a,n);
	cout<<endl<<endl;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
