#include<iostream>
using namespace std;
int main()
{
	int x = 10;
	int *xptr = &x;
	
	cout<<xptr<<endl;
	cout<<&x<<endl;
	
	cout<<*(&x)<<endl;
	cout<<*xptr<<endl;
	
	cout<<*(&xptr)<<endl;
	cout<<&(*xptr)<<endl;
	
	int **xxptr = &xptr;
	cout<<&xptr<<endl;
	cout<<xxptr<<endl;
	
	return 0;
}
