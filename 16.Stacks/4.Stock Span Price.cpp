#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int *arr,int n)
{
	stack<int> s;
	int ans[n] = {};
	for(int i=0;i<n;i++)
	{
		int currentPrice = arr[i];
		while(s.empty() == false and arr[s.top()]<currentPrice)
		{
			s.pop();
		}
		int betterDay = s.empty() ? 0 : s.top();
		int span = i - betterDay;
		ans[i] = span;
		s.push(i);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	stockSpan(arr,n);
	
	delete []arr;
	return 0;
}
