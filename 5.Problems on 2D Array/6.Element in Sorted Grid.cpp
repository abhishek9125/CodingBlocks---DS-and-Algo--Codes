#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int value = 1;
	
	int **arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[n];	
	}	
	
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
	cout<<endl;
	int key;
	cin>>key;
	
	int x = 0;
	int y = n-1; 
	
	while(y>=0 and x<=n-1)
	{
		if(arr[x][y] == key)
		{
			cout<<"Index : "<<x<<","<<y<<endl;
			return 0;
		}
		else if(arr[x][y]<key)
		{
			x++;
		}
		else
		{
			y--;
		}
	}
	
	cout<<-1;
	return 0;
}
