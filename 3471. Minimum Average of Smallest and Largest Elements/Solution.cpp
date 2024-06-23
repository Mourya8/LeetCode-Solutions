class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double minAvg = 2500;
        sort(nums.begin(),nums.end());
        int i=0;
        int j = nums.size()-1;
        double tempAvg = 0;
        while(i<j)
        {
            tempAvg = double(double(nums[i]+nums[j])/double(2));
            minAvg  = min (tempAvg,minAvg);
            i++;j--;
        }
        return minAvg;
    }
};