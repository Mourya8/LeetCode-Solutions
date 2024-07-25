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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode* slow = head;
        ListNode* fast=head;
        ListNode* slowParent=head;
        while(fast!=NULL && n>0)
        {
            fast=fast->next;
            n--;
        }
        while(fast!=NULL)
        {
            slowParent=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(slow==head) return slow->next;
        slowParent->next=slow->next;
        return head;

    }
};