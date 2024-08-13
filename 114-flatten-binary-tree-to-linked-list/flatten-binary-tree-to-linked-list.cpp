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
    vector<int> preOrder;
    void solve(TreeNode * root){
        if(root==NULL) return;

        preOrder.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    void flatten(TreeNode* root) {
        solve(root);
        if(root==NULL) return ;
        TreeNode *temp=new TreeNode(preOrder[0]);
        // temp->left=NULL;
        TreeNode *dummy=temp;

        // for(int i=0;i<preOrder.size();i++) cout<<preOrder[i]<<" ";

        for(int i=1;i<preOrder.size();i++){
            TreeNode *newTemp=new TreeNode(preOrder[i]);
            root->right=newTemp;
            root->left=NULL;
            root=root->right;
        }
        
    }
};