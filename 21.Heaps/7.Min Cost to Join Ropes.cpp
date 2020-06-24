#include<iostream>
#include<queue>
using namespace std;

int joinRopes(int* ropes,int n){
    priority_queue<int,vector<int>,greater<int>> q(ropes,ropes+n);  //By default maxHeap, greater<int> --> minHeap
    int cost = 0;
    while(q.size()>1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        cost = cost + a + b;
        q.push(a+b);
    }
    return cost;
}

int main(){
    int ropes[] = {4,3,2,6};
    int n = 4;
    cout<<joinRopes(ropes,n)<<endl;
    return 0;
}

