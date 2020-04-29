#include<iostream>
using namespace std;

float squareRoot(int n,int p)
{
	int start = 0;
	int end = n;
	float ans = -1;
	
	while(start<=end)
	{
		int mid = start + (end - start)/2;
		if(mid*mid == n)
		{
			return mid;	
		}
		else if(mid*mid<n)
		{
			ans = mid;
			start = mid + 1;	
		}	
		else
		{
			end = mid - 1;
		}
	}
	float inc = 0.1;
	for(int times=1;times<=p;times++)
	{
		while(ans*ans<=n)
		{
			ans += inc;
		}
		ans = ans - inc;
		inc = inc/10;
	}
	return ans;
}

int main()
{
	int n,p;
	cin>>n>>p;
	cout<<squareRoot(n,p)<<endl;
	return 0;
}
