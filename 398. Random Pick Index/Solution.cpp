class Solution {
public:
    map <int,vector<int>> m;
    Solution(vector<int>& nums) {
        m.clear();
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int range = m[target].size();
        int t = rand();
        t = t%range;
        //cout <<  range <<endl;
        return m[target][t];
    }
};



/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */