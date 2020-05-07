#include<iostream>
using namespace std;

int dp[100][100] = {0};
int cost[100][100];
int minCost(int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i==0 && j==0)
			{
				dp[i][j] = cost[0][0];
			}
			else if(i==0)
			{
				dp[i][j] = dp[0][j-1] + cost[0][j];
			}
			else if(j==0)
			{
				dp[i][j] = dp[i-1][0] + cost[i][0];
			}
			else
			{
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + cost[i][j];
			}
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[r-1][c-1];
}

int main()
{
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>cost[i][j];
		}
	}

	cout<<minCost(r,c)<<endl;
	return 0;
}
