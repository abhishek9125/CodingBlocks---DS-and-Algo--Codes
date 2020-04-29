#include<iostream>
#include<algorithm>
//Hackerblocks
int find_key(int arr[],int n,int key)
{
	int start = 0;
	int end = n - 1;
	while(start<=end)
	{
		int mid = start + (end - start)/2;
		if(arr[mid] == key)
		{
			return mid;
		}
		else if(arr[start]<=arr[mid])
		{
			if(key>=arr[start] and key<=arr[mid])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		else
		{
			if(key>=arr[mid] and key<=arr[end])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
	}
	return -1;
}

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
	
	int key;
	cin>>key;
	
	cout<<find_key(arr,n,key)<<endl;
	
	return 0;
}
