/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> initial;
        ListNode* temp=head;
        while(temp!=NULL){
            initial.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=initial.size()-1;
        vector<int> ans;
        while(j>=i){
            if(i!=j){ 
            ans.push_back(initial[i++]);
            ans.push_back(initial[j--]);
            }
            else{
                ans.push_back(initial[i++]);
            }
        }
        int k=0;
        ListNode * t=head;
        int n=ans.size();
        while(t!=NULL){
            t->val=ans[k++];
            t=t->next;
        }
    }
};