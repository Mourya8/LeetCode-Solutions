class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            m[nums[i]]++;
        }
        ans.push_back(m.size());
        for(int i=k;i<nums.size();i++)
        {
            m[nums[i-k]]--;
            m[nums[i]]++;
            if(m[nums[i-k]]==0) m.erase(nums[i-k]);
            ans.push_back(m.size());
        }
        return ans;
    }
};