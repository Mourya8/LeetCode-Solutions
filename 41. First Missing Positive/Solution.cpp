class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        for (int i = 0 ; i < n; ++i)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 1; i <= n; ++i)
            if (nums[i] != i)
                return i;
        return n + 1;
    }
};