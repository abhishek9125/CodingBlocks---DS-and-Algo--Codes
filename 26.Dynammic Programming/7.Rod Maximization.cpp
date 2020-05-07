#include<iostream>
using namespace std;

int dp[100];

int maxProfit(int totalLen,int arr[])
{
	if(totalLen==0)
	{
		return 0;
	}
	if(dp[totalLen] != -1)
	{
		return dp[totalLen];
	}
	int best = 0;
	for(int i=1;i<=totalLen;i++)
	{
		int profit = arr[i] + maxProfit(totalLen - i,arr);
		best = max(best,profit); 
	}
	dp[totalLen] = best;
	return best;
}

int maxProfitBU(int n,int arr[])
{
	int memo[100] = {};
	for(int i=1;i<=n;i++)
	{
		int best = 0;
		for(int j=1;j<=i;j++)
		{
			best = max(best,arr[j] + memo[i - j]);
		}
		memo[i] = best;
	}
	return memo[n];
}

int main()
{
	int totalLen;
	cin>>totalLen;
	int lengthPart[100];
	for(int i=0;i<=totalLen;i++)
	{
		dp[i] = -1;	
	}
	for(int i=1;i<=totalLen;i++)
	{
		cin>>lengthPart[i];
	}
	
	cout<<maxProfit(totalLen,lengthPart)<<endl;
	cout<<maxProfitBU(totalLen,lengthPart)<<endl;
	return 0;
}
