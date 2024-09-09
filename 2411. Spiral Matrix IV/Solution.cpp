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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> r(m,vector<int>(n,1001));
        vector<vector<int>> d = {{0,1},{1,0},{0,-1},{-1,0}};
        int t =m*n;
        vector<int> pos={0,0};
        int lr=0,rr=m-1,tc=0,bc=n-1, direction=0;;
        while(t>0)
        {
            while(pos[0]>=lr &&pos[0]<=rr && pos[1]>=tc && pos[1]<=bc && r[pos[0]][pos[1]]==1001)
            {
                //cout<<pos[0]<<" "<<pos[1]<<endl;
                if(head) 
                {
                    r[pos[0]][pos[1]]=head->val;
                    head=head->next;
                }
                else r[pos[0]][pos[1]]=-1;
                pos[0]+=d[direction][0];
                pos[1]+=d[direction][1];
                t--;
            }
            //cout<<pos[0]<<" "<<pos[1]<<endl;
            pos[0]-=d[direction][0];
            pos[1]-=d[direction][1];
            direction++;
            direction=direction%4;
            pos[0]+=d[direction][0];
            pos[1]+=d[direction][1];
        }
        return r;
    }
};