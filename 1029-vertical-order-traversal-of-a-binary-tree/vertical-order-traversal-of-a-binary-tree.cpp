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
    void traverse(TreeNode* root, vector<vector<int>> &store,int V,int H){
        store.push_back({V,H,root->val});

        if(root->left) traverse(root->left,store,V-1,H+1);
        if(root->right) traverse(root->right,store,V+1,H+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> store;
        if(root==NULL) return store;
        traverse(root,store,0,0);

        sort(store.begin(),store.end());
        int i=0;
        int n=store.size();
        vector<vector<int>> ans;
        while(i<n){
            vector<int> temp;
            temp.push_back(store[i][2]);
            int val=store[i][0];
            int count=0;
            for(int j=i+1;j<n && store[j][0]==val;j++){
                temp.push_back(store[j][2]);
                count++;
            }
            ans.push_back(temp);
            // if(count==0) count++;/
            i+=(count+1);
        }
        return ans;
    }
};