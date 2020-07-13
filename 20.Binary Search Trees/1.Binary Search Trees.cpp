#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class LinkedList{
    public:
        node* head;
        node* tail;
};

node* insertInBST(node* root,int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

node* buildTree(){
    int d;
    cin>>d;
    node* root = NULL;  
    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}

node* deleteInBST(node* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data<root->data){
        root->left = deleteInBST(root->left,data);
        return root;
    }else if(data>root->data){
        root->right = deleteInBST(root->right,data);
        return root;
    }else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        node* replace = root->right;
        while(replace->left!=NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right,replace->data);
        return root;
    }
}

LinkedList flattenBST(node* root){
    LinkedList l;
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }

    if(root->left==NULL && root->right==NULL){
        l.head = l.tail = root;
        return l;
    }

    if(root->left!=NULL && root->right==NULL){
        LinkedList leftLL = flattenBST(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    if(root->left==NULL && root->right!=NULL){
        LinkedList rightLL = flattenBST(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    LinkedList leftLL = flattenBST(root->left);
    LinkedList rightLL = flattenBST(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

bool search(node* root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(data<root->data){
        return search(root->left,data);
    }else{
        return search(root->right,data);
    }
}

bool isBST(node* root,int minV = INT_MIN,int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data>=minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}

node* buildPreorderTree(vector<int>& preorder,vector<int>& inorder,int start,int end,int &index){
    if(start>end){
        return NULL;
    }
    int data = preorder[index];
    index++;
    node* root = new node(data);
    int k = -1;
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==data){
            k = i;
            break;
        }
    }
    root->left = buildPreorderTree(preorder,inorder,start,k-1,index);
    root->right = buildPreorderTree(preorder,inorder,k+1,end,index);
    return root;
}

node* preorderBST(vector<int>& preorder){
    if(preorder.size()==0){
        return NULL;
    }
    vector<int> inorder = preorder;
    sort(inorder.begin(),inorder.end());
    return buildPreorderTree(preorder,inorder,0,preorder.size()-1,0);
}

int countBST(int n){
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] = dp[i] + dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<f->data<<",";
            q.pop();
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
        }
    }
    return;
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

int main(){
    node* root = buildTree();
    inorder(root);
    cout<<endl;
    bfs(root);
    // cout<<search(root,6)<<endl;
    // int s;
    // cin>>s;
    // root = deleteInBST(root,s);
    // bfs(root);
    LinkedList l = flattenBST(root);
    node* temp = l.head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
    }
    return 0;
}

