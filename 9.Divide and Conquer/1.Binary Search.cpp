#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[],int n,int key)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = start + (end - start)/2;
		if(a[mid]==key)
		{
			return mid;
		}
		if(a[mid]>key)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;	
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

	cout<<"Enter key"<<endl;
    cin>>key;
    
    cout<<binary_search(arr,n,key);

    return 0;
}

