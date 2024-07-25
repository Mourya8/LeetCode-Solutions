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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        if(list.size()==0)
        {
            return NULL;
        }else if(list.size()==1)
        {
            return list[0];
        }
        ListNode* result=list[0];
        for(int i=1;i<list.size();i++)
        {
            result=merge(result,list[i]);
        }
        return result;
    }

    ListNode* merge(ListNode *l1, ListNode* l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *head,*tail;
        if(l1->val>l2->val)
        {
            head=l2;
            l2=l2->next;
        }
        else
        {
            head=l1;
            l1=l1->next;
        }
        tail=head;
        while(l1&&l2)
        {
           if(l1->val>l2->val)
            {
                tail->next=l2;
                l2=l2->next;
               tail=tail->next;
            }
            else
            {  
                tail->next=l1;
                l1=l1->next;
               tail=tail->next;
            } 
        }
        if(l1)
        {
            tail->next=l1;
        }
        if(l2)
        {
            tail->next=l2;
        }
        return head;
    }
};