#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char s[100] = "Today is a Rainy Day";
	char *ptr = strtok(s," ");
	cout<<ptr<<" ";
	
	while(ptr!=NULL)
	{
		ptr = strtok(NULL," ");
		cout<<ptr<<" ";
	}
	return 0;
}
