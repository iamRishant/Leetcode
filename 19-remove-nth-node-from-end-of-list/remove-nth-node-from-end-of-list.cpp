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
    int Len(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;

        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=Len(head);
        int N=len-n;
        if(len==1) return NULL;

        ListNode * curr=head;
        ListNode *prev=nullptr;
        if(N==0) return head->next;
        while(N--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;

        return head;
        
    }
};