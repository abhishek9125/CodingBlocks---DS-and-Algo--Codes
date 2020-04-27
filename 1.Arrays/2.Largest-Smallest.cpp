#include <iostream>
using namespace std;
int main() 
{
    int n,key;
    cin>>n;
    int* arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

   	int largest = INT_MIN;
   	int smallest = INT_MAX;
   	
   	for(int i=0;i<n;i++)
   	{
   		if(arr[i]<smallest)
		{
			smallest = arr[i];   	
		}
		
		if(arr[i]>largest)
		{
			largest = arr[i];
		}	
	}
	
	cout<<"Largest element in given array is "<<largest<<" and smallest element is "<<smallest<<endl;
   	
    return 0;
}

