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
        // post order using 2 stack
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        if(root==NULL) return {};
        st1.push(root);
        while(!st1.empty()){
            auto it=st1.top();
            st1.pop();
            st2.push(it);
            if(it->left) st1.push(it->left);
            if(it->right) st1.push(it->right);

        }

        vector<int> ans;
        while(!st2.empty()){
            auto it=st2.top();
            ans.push_back(it->val);
            st2.pop();
        }
        return ans;
    }
};