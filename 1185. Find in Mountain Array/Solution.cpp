/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getPeak(MountainArray &mountainArr, int l, int r)
    {
        int mid = l+(r-l)/2;
        while(!(mountainArr.get(mid-1)<mountainArr.get(mid) && mountainArr.get(mid)>mountainArr.get(mid+1)))
        {
            if(mountainArr.get(mid-1)<mountainArr.get(mid))
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

    int getLeft(int target,MountainArray &mountainArr, int l, int r)
    {
        int mid = l+(r-l)/2;
        while(l<r)
        {
            // cout<<l<<" "<<mid<<" "<<r<<endl;
            // cout<<mountainArr.get(mid)<< target<<endl;
            if(target == mountainArr.get(mid)) return mid;
            else if(target>mountainArr.get(mid))
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
            mid = l+(r-l)/2;
        }
        return -1;
    }

    int getRight(int target,MountainArray &mountainArr, int l, int r)
    {
        int mid = l+(r-l)/2;
        while(l<r)
        {
            if(target == mountainArr.get(mid)) return mid;
            else if(target<mountainArr.get(mid))
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
            mid = l+(r-l)/2;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int r = mountainArr.length();
        int peak = getPeak(mountainArr,0,r);
        //cout<<peak<<endl;
        int left = getLeft(target,mountainArr, 0, peak);
        // cout<<left<<endl;
        int right = getRight(target, mountainArr, peak, r);
        // cout<<right<<endl;

        if(left==-1 && right == -1) return -1;
        else if(left==-1 && right !=-1) return right;
        else if(left!=-1 && right ==-1) return left;

        return min(left,right);
    }
};