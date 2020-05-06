#include<iostream>
#include<stack>
using namespace std;
bool isValidParenthesis(string str)
{
	stack<char> s;
	for(int i=0;i<str.length();i++)
	{
		char currentChar = str[i];
		if(currentChar == '(')
		{
			s.push(currentChar);	
		}
		else if(currentChar == ')')
		{
			if(s.empty() || s.top()!='(')
			{
				return false;
			}
			s.pop();
		}	
	}
	
	return s.empty();
		
}

int main()
{
	string str;
	cin>>str;
	cout<<isValidParenthesis(str);
	return 0;
}
