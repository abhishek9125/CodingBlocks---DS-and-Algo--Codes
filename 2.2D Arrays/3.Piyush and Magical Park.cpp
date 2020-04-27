#include<iostream>
using namespace std;

void magical_park(char a[][100], int n, int m, int k, int s)
{
	bool success = true;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char c = a[i][j];
			if(s<k)
			{
				success = false;
				break;
			}
			if(c == '*')
			{
				s += 5;
			}
			else if(c == '.')
			{
				s -= 2;
			}
			else
			{
				break;
			}
			if(j!=m-1)
			{
				s -= 1;
			}
		}
	
	}

	if(success)
	{
		cout<<"Yes"<<endl;
		cout<<s<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return;
}

int main() 
{
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	char a[100][100];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}

	magical_park(a, n, m, k, s);

	return 0;
}
