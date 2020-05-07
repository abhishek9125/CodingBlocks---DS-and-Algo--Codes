#include<iostream>
using namespace std;

int lis(int arr[],int n)
{
	int dp[100];
	for(int i=0;i<n;i++)
	{
		dp[i] = 1;
	}
	int best = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<=arr[i])
			{
				int curLength = 1 + dp[j];
				dp[i] = max(dp[i],curLength);
			}
		}
		best = max(best,dp[i]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return best;
}

int main()
{
	int arr[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];	
	}
	int ans = lis(arr,n);
	cout<<ans<<endl;
	return 0;
}
