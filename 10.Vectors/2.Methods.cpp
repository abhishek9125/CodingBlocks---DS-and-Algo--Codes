#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> d{1,2,3,10,14};
	d.push_back(16);
	d.pop_back();
	d.insert(d.begin()+3,4,100);
	d.erase(d.begin()+2);
	d.erase(d.begin()+2,d.begin()+5);
	cout<<d.size()<<" "<<d.capacity<<endl;
	d.resize(18);
	for(int x:d)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	d.clear();
	for(int x:d)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<d.size();
	if(d.empty())
	{
		cout<<"Empty"<<endl;
	}
	
	d.push_back(10);
	d.push_back(11);
	d.push_back(12);
	d.push_back(13);
	
	cout<<d.front();
	cout<<d.back();
	
	//Reserve
	vector<int> v;
	v.reserve(1000);
	
	return 0;
}
