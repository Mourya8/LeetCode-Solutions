class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left =0;
        int count =0;
        int maxCount = -1;
        int right = 0;
        int prevZero = -1;
        while(right<nums.size())
        {
            if(nums[right]==0)
            {
                count++;
                if(count ==1)
                {
                    prevZero=right;
                }
            }
            if (count==2)
            {
                maxCount=max(maxCount,right-left);
                left=prevZero+1;
                prevZero=right;
                count--;
            }
            right++;
        }
        maxCount=max(maxCount,right-left);
        return maxCount-1;
    }
};