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
    
    int maxi=0;
    int height(TreeNode* root){
        if(root==NULL) return 0;

        int lh=height(root->left);
        int rh=height(root->right);
        // now we are calculating left height and right height and storing the value
        maxi=max(maxi,lh+rh);// here we are storing the diameter while finding the height
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // now we will do it in order of n

        height(root);
        return maxi;
    }
};