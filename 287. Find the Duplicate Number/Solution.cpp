class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=i)
            {
                return nums[i];
            }
            while(nums[i]-1!=i)
            {
                //int temp=nums[nums[i]-1];
                if(nums[i]==nums[nums[i]-1])
                {
                    return nums[i];
                }
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        return nums[nums.size()-1];
    }
};