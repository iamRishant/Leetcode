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
    TreeNode * solve(vector<int> & preorder,int &i,long long  bound){
        if(i==preorder.size() || preorder[i]>bound) return NULL;

        TreeNode * root=new TreeNode(preorder[i++]);
        root->left=solve(preorder,i,root->val);//while moving left node val will be bound 
        root->right=solve(preorder,i,bound);//while moving right bound will bound

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,LLONG_MAX);
    }
};