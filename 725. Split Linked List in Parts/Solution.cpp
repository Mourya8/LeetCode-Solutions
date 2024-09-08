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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n =0;
        vector<ListNode*> a;

        ListNode* temp = head;
        ListNode* tail;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        cout <<n<<endl;
        
        int r =n%k;
        int q = n/k;
        temp = head;

        while(temp)
        {
            a.push_back(temp);
            for(int i=0;i<q;i++)
            {
                tail=temp;
                temp=temp->next;
            }
            if(r>0)
            {
                tail=temp;
                temp=temp->next;
                r--;
            }
            tail->next=NULL;
        }
        if(a.size()<k)
        {
            while(a.size()<k) 
            {
                a.push_back(NULL);
            }
        }

        return a;
    }
};