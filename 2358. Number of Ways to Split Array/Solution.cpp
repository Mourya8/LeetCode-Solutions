class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector <long long> r(nums.size(),0);
        vector<long long> l(nums.size(),0);
        l[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            l[i]=l[i-1]+nums[i];
        }
        r[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            r[i]=r[i+1]+nums[i];
        }

        int x=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(l[i]>=r[i+1]) x++;
        }

        return x;
    }
};