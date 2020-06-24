#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Heap{
    vector<int> v;
    bool minHeap = true; // True when minHeap otherwise maxHeap

    bool compare(int a,int b){
        return minHeap ? a < b : a > b;
    }

    void heapify(int index){
        int left = 2*index;
        int right = 2*index + 1;
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
            heapify(minIndex);
            return;
        }
    }

    public:
        Heap(int default_size = 10,bool type = true){
            v.reserve(default_size);
            v.push_back(-1);
            minHeap = type;
        }

        void push(int x){
            v.push_back(x);
            int index = v.size() - 1;
            int parent = index/2;
            while(index>1 && compare(v[index],v[parent])){
                swap(v[index],v[parent]);
                int index = parent;
                int parent = index/2;
            }
        }

        void pop(){
            int last = v.size() - 1;
            swap(v[1],v[last]);
            v.pop_back();
            heapify(1);
        }

        void deleteNode(int index){
            int last = v.size() - 1;
            swap(v[index],v[last]);
            v.pop_back();
            heapify(index);
        }

        int top(){
            return v[1];
        }

        bool empty(){
            return v.size()==1;
        }
};

int main(){
    Heap H;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        H.push(x);
    }

    while(!H.empty()){
        cout<<H.top()<<" ";
        H.pop();
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        H.push(x);
    }
    H.deleteNode(2);
    while(!H.empty()){
        cout<<H.top()<<" ";
        H.pop();
    }
    return 0;
}

