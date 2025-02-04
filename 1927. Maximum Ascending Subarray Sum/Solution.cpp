class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum=nums[0];
        int tempSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                tempSum+=nums[i];
            }
            else{
                tempSum=nums[i];
            }
            maxSum=max(maxSum,tempSum);
        }
        return maxSum;
    }
};