#include<iostream>
#include<cstring>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        long long arr[100000] = {0};
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string name;
            int rank;
            cin>>name>>rank;
            arr[rank]++;
        }
        int actual_rank = 1;
        long long badness = 0;
        for(int i=1;i<=n;i++)
        {
            while(arr[i])
            {
                badness = badness + abs(actual_rank-i);
                actual_rank++;
                arr[i]--;
            }
        }
        cout<<badness<<endl;
    }
    return 0;
}

