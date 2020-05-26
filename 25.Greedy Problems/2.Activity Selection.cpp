#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}

int main() 
{
    int t;
    cin>>t;
    vector<pair<int,int> > v;
    while(t--)
    {
        int n,s,e;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }   
        sort(v.begin(),v.end(),compare);
        int ans = 1;
        int ft = v[0].second;

        for(int i=1;i<n;i++)
        {
            if(v[i].first>=ft)
            {
                ft = v[i].second;
                ans++;
            }
        }
        cout<<ans<<endl;
        v.clear();
    }
    return 0;
}

