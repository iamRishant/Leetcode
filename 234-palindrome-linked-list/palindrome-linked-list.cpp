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
    ListNode * rev(ListNode * head){
        if(head==NULL || head->next==NULL) return head;

        ListNode *newHead=rev(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=NULL;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *itr2=rev(slow);
        ListNode *itr1=head;
        while(itr1 && itr2){
            if(itr1->val!=itr2->val) return false;
            itr1=itr1->next;
            itr2=itr2->next;
        }
        return true;
    }
};