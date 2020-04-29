#include<iostream>
#include<algorithm>
using namespace std;
//SPOJ
int canPlaceCows(int *stalls,int n,int c,int dist)
{
	int current = stalls[0];
	int count = 1;
	for(int i=1;i<n;i++)
	{
		if(stalls[i] - current>=dist)
		{
			current = stalls[i];
			count++;
			if(count==c)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
	cin>>n>>c;
	int *stalls = new int[n];	
	for(int i=0;i<n;i++)
	{
		cin>>stalls[i];
	}
	sort(stalls,stalls + n);
	
	int start = 0;
	int end = stalls[n-1] - stalls[0];
	int ans = 0;
	while(start<=end)
	{
		int mid = start + (end - start/2);
		bool solution = canPlaceCows(stalls,n,c,mid);
		if(solution)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	
	cout<<ans<<endl;
	}
	
	
	return 0;
}
