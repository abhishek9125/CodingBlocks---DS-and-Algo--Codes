#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

node* buildTree()
{
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

node* buildTreeFromArray(int* a,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid = (start + end)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a,start,mid-1);
    root->right = buildTreeFromArray(a,mid+1,end);
    return root;
}

node* buildTreeFromTraversal(int* io,int* po,int start,int end)
{
    static int i = 0;
    if(start>end)
    {
        return NULL;
    }

    node* root = new node(po[i]);
    int index = -1;
    for(int j=start;j<=end;j++)
    {
        if(io[j]==po[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = buildTreeFromTraversal(io,po,start,index-1);
    root->right = buildTreeFromTraversal(io,po,index+1,end);
    return root;
}

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}

int count(node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return 1 + count(root->left) + count(root->right); 
}

int sum(node *root)
{
    if(root==NULL)
    {
        return 0;
    }

    return root->data + sum(root->left) + sum(root->right);
}

int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);
    int option1 = h1 + h2;
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}

class Pair{
    public:
        int height;
        int diameter;
};

Pair optimizedDiameter(node* root)
{
    Pair p;
    if(root==NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    Pair left = optimizedDiameter(root->left);
    Pair right = optimizedDiameter(root->right);

    p.height = max(left.height,right.height) + 1;
    p.diameter = max(left.height + right.height,max(left.diameter,right.diameter));
    return p;
}

int childSum(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    int leftSum = childSum(root->left);
    int rightSum = childSum(root->right);
    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + leftSum + rightSum;
}

class HBPair{
    public:
        int height;
        bool balanced;
};

HBPair isHeightBalanced(node* root)
{
    HBPair p;
    if(root==NULL)
    {
        p.height = 0;
        p.balanced = true;
        return p;
    }

    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);
    
    p.height = max(left.height,right.height) + 1;
    if(abs(left.height - right.height)<=1 && left.balanced && right.balanced)
    {
        p.balanced = true;
    }
    else
    {
        p.balanced = false;
    }
    return p;
}

void rightView(node* root,int level)
{
    static int maxLevelRight = -1;
    if(root==NULL)
    {
        return;
    }
    if(level>maxLevelRight)
    {
        maxLevelRight = level;
        cout<<root->data<<" ";
    }
    rightView(root->right,level+1);
    rightView(root->left,level+1);
    return;
}

void leftView(node* root,int level)
{
    static int maxLevelLeft = -1;
    if(root==NULL)
    {
        return;
    }
    if(level>maxLevelLeft)
    {
        maxLevelLeft = level;
        cout<<root->data<<" ";
    }
    leftView(root->left,level+1);
    leftView(root->right,level+1);
    return;
}



void preOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void printKthLevel(node* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;
}

void printAllLevels(node* root)
{
    int h = height(root);
    for(int i=1;i<=h;i++)
    {
        printKthLevel(root,i);
        cout<<endl;
    }
    return;
}

void bfs(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f = q.front();
        if(f==NULL)
        {
            q.pop();
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

int main()
{
    node* root = buildTree();
    preOrder(root); 
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    bfs(root);
    printKthLevel(root,3);
    cout<<endl;
    printAllLevels(root);
    cout<<count(root)<<" "<<sum(root)<<endl;
    cout<<diameter(root)<<endl;
    Pair a = optimizedDiameter(root);
    cout<<a.diameter<<endl;
    // childSum(root);
    // bfs(root);
    HBPair heightBalanced = isHeightBalanced(root);
    cout<<heightBalanced.height<<" ";
    if(heightBalanced.balanced)
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Unbalanced";
    }
    cout<<endl;
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    node* root2 = buildTreeFromArray(arr,0,n-1);
    bfs(root2);
    int io[] = {3,2,8,4,1,6,7,5};
    int po[] = {1,2,3,4,8,5,6,7};
    int n2 = sizeof(io)/sizeof(int);
    node* root3 = buildTreeFromTraversal(io,po,0,n2-1);
    bfs(root3);
    bfs(root);
    rightView(root,0);
    cout<<endl;
    leftView(root,0);
    return 0; 
}
