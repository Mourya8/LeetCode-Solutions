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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* a = head;
        ListNode* b = head->next;
        while(b)
        {
            int t = gcd(a->val,b->val);
            ListNode * temp =new ListNode(t);
            a->next=temp;
            temp->next=b;
            a=b;
            b=b->next;
        }
        return head;
    }
};