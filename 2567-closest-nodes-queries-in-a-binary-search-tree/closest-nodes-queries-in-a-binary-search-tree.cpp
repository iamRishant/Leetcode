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
    void solve(TreeNode* root,vector<int> &inorder){
        if(root==NULL) return ;

        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inorder;
        solve(root,inorder);
        vector<vector<int>> ans;
        
        for(int i=0;i<queries.size();i++){
            int first=lower_bound(inorder.begin(),inorder.end(),queries[i])-inorder.begin();
            if(first<0){
                ans.push_back({-1,inorder[0]});
            }
            else if(first==inorder.size()){
                int n=inorder.size()-1;
                ans.push_back({inorder[n],-1});
            }
            else if(inorder[first]==queries[i]){
                ans.push_back({inorder[first],inorder[first]});
            }
            else{
                int high=inorder[first];
                int low=-1;
                if(first>0) low=inorder[first-1];
                ans.push_back({low,high});
            }

        }
        return ans;
    }
};