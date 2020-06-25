#include<bits/stdc++.h>
using namespace std;

struct trie{
    int count;
    trie* children[2];
    trie(){
        count = 0;
        children[0] = NULL;
        children[1] = NULL;
    }    
};

trie* head;

void insert(vector<int>& v,int val){
    trie* current = head;
    trie* newNode;
    for(int i=31;i>=0;i--){
        int bit = (val>>i) & 1;
        if(current->children[bit]==NULL){
            newNode = new trie;
            newNode->count = 1;
            current->children[bit] = newNode;
        }else{
            (current->children[bit]->count)++;
        }
        current = current->children[bit];
    }
    return;
}

long long query(vector<int>& v,int val){
    long long ans = 0;
    trie* current = head;
    if(head==NULL){
        return 0;
    }
    for(int i=31;i>=0;i--){
        int bit = (val>>i)&1;
        if(current->children[1-bit]){
            current = current->children[1-bit];
            ans = ans*2 + 1;
        }else{
            current = current->children[bit];
            ans = ans*2;
        }
    }
    return ans;
}

int main(){
    int n,tempxor;
    long long ans;
    cin>>n;
    vector<int> v;
    head = new trie;
    ans = 0;
    tempxor = 0;
    insert(v,tempxor);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        tempxor = tempxor^x;
        ans = max(ans,query(v,tempxor));
        insert(v,tempxor);
    }
    cout<<ans<<endl;
    return 0;
}
