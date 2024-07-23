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
    int height(TreeNode *root){
        if(root==NULL) return 0;

        int left=1+height(root->left);
        int right=1+height(root->right);

        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // diameter of tree either lie in the left subtree
        // or right subtree
        // of height of left + right + 1
        // this if o(N^2)
        if(root==NULL) return 0;

        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=height(root->left)+height(root->right);
        // we are not counting the nodes we are counting edges so we dont need to add 1 to op3

        return max(op1,max(op2,op3));
    }
};