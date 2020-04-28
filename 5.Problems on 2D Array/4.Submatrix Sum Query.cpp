#include<iostream>
using namespace std;
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
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	
	for(int i=1;i<n;i++)
	{
		arr[0][i] = arr[0][i] + arr[0][i-1];
		arr[1][i] = arr[1][i] + arr[1][i-1];
		arr[2][i] = arr[2][i] + arr[2][i-1];
	}
	
		for(int i=1;i<n;i++)
	{
		arr[i][0] = arr[i][0] + arr[i-1][0];
		arr[i][1] = arr[i][1] + arr[i-1][1];
		arr[i][2] = arr[i][2] + arr[i-1][2];
	}
	
	cout<<endl;
	
	int q;
	cin>>q;
	
	while(q--)
	{
		int i,j,k,l;
		cin>>i>>j>>k>>l;
		int sum = 0;
		if(i==0 or j==0)
		{
			sum = arr[k][l];			
		}
		else
		{
			sum = arr[k][l] - arr[i-1][l] - arr[k][j-1] + arr[i-1][j-1];
		}
		cout<<"Top Left : ("<<i<<","<<j<<")"<<" "<<"Bottom Right : ("<<k<<","<<l<<") "<<"Sum : "<<sum<<endl;
	}

	
	return 0;
}
