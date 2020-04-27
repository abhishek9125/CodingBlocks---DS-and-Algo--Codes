#include<iostream>
using namespace std;
int main()
{
	char a[] = {'a','b','c','d','e','\0'};
	cout<<a<<endl; 
	
	char s[10];
	cin>>s;
	cout<<s<<endl;
	
	char s1[] = {'h','e','l','l','o'}; //Not terminate with NULL : Avoid using it
	char s2[] = {'h','e','l','l','o','\0'}; 
	char s3[] = "hello";
	
	cout<<s1<<" "<<sizeof(s1)<<endl;
	cout<<s2<<" "<<sizeof(s2)<<endl;
	cout<<s3<<" "<<sizeof(s3)<<endl;
	return 0;
}
