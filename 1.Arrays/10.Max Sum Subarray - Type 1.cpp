#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	cin>>n;
	
	int *arr = new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int maximumSum = 0;
	int currentSum = 0;
	
	int left = -1;
	int right = -1;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			currentSum = 0;
			for(int k=i;k<=j;k++)
			{
				currentSum += arr[k];
				if(currentSum>maximumSum)
				{
					left = i;
					right = j;
					maximumSum = currentSum;
				}
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
