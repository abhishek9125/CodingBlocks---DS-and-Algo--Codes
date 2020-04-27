#include<iostream>
#include<cstring>
using namespace std;

void removeDuplicates(char a[])
{
	int prev = 0;
	int n = strlen(a);
	
	if(n==0 or n==1)
	{
		return;
	}
		
	for(int current = 0;current<n;current++)
	{
		if(a[prev]!=a[current])
		{
			prev++;
			a[prev] = a[current];
		}
	}
	a[prev + 1] = '\0';
	return;
}

int main()
{
	char a[1000];
	cin.getline(a,1000);
	removeDuplicates(a);
	cout<<a<<endl;
	
	return 0;
}
