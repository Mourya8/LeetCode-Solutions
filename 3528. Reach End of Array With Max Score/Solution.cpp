class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        if(nums.size()==1) return 0;
        long long maxS = 0;
        int current = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[current])
            {
                maxS+=((long long)nums[current]*(long long)(i-current));
                current=i;
            }
            else if(i==nums.size()-1)
            {
                maxS+=((long long)nums[current]*(long long)(i-current));
            }
        }
        return maxS;
    }
};