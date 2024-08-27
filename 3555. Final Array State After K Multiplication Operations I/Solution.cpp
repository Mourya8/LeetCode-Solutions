class Solution {
public:
    int minIndex(vector<int> &nums)
    {
        int n=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[n]>nums[i]) n = i;
        }
        return n;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0;i<k;i++)
        {
            int n = minIndex(nums);
            nums[n]*=multiplier;
        }
        return nums;
    }
};