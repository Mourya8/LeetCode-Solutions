class Solution {
public:
    void helper(vector<int> nums, int index, vector<int> s, vector<vector<int>> &r, map<vector<int>,bool> &m)
    {
        if(index == nums.size() )
        {
            sort(s.begin(),s.end());
            if(m.find(s)==m.end())
            {
                r.push_back(s);
                m[s]=1;
            }
            return;
        }
        helper(nums,index+1,s,r,m);
        s.push_back(nums[index]);
        helper(nums,index+1,s,r,m);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> r;
         map<vector<int>,bool> m;
        helper(nums,0,{},r,  m);
        return r;
    }
};