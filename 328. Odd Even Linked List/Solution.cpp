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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode *odd = head;
        ListNode* even;
        if(head) even = head->next;
        int n=1;

        ListNode* oddTail= odd;
        ListNode* evenTail=even;
        head=head->next;
        if(head) head=head->next;

        while(head)
        {
            if(n%2!=0)
            {
                oddTail->next=head;
                oddTail=oddTail->next;
            }
            else
            {
                evenTail->next=head;
                evenTail = evenTail->next;
            }
            head=head->next;
            n++;
        }
        if(evenTail) evenTail->next=NULL;
        if(oddTail) oddTail->next = even;
        return odd;
    }
};