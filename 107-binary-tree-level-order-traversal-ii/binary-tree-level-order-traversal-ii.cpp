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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int> temp;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                if(it->left!=NULL) q.push(it->left);
                if(it->right!=NULL) q.push(it->right);
                temp.push_back(it->val);
                q.pop();
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};