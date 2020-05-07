#include<iostream>
#include<climits>
using namespace std;
int arr[100];
long long dp[100][100];

long long sum(int i,int j)
{
	long long ans = 0;
	for(int k=i;k<=j;k++)
	{
		ans += arr[k];
        ans %= 100;
	}
	return ans;
}

long long mixtures(int i,int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(dp[i][j]!=-1)    
	{
		return dp[i][j];
	}
    dp[i][j] = INT_MAX;
	for(int k=i;k<=j;k++)
	{
		dp[i][j] = min(dp[i][j],mixtures(i,k) + mixtures(k+1,j) + sum(i,k)*sum(k+1,j));
	}
	
	return dp[i][j];
}

int main()
{
	int n;
	while((scanf("%d",&n))!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				dp[i][j] = -1;
			}
		}
		cout<<mixtures(0,n-1)<<endl;
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
