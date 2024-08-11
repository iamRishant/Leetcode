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
    TreeNode * solve(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart,int inend,map<int,int> &mp){
        if(instart>inend || prestart>preend) return NULL;

        int node=preorder[prestart];
        TreeNode * root=new TreeNode(node);

        int ind=mp[node];
        int numInLeft=ind-instart;
        
        root->left=solve(preorder,prestart+1,prestart+numInLeft,inorder,instart,ind-1,mp);
        root->right=solve(preorder,prestart+numInLeft+1,preend,inorder,ind+1,inend,mp);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};