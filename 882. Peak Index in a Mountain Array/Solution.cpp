class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size();
        int mid = l+(r-l)/2;
        while(!(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]))
        {
            // if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) break;
            if(arr[mid-1]<arr[mid])
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
            mid = l+(r-l)/2;
        }
        return mid;
    }
};