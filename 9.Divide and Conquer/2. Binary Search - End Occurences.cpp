#include<iostream>
using namespace std;

int first_occurence(int a[],int n,int key)
{
	int start = 0;
	int end = n-1;
	int ans = -1;
	while(start<end)
	{
		int mid = start + (end - start)/2;
		if(a[mid] == key)
		{
			ans = mid;
			end = mid - 1;
		}
		else if(a[mid]<key)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return ans;
}

int last_occurence(int a[],int n,int key)
{
	int start = 0;
	int end = n-1;
	int ans = -1;
	while(start<end)
	{
		int mid = start + (end - start)/2;
		if(a[mid] == key)
		{
			ans = mid;
			start = mid + 1;
		}
		else if(a[mid]<key)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return ans;
}

int main()
{
	int arr[] = {1,2,5,8,8,8,8,10,12,15,20};
	int n = sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	
	cout<<first_occurence(arr,n,key)<<endl;
	cout<<last_occurence(arr,n,key)<<endl;
	
	return 0;
}
