/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool traverse(TreeNode * root, TreeNode* find){
        if(root==NULL && find!=NULL) return false;

        if(root==find) return true;
        bool left=traverse(root->left,find);
        bool right=traverse(root->right,find);

        return left|| right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool leftp=traverse(root->left,p);
        bool leftq=traverse(root->left,q);
        bool rightp=traverse(root->right,p);
        bool rightq=traverse(root->right,q);
        if(leftp && rightq) return root;
        if(rightp && leftq) return root;
        if(leftp && leftq) return lowestCommonAncestor(root->left,p,q);
        if(rightp && rightq) return lowestCommonAncestor(root->right,p,q);

        return root;
    }
};