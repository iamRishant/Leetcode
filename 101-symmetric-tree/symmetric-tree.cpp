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
    bool solve(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL) return false;
        else if(root1==NULL && root2!=NULL) return true;
        else if(root1!=NULL && root2==NULL) return true;
        if(root1->val!=root2->val) return true;

        if(root1==NULL) return false;
        bool op1=solve(root1->left,root2->right);
        bool op2=solve(root1->right,root2->left);

        return op1||op2;
    }
    bool isSymmetric(TreeNode* root) {
        return !solve(root->left,root->right);
    }
};