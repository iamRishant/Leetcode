/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushAll(TreeNode * node){
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        if(!st.empty()){
            auto it=st.top();
            int ans=it->val;
            st.pop();
            if(it->right){
                pushAll(it->right);
            }
            return ans;
        }
        return -1;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */