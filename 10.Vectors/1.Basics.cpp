#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> a;
	vector<int> b(5,0);
	vector<int> c(b.begin(),b.end());
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		v.push_back(no);
	}
	
	for(int x: v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	
	cout<<v.size()<<" "<<v.capacity()<<" "<<v.max_size();
	cout<<b.size()<<" "<<b.capacity()<<" "<<b.max_size();	
	return 0;
}
