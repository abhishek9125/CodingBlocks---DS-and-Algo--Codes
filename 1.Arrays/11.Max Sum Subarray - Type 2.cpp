#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	cin>>n;
	
	int *arr = new int[n];
	int crtSum[n] = {0};
	
	cin>>arr[0];
	crtSum[0] = arr[0];
	
	for(int i=1;i<n;i++)
	{
		cin>>arr[i];
		crtSum[i] = crtSum[i-1] + arr[i];
	}
	
	int maximumSum = 0;
	int currentSum = 0;
	
	int left = -1;
	int right = -1;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			currentSum = crtSum[j] - crtSum[i-1];
			if(currentSum>maximumSum)
			{
				left = i;
				right = j;
				maximumSum = currentSum;
			}
		}
	}
	
	cout<<"Maximum Sum Subarray : ";
	for(int k=left;k<=right;k++)
	{
		cout<<arr[k]<<" ";
	}
	cout<<endl;
	cout<<"Maximum Sum : "<<maximumSum<<endl;
	
	return 0;
}
