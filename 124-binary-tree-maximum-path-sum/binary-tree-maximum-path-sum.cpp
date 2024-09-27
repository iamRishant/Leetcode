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
    int solve(TreeNode *root,int &maxi){
        if(root==NULL) return 0;

        int lsum=solve(root->left,maxi);
        int rsum=solve(root->right,maxi);
        int pathSum=root->val+lsum+rsum;
        maxi=max(pathSum,maxi);
        if(pathSum<0) return 0;
        
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=root->val;
        solve(root,maxi);
        return maxi;
    }
};