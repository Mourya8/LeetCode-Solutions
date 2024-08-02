class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total =0;
        for (int i=0;i< nums.size();i++)
        {
            if (nums[i]==1) total++;
        }
        int l=0;
        int r=l+total-1;
        int minSwaps=total;
        int winTotal=0;
        for(int i=0;i<=r;i++)
        {
            if (nums[i]==1) winTotal++;
        }
        minSwaps=min(minSwaps,total-winTotal);
        while(l<nums.size())
        {
            if(nums[l]==1) winTotal--;
            if(r==nums.size()-1) r=0;
            else r++;
            l++;
            if(nums[r]==1)winTotal++;
            minSwaps=min(minSwaps,total-winTotal);
        }
        return minSwaps;
    }
};