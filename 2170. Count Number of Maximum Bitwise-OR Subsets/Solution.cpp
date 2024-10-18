class Solution {
public:
    void subsetOr(vector <int> & nums, int index, int maxOr, int tempOr, int &count)
    {
        
        if(index==nums.size()) 
        {
            if(tempOr==maxOr)
            {
                count++;
            }
            return;
        }

        int temp = tempOr | nums[index] ; 

        subsetOr(nums,index+1,maxOr, temp,count);
        subsetOr(nums,index+1,maxOr, tempOr,count);

        return;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;

        for(int i=0;i<nums.size();i++)
        {
            maxOr=maxOr | nums[i];
        }


        int count = 0;
        subsetOr(nums,0,maxOr,0,count);

        return count;
    }
};