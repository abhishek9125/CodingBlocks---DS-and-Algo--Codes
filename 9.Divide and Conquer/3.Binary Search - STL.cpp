#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[] = {20,30,40,40,40,50,100,1100};
	int n = sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	
	bool present = binary_search(arr,arr+n,key);
	if(present)
	{
		cout<<"Present"<<endl;
	}
	else
	{
		cout<<"Not Prsent"<<endl;
	}
	
	auto lb = lower_bound(arr,arr+n,40);
	cout<<(lb-arr)<<endl;
	
	auto ub = upper_bound(arr,arr+n,40);
	cout<<(ub-arr)<<endl;
	
	cout<<"Frequency of 40 : "<<(ub-lb)<<endl;
	
	return 0;
}
