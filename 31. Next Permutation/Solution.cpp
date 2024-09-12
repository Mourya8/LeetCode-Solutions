class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int i=nums.size()-2;
        int j = nums.size()-1;
        while(i>=0&&nums[i]>=nums[j])
        {
            i--;
            j--;
        }
        if(i<0) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int nextBig=j;
        for(int a=j;a<nums.size();a++)
        {
            //cout<<nums[nextBig]<<" "<< nums[i] <<" "<< nums[a]<<endl;
            if(nums[a]>nums[i]&& nums[nextBig] >nums[a])
            {
                nextBig=a;
            }
            //cout<<nums[nextBig]<<" "<< nums[i] <<" "<< nums[a]<<endl;
        }
        //cout<<nums[nextBig]<<endl;
        int temp=nums[i];
        nums[i]=nums[nextBig];
        nums[nextBig] = temp;
        sort(nums.begin()+i+1, nums.end());
        return;
    }
};