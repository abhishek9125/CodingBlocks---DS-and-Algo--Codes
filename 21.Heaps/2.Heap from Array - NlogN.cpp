#include<iostream>
#include<vector>
using namespace std;

bool minHeap = true;

bool compare(int a,int b){
    return minHeap ? a < b : a > b;
}

void buildHeap(vector<int>& v){
    for(int i=2;i<v.size();i++){
        int index = i;
        int parent = index/2;

        while(index>1 && compare(v[index],v[parent])){
            swap(v[index],v[parent]);
            index = parent;
            parent = index/2;
        }
    }
}

void print(vector<int>& v){
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {-1,10,20,5,6,1,8,9,4};
    print(v);
    buildHeap(v);
    print(v);
    return 0;
}
