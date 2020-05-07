#include<iostream>
using namespace std;

int mitosis(int n,int x,int y,int z)
{
	int* dp = new int[n];
	dp[0] = 0;
	dp[1] = 0;
	
	for(int i=2;i<=n;i++)
	{
		if(i%2==0)
		{
			dp[i] = min(dp[i/2]+x,dp[i-1]+y);
		}
		else
		{
			dp[i] = min(dp[i+1/2]+x+z,dp[i-1]+y);
		}
	}
	
	return dp[n];
}

int main()
{
	int x,y,z,n;
	cin>>n>>x>>y>>z;
	
	cout<<mitosis(n,x,y,z)<<endl;
	
	return 0;
}
