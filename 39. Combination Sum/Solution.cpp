class Solution {
public:
    void helper(vector<int> candidates, int sum, int target, vector <int> s, vector<vector<int>> &r, int index)
    {
        if(sum==target)
        {
            r.push_back(s);
            return;
        }
        else if(sum>target) return;
        for(int i = index;i<candidates.size();i++)
        {
            s.push_back(candidates[i]);
            helper(candidates, sum+candidates[i], target, s, r,i);
            s.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> r;
        int index = 0;
        int sum =0;
        helper(candidates, sum,target, {}, r, index);
        return r;
    }
};