#include<iostream>
#include<climits>
using namespace std;

int minCoinChangeTD(int n,int den[],int t,int dp[])
{
	if(n==0)
	{
		return 0;
	}
	if(dp[n]!=0)
	{
		return dp[n];
	}
	int ans = INT_MAX;
	for(int i=0;i<t;i++)
	{
		if(n-den[i]>=0)
		{
			int money = minCoinChangeTD(n-den[i],den,t,dp);
			ans = min(ans,money + 1);
		}
	}
	dp[n] = ans;
	return dp[n];
}

int minCoinChangeBU(int n,int coins[],int t)
{
	int dp[100] = {0};
	
	for(int i=1;i<=n;i++)
	{
		dp[i] = INT_MAX;
		for(int j=0;j<t;j++)
		{
			if(i-coins[j]>=0)
			{
				int count = dp[i-coins[j]] + 1;
				dp[i] = min(dp[i],count);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	int den[] = {1,7,10};
	int t = sizeof(den)/sizeof(int);
	int dp[100] = {0};
	cout<<minCoinChangeTD(n,den,t,dp)<<endl;
	cout<<minCoinChangeBU(n,den,t)<<endl;
	return 0;
}
