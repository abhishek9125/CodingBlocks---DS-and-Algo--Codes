#include<iostream>
#include<algorithm>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int rows,cols,n;
        cin>>rows>>cols>>n;
        long long x[n+1],y[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        sort(x,x+n);
        sort(y,y+n);

        long long dx = x[0] - 1;
        long long dy = y[0] - 1;

        for(int i=1;i<n;i++)
        {
            dx = max(dx,x[i] - x[i-1] - 1);
            dy = max(dy,y[i] - y[i-1] - 1);
        }

        dx = max(dx,rows - x[n-1]);
        dy = max(dy,cols - y[n-1]);

        cout<<dx*dy<<endl;
    }
    return 0;
}    
