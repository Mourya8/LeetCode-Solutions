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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=1;
        }
        while(head!=NULL&&m.find(head->val)!=m.end())
        {
            head=head->next;
        }
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->next)
            {
                if(m.find(temp->next->val)!=m.end())
                {
                    temp->next=temp->next->next;
                }
                else
                {
                    temp=temp->next;
                }
            }
            else temp=temp->next;
        }
        return head;
    }
};