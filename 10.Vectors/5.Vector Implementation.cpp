#include<iostream>
#include "vector.h"
using namespace std;

int main()
{
	Vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.pop_back();
	v.push_back(60);
	v.push_back(70);
	
	cout<<v.capacity()<<endl;
	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}
