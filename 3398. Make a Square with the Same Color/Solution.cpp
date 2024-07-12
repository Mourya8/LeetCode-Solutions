class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i-1>=0&&j-1>=0)
                {
                    if(grid[i-1][j]==grid[i][j]&&grid[i][j-1]==grid[i][j])return true;
                }
                if(i-1>=0&&j+1<3)
                {
                    if(grid[i-1][j]==grid[i][j]&&grid[i][j+1]==grid[i][j])return true;
                }
                if(i+1<3&&j+1<3)
                {
                    if(grid[i+1][j]==grid[i][j]&&grid[i][j+1]==grid[i][j])return true;
                }
                if(i+1<3&&j-1>=0)
                {
                    if(grid[i+1][j]==grid[i][j]&&grid[i][j-1]==grid[i][j])return true;
                }
            }
        }
        return false;
    }
};