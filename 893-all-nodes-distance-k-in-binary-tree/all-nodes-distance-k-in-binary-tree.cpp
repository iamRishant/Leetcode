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
    void solve(TreeNode * root, unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        solve(root,parent_track);

        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*,bool> visited;
        visited[target]=true;
        int dis=0;
        while(!q.empty()){
            int sz=q.size();
            if(dis==k) break;
            dis++;
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    visited[parent_track[curr]]=true;
                    q.push(parent_track[curr]);
                }
                if(curr->left && !visited[curr->left]){
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && !visited[curr->right]){
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
            }
            
        }
        vector<int> ans;
            while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
    }
};