#include<iostream>
#include<string>
using namespace std;
int main()
{
	//Initialize
	string s0;
	string s1("Hello");
	string s2 = "Hello World";
	string s3(s2);
	string s4 = s3;
	
	char a[] = {'a','b','c','\0'};
	string s5(a);
	
	cout<<s0<<endl;
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s4<<endl;
	cout<<s5<<endl;
	
	if(s0.empty())
	{
		cout<<"s0 is an empty String"<<endl;
	}
	
	//Append
	s0.append("I Love C++");
	cout<<s0<<endl;
	s0 += " and Python";
	
	//Remove
	cout<<s0<<endl;
	cout<<s0.length()<<endl;
	s0.clear();
	cout<<s0.length()<<endl;
	
	//Compare
	s0 = "Apple";
	s1 = "Mango";
	cout<<s0.compare(s1)<<endl;
	
	//Overloaded Operator
	if(s1>s0)
	{
		cout<<"Mango is Lexicographically greater than Apple"<<endl;
	}
	
	cout<<s1[0]<<endl;
	
	//Substrings
	string s = "I want to have Apple Juice";
	int index = s.find("Apple");
	cout<<index<<endl;
	
	//Remove Word
	string word = "Apple";
	int len = word.length();
	cout<<s<<endl;
	s.erase(index,len + 1);
	cout<<s<<endl;	
	
	//Iterate
	for(int i=0;i<s1.length();i++)
	{
		cout<<s1[i]<<" "; 
	}
	
	cout<<endl;
	
	for(auto it = s.begin();it!=s.end();it++)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;
	
	for(auto c:s1){
		cout<<c<<",";
	}
	
	return 0;
}
