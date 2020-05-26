#include<iostream>
using namespace std;

int main() 
{
    while(true)
    {
        int n;
        int arr[9000];
        cin>>n;
        if(n==-1)
        {
            break;
        }
        int load = 0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            load = load + arr[i];
        }
        if(load%n!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        load = load/n;
        int diff = 0;
        int max_load = 0;
        for(int i=0;i<n;i++)
        {
            diff = diff + arr[i] - load;
            int ans = max(diff,-diff);
            max_load = max(max_load,ans);
        }
        cout<<max_load<<endl;
    }

    return 0;
}

