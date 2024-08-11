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
        // Morris Traversal o(n) time and o(1) space using threaded binary tree
        // case 1 if left is null then just print and move to right
        // case 2 is left is not null then go left and move to its right most part and connect it to root

        vector<int> inorder;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode * temp=curr->left;
                while(temp->right!=NULL && temp->right!=curr){
                    temp=temp->right;
                }
                // ab yha do case ya to temp->right=NULL mtlb first time visit krr rhe
                // but agar temp->right=curr hai then mtlb visit kar chuke hai we need to remove this thred and move to right
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
            return inorder;
    }
};