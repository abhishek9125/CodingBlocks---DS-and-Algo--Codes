#include <iostream>
using namespace std;

void selection_sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min_index = i;
		for(int j=i;j<n;j++)
		{
			if(a[j]<a[min_index])
			{
				min_index = j;
			}
		}
		
		swap(a[min_index],a[i]); 
	}
}

int main() 
{
    int n,key;
    cin>>n;
    int* arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	
	selection_sort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
