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
    int maxi=-1e9;
    int solve(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int lsum=solve(root->left);
        int rsum=solve(root->right);
        int pathSum=root->val+lsum+rsum;
        maxi=max(maxi,pathSum);
        if(pathSum<0) return 0;
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        // we have to go everynode and find max path passing through it
        maxi=root->val;
        solve(root);
        return maxi;
    }
};