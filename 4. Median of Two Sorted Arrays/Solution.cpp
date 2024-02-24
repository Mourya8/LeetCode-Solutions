class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x;
        double y;
        for(int i=0;i<nums2.size();i++)
        {
            nums1.push_back(nums2[i]);
        }
        nums2.clear();
        sort(nums1.begin(),nums1.end());
        x=nums1.size();
        if(x%2==0)
        {
            y=nums1[x/2]+nums1[(x/2)-1];
            y=y/2;
            return y;
        }
        else
        {
            y=nums1[x/2];
            return y;
        }
        
    }
};