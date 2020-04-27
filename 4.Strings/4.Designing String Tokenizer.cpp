#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char *mystrtok(char* str,char delim)
{
	static char *input = NULL;
	if(str!=NULL)
	{
		input = str;
	}
	
	if(input==NULL)
	{
		return NULL; 	//Base Case as need to return NULL at end
	}
	
	char* output = new char[strlen(input) + 1];
	int i;
	for(i=0;input[i]!='\0';i++)
	{
		if(input[i]!=delim)
		{
			output[i] = input[i];
		}
		else
		{
			output[i] = '\0';
			input = input + i + 1;
			return output;
		}
	}
	output[i] = '\0';  //For last element need to put NULL at end
	input = NULL;
	return output;
	
}

int main()
{
	char s[100] = "Today, is a Rainy, Day";
	char *ptr = mystrtok(s,' ');
	cout<<ptr<<" ";
	
	while(ptr!=NULL)
	{
		ptr = mystrtok(NULL,' ');
		cout<<ptr<<" ";
	}
	return 0;
}
