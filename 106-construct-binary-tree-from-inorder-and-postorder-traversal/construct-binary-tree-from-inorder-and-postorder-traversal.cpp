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
    TreeNode* solve(vector<int> &inorder,int is,int ie,vector<int> &postorder,int ps,int pe,map<int,int> &mp){
        if(is>ie || ps>pe) return NULL;

        int node=postorder[pe];
        TreeNode * root=new TreeNode(node);
        int ind=mp[postorder[pe]];
        int nodeinleft=ind-is;

        root->left=solve(inorder,is,is+nodeinleft,postorder,ps,ps+nodeinleft-1,mp);
        root->right=solve(inorder,ind+1,ie,postorder,ps+nodeinleft,pe-1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // reverse(postorder.begin(),postorder.end());
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};