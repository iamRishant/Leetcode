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
    TreeNode * prev=NULL;
    void flatten(TreeNode* root) {
        // recursion is easy just last node par jao by doing (right left node) ulta of pre order and then assign its value to prev
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);
         
        //  now we need to update node linkiing
        root->right=prev;
        root->left=NULL;
        prev=root;//updating prev
        
    }
};