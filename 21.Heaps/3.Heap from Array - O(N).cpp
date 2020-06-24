#include<iostream>
#include<vector>
using namespace std;

bool minHeap = true;

bool compare(int a,int b){
    return minHeap ? a < b : a > b;
}

void heapify(vector<int>& v,int index){
    int left = index*2;
    int right = index*2 + 1;
    int minIndex = index;
    int last = v.size() - 1;

    if(left<=last && compare(v[left],v[index])){
        minIndex = left;
    }
    if(right<=last && compare(v[right],v[minIndex])){
        minIndex = right;
    }
    if(minIndex!=index){
        swap(v[index],v[minIndex]);
        heapify(v,minIndex);
        return;
    }
}

//void buildHeap(vector<int>& v){
//    for(int i=2;i<v.size();i++){
//        int index = i;
//        int parent = index/2;
//
//        while(index>1 && compare(v[index],v[parent])){
//            swap(v[index],v[parent]);
//            index = parent;
//            parent = index/2;
//        }
//    }
//}

void buildHeapOptimized(vector<int>& v){
    for(int i=(v.size()-1)/2;i>0;i--){
        heapify(v,i);
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
    buildHeapOptimized(v);
    print(v);
    return 0;
}
