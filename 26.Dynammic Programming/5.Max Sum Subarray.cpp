#include<iostream>
using namespace std;

int maxSumSubArray(int *arr,int n)
{
	int dp[100] = {};
	dp[0] = arr[0]>0?arr[0]:0;
	int maxSoFar = dp[0];
	
	for(int i=1;i<n;i++)
	{
		dp[i] = dp[i-1] + arr[i];
		if(dp[i]<0)
		{
			dp[i] = 0;
		}
		maxSoFar = max(maxSoFar,dp[i]);
	}
	
	return maxSoFar;
}

int maxSumSpaceOptimized(int arr[],int n)  //Kadane's Algorithm
{
	int currentSum = 0;
	int maxSum = 0;
	for(int i=0;i<n;i++)
	{
		currentSum += arr[i];
		if(currentSum<0)
		{
			currentSum = 0;
		}
		maxSum = max(maxSum,currentSum);
	}
	return maxSum;
}

int main()
{
	int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
	int n = sizeof(arr)/sizeof(int);
	
	cout<<maxSumSubArray(arr,n)<<endl;
	cout<<maxSumSpaceOptimized(arr,n)<<endl;
	return 0;
}
