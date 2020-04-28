#include<iostream>
using namespace std;
int main()
{
	int **arr;
	int r,c;
	cin>>r>>c;
	
	arr = new int*[r];
	for(int i=0;i<r;i++)
	{
		arr[i] = new int[c];
	}
	
	return 0;
}
