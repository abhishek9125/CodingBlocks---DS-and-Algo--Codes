#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> maxQ;
    priority_queue<int,vector<int>,greater<int>> minQ;
    int d;
    cin>>d;
    maxQ.push(d);
    float median = d;
    cout<"Median: "<<median<<" ";
    cin>>d;

    while(d!=-1){
        if(maxQ.size()>minQ.size()){
            if(d<median){
                minQ.push(maxQ.top());
                maxQ.pop();
                maxQ.push(d);
            }else{
                minQ.push(d);
            }
            median = (maxQ.top() + minQ.top())/2.0;
        }else if(maxQ.size()==minQ.size()){
            if(d<median){
                maxQ.push(d);
                median = maxQ.top();
            }else{
                minQ.push(d);
                median = minQ.top();
            }
        }else{
            if(d>median){
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(d);
            }else{
                maxQ.push(d);
            }
            median = (maxQ.top() + minQ.top())/2.0;
        }
        cout<<median<<" ";
        cin>>d;
    }

    return 0;
}

