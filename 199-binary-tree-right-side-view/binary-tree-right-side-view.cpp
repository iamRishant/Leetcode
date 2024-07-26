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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode *,int>> q;// root and horizontal dist;
        if(root==NULL) return {};
        q.push({root,0});
        map<int,int> mp;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            auto node=it.first;
            int hd=it.second;
            mp[hd]=node->val;
            if(node->left) q.push({node->left,hd+1});
            if(node->right) q.push({node->right,hd+1});
        }
        vector<int> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }

};