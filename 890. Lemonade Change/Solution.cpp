class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> a(3,0);
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5) a[0]++;
            else if(bills[i]==10)
            {
                if(a[0]>0) 
                {
                    a[0]--;
                    a[1]++;
                }
                else return 0;
            }
            else if(bills[i]==20)
            {
                if(a[0]>0 && a[1]>0) 
                {
                    a[0]--;
                    a[1]--;
                    a[2]++;
                }
                else if(a[0]>=3)
                {
                    a[0]-=3;
                }
                else return 0;
            }
        }
        return 1;
    }
};