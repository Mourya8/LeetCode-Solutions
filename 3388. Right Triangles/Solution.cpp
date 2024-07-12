class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long long r=0;
        vector <int> row(m,0);
        vector <int> col(n,0);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)row[i]++;
            }
        }
        for(int j=0;j<grid[0].size();j++)
        {
            for(int i=0;i<grid.size();i++)
            {
                if(grid[i][j]==1)col[j]++;
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)r+=(long long)((row[i]-1)*(col[j]-1));
            }
        }
        return r;
    }
};