#include<iostream>
#include<climits>
using namespace std;
//https://hack.codingblocks.com/app/practice/1/1365/problem
bool isPossible(int *pages,int n,int m,int current)
{
	int students = 1;
	int cur_pages = 0;
	for(int i=0;i<n;i++)
	{
		if(pages[i] + cur_pages > current)
		{
			students++;
			cur_pages = pages[i];
			if(students>m)
			{
				return false;
			}
		}
		else
		{
			cur_pages += pages[i];
		}
	}
	return true;
}

int findPages(int *pages,int n,int m)
{
	if(n<m)
	{
		return -1;
	}
	
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += pages[i];
	}
	
	int start = pages[n-1];
	int end = sum;
	int ans = INT_MAX;
	
	while(start<=end)
	{
		int mid = start + (end - start)/2;
		if(isPossible(pages,n,m,mid))
		{
			ans = mid;
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int *pages = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>pages[i];
		}
		
		cout<<findPages(pages,n,m)<<endl;
		
		delete []pages;
	}
	return 0;
}
