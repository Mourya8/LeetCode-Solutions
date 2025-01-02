class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};

        int l=0, r =nums.size();
        int mid = l + (r-l)/2;
        bool found = 0;

        while(l<r)
        {
            if(nums[mid]==target) 
            {
                found=1;
                break;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
            mid = l + (r-l)/2;
        }
        if(found==0) return {-1,-1};

        int temp = mid;
        while(temp>=0 && nums[temp]==target ) 
        {
            temp--;
        }

        while(mid<nums.size() && nums[mid]==target )
        {
            mid++;
        }

        return {temp+1,mid-1};



    }
};