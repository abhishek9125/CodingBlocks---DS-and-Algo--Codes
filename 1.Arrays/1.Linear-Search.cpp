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

    cout<<"Enter key"<<endl;
    cin>>key;

    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key){
            cout<<"Element "<<key<<" found at index "<<i<<endl;
            break;
        }
    }
    if(i==n){
        cout<<"Key not present in array"<<endl;
    }
    return 0;
}

