#include<iostream>
using namespace std;
int main()
{
	int x = 10;
	cout<<&x<<endl;
	
	float y = 10.5;
	cout<<&y<<endl;
	
	char ch = 'A';
	cout<<&ch<<endl;
	//Explicit Typecasting as << overloaded for char type
	cout<<(void *)&ch<<endl; //void * means we dont know data type
	
	int *xptr = &x;
	cout<<&x<<endl;
	cout<<xptr<<endl;
	return 0;
}
