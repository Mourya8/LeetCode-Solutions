class Solution {
public:

    int digitSum(int x)
    {
        int s = 0;
        int temp = 0;
        while(x!=0)
        {
            temp = x%10;
            x=x/10;
            s+=temp;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,set<int>> s;
        int maxSum = 0;
        int t,p;
        for(int i=0;i<nums.size();i++)
        {
            t = digitSum(nums[i]);
            //cout << t <<endl;
            if(s.find(t)==s.end())
            {
                s[t].insert(nums[i]);
            }
            else
            {
                p = *s[t].rbegin();
                maxSum=max(maxSum,nums[i]+p);
                s[t].insert(nums[i]);
            }
        }

        return maxSum==0? -1 : maxSum;
    }
};