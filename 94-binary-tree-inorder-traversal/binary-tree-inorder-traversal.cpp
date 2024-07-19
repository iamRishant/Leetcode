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
    vector<int> inorderTraversal(TreeNode* root) {
        // all in one
        // num==1 then preorder, push(left,1) and push same with (root,num+1)
        //num==2 then in order, push(right,1) and push same with (root,num+1)
        // num==3 then post order
        
        vector<int> post;
        vector<int> pre;
        vector<int> in;
        if(root==NULL) return post;
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            auto roott=it.first;
            int num=it.second;
            if(num==1){
                pre.push_back(roott->val);
                st.push({roott,num+1});
                if(roott->left!=NULL) st.push({roott->left,1});
            }
            else if(num==2){
                in.push_back(roott->val);
                st.push({roott,num+1});
                if(roott->right!=NULL) st.push({roott->right,1});
            }
            else if(num==3){
                post.push_back(roott->val);

            }
        }
        return in;
    }
};