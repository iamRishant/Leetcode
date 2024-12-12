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
    int maxi=INT_MIN;
    int solve(TreeNode *root){
        if(root==NULL) return 0;

        int leftVal=solve(root->left);
        int rightVal=solve(root->right);
        maxi=max(maxi,root->val+leftVal+rightVal);
        if(root->val+max(leftVal,rightVal)<0) return 0;

        return root->val+max(leftVal,rightVal);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};