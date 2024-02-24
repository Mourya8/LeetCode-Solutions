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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1;
        bool trig=0;
        int carry=0;
        while(l1->next!=NULL&&l2->next!=NULL)
        {
            //trig=1;
            int t=l1->val+l2->val+carry;
            l1->val=t%10;
            carry=t/10;
            if(l1->next)
            {
                l1=l1->next;
            }
            if(l2->next)
            {
                l2=l2->next;
            }
        }
        int x=l1->val+l2->val+carry;
        l1->val=x%10;
        carry=x/10;
        if(l1->next==NULL)
        {
            l1->next=l2->next;
        }
        if(l1->next)
        {
            trig=1;
            l1=l1->next;
        }
        while(l1&&l1->next!=NULL)
        {
            trig=1;
            int t=l1->val+carry;
            l1->val=t%10;
            carry=t/10;
            if(l1->next)
            {
                l1=l1->next;
            }
        }
        if(l1&&trig)
        {
            x=l1->val+carry;
            l1->val=x%10;
            carry=x/10;
        }
        if(carry!=0)
        {
            l1->next=new ListNode(carry);
        }
        return temp;
    }
};