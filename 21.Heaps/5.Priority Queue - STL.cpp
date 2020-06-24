#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    while(n--){
        int x;
        cin>>x;
        q.push(x);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}

