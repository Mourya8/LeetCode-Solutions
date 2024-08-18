class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l=0;
        int r = m-1;
        int mid ;
        while(l<=r)
        {
            mid =l+((r-l)/2);
            if(matrix[mid][0]<target) l=mid+1;
            else if(matrix[mid][0]>target) r = mid-1;
            else return 1;
        }

        //cout<<mid<<endl;

        int j = r;
        if (j < 0) return false;
        if (matrix[j][n-1] < target) return false;

        l=0;
        r = n-1;
        while(l<=r)
        {
            mid =l+((r-l)/2);
            if(matrix[j][mid]<target) l=mid+1;
            else if(matrix[j][mid]>target) r = mid-1;
            else return 1;
        }
        if(matrix[j][mid]==target) return 1;
        return 0;
    }


};