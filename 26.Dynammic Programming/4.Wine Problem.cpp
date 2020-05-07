#include<iostream>
using namespace std;

int wineProblemTD(int *wines,int i,int j,int y,int dp[][100])
{
	if(i>j)
	{
		return 0;
	}
	
	if(dp[i][j]!=0)
	{
		return dp[i][j];
	}
	
	int option1 = wines[i]*y + wineProblemTD(wines,i+1,j,y+1,dp);
	int option2 = wines[j]*y + wineProblemTD(wines,i,j-1,y+1,dp);
	
	dp[i][j] = max(option1,option2);
	
	return dp[i][j];
}


int main()
{
	int wines[] = {2,3,5,1,4};
	int n = sizeof(wines)/sizeof(int);
	
	int dp[100][100] = {0};
	cout<<wineProblemTD(wines,0,n-1,1,dp)<<endl;
//	cout<<wineProblemBU(wines,0,n-1,1)<<endl;
	return 0; 
}
