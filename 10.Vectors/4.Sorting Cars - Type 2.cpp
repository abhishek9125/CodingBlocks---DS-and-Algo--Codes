#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

class Car{
	public:
	string name;
	int x,y;
	
	Car(string name,int x,int y)
	{
		this->name = name;
		this->x = x;
		this->y = y;
	}
	
	int dist()
	{
		return x*x + y*y;
	}
};

bool compare(Car A,Car B)
{
	int da = A.dist();
	int db = B.dist();
	
	if(da==db)
	{
		return A.name<B.name;
	}
	
	return da<db;
}

int main()
{
	int n;
	cin>>n;
	vector<Car> v;
	for(int i=0;i<n;i++)
	{
		string name;
		int x,y;
		cin>>name>>x>>y;
		Car temp(name,x,y);
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end(),compare);
	
	for(auto c: v)
	{
		cout<<"Car: "<<c.name<<" Distance: "<<c.dist()<<" Location: "<<"("<<c.x<<","<<c.y<<")"<<endl;
	}
		
	return 0;
}
