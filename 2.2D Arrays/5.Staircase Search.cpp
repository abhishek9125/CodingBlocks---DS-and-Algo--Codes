#include<bits/stdc++.h>
using namespace std;

void staircase_search(int a[][100],int n,int m,int key)
{
	int i = 0;
	int j = m - 1;
	cout<<"Path Followed : "<<endl;
	while(i<n and j>=0)
	{
		if(a[i][j] == key)
		{
			cout<<"Index is : "<<i<<" "<<j<<endl;
			return;
		}
		else if(a[i][j]<key)
		{
			i++;
		}
		else
		{
			j--;
		}
		cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
	}
	
	cout<<"No key exists"<<endl;
	return;
}

int main()
{
	int a[100][100];
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	
	int key;
	cin>>key;
	
	staircase_search(a,n,m,key);
	cout<<endl<<endl;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}

	return 0;
}
