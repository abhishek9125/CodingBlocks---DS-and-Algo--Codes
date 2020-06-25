class Solution {
public:
    class trieNode{
    public:
        trieNode* left;
        trieNode* right;
    };
    
    void insert(int n,trieNode* head){
        trieNode* current = head;
        for(int i=31;i>=0;i--){
            int bit = (n>>i) & 1;
            if(bit==0){
                if(!current->left){
                    current->left = new trieNode();
                }
                current = current->left;
            }else{
                if(!current->right){
                    current->right = new trieNode();
                }
                current = current->right;
            }
        }
    }
    
    int findMaxPairXOR(vector<int>& v,trieNode* head){
        int ans = INT_MIN;
        for(int i=0;i<v.size();i++){
            trieNode* current = head;
            int currentAns = 0;
            for(int j=31;j>=0;j--){
                int bit = (v[i]>>j) & 1;
                if(bit==0){
                    if(current->right){
                        currentAns += pow(2,j);
                        current = current->right;
                    }else{
                        current = current->left;
                    }
                }else{
                    if(current->left){
                        currentAns += pow(2,j);
                        current = current->left;
                    }else{
                        current = current->right;
                    }
                }
            }
            ans = max(ans,currentAns);
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& v) {
        trieNode* head = new trieNode();
        for(int i=0;i<v.size();i++){
            insert(v[i],head);
        }
        return findMaxPairXOR(v,head);
    }
};
