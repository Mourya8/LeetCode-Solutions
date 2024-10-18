class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(maxReach<i) return 0;

            maxReach = max(maxReach,i+nums[i]);
        }

        if(maxReach>=nums.size()-1) return 1;

        return 0;
    }
};