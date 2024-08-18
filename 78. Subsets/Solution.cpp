class Solution {
public:
    void helper(vector<int> nums, int index, vector<int> s, vector<vector<int>> &r)
    {
        if(index == nums.size() )
        {
            r.push_back(s);
            return;
        }
        helper(nums,index+1,s,r);
        s.push_back(nums[index]);
        helper(nums,index+1,s,r);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> r;
        helper(nums,0,{},r);
        return r;
    }
};