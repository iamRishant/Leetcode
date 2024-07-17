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
    vector<int> preorderTraversal(TreeNode* root) {
        // preorder root left right to to it iteratively we just have to use stack and do opposite root right left
        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            auto it=st.top();
            st.pop();
            ans.push_back(it->val);
            // now for preorder we need to push right first
            if(it->right!=NULL) st.push(it->right);
            if(it->left!=NULL) st.push(it->left);
        }
        return ans;
    }
};