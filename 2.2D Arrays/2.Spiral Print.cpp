#include<iostream>
using namespace std;

void spiralprint(int n,int m,int a[][100])
{
	int sr = 0;
	int sc = 0;
	int er = n-1;
	int ec = m-1;
	
	while(sr<=er and sc<=ec)
	{
		for(int i=sc;i<=ec;i++)
		{
			cout<<a[sr][i]<<" ";
		}
		sr++;
		for(int i=sr;i<=er;i++)
		{
			cout<<a[i][ec]<<" ";
		}
		ec--;
		if(er>sr)
		{
			for(int i=ec;i>=sc;i--)
			{
				cout<<a[er][i]<<" ";
			}
		}
		er--;
		if(ec>sc)
		{
			for(int i=er;i>=sr;i--)
			{
				cout<<a[i][sc];
			}
		}
		sc++;
		cout<<" ";
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	int arr[100][100];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	spiralprint(n,m,arr);
}
