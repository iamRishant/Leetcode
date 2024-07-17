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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // initial state root node in st1
        // step1 pop from st1 push into st2
        // step2 top element of st2 push its left and right to st1 
        // loop until st1 is empty and then the st2 will have the post order traversal
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(!st1.empty()){
            auto it=st1.top();
            st1.pop();
            st2.push(it);
            if(it->left!=NULL) st1.push(it->left);
            if(it->right!=NULL) st1.push(it->right);
        }
        while(!st2.empty()){
            auto it=st2.top();
            ans.push_back(it->val);
            st2.pop();
        }
        return ans;

    }
};