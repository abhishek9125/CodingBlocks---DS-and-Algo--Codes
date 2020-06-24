#include<iostream>
#include<vector>
using namespace std;

bool minHeap = false;

bool compare(int a,int b){
    return minHeap ? a < b : a > b;
}

void heapify(vector<int>& v,int index,int size){
    int left = index*2;
    int right = index*2 + 1;

    int max_index = index;
    int last = size - 1;

    if(left<=last && compare(v[left],v[index])){
        max_index = left;
    }
    if(right<=last && compare(v[right],v[max_index])){
        max_index = right;
    }
    if(max_index!=index){
        swap(v[max_index],v[index]);
        heapify(v,max_index,size);
    }
}

void buildHeapOptimized(vector<int>& v){
    for(int i=(v.size()-1)/2;i>=1;i--){
        heapify(v,i,v.size());
    }
}

void print(vector<int>& v){
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

void heapSort(vector<int>& v){
    buildHeapOptimized(v);
    int n = v.size();

    while(n>1){
        swap(v[1],v[n-1]);
        n--;
        heapify(v,1,n);
    }
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    int temp;
    v.push_back(-1);
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    heapSort(v);
    print(v);
    return 0;
}

