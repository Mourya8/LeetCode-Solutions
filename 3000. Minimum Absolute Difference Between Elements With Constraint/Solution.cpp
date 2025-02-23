class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int s) {
        map<int,int> m;
        int r = INT_MAX;
        for(int i=s;i<nums.size();i++)
        {
            m[nums[i-s]]=i-s;
            auto x = m.lower_bound(nums[i]);
            auto y = m.lower_bound(nums[i]);
            if(y==m.begin()) y= m.end();
            else y--;
            int a = INT_MAX;
            int b =INT_MAX;
            if(x!=m.end() && abs(i-x->second)>=s) a=abs(nums[i]-x->first);
            if(y!=m.end() && abs(i-y->second)>=s) b=abs(nums[i]-y->first);
            
            r=min(r,min(a,b));
            
        }
        return r;
    }
};