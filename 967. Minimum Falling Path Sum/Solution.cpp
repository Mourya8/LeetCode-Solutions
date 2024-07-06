class Solution {
public:
    void dfs(vector <vector<int>> &m, int r, int &minSum)
    {
        int tempMin = INT_MAX;
        for(int i=0;i<m[r].size();i++)
        {
            if(i>0 && i<m[r].size()-1)
            {
                m[r][i]+=min(m[r-1][i-1],min(m[r-1][i],m[r-1][i+1]));
            }
            else if(i>0)
            {
                m[r][i]+=min(m[r-1][i-1],m[r-1][i]);
            }
            else if(i<m[r].size()-1)
            {
                m[r][i]+=min(m[r-1][i+1],m[r-1][i]);
            }
            else
            {
                m[r][i]+=m[r-1][i];
            }
            tempMin=min(tempMin,m[r][i]);
            //cout<<m[r][i]<<" "<<r<<" "<<i<<endl;
        }
        if (r==m.size()-1)
        {
            minSum=tempMin;
            return;
        }
        dfs(m,r+1,minSum);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        if (matrix.size()==1)
        {
            for(int i=0;i<matrix[0].size();i++)
            {
                minSum=min(minSum,matrix[0][i]);
            }
            return minSum;
        }
        dfs(matrix,1,minSum);
        return minSum;
    }
};