class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum = 0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k) count++;
            int temp=sum-k;
            count+=m[temp];
            m[sum]++;
        }

        return count;
    }
};