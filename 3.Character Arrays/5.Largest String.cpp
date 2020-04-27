#include<iostream>
#include<cstring>
using namespace std;

void removeDuplicates(char a[])
{

}

int main()
{
	int n;
	cin>>n;
	
	char a[1000];
	char largest[1000];
	int l = 0;
	int len = 0;
	cin.get();
	for(int i=0;i<n;i++)
	{
		cin.getline(a,1000);
		l = strlen(a);
		if(l>len)
		{
			len = l;
			strcpy(largest,a);
		}
	}
	
	cout<<largest<<" "<<len<<endl;
	
	return 0;
}
