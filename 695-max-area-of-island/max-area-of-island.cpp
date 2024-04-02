class Solution {
public:
    int bfs(vector<vector<int>> &grid,int i,int j)
    {
        int x=0;
        queue <pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=2;
        while(!q.empty())
        {
            pair <int,int> temp = q.front();
            q.pop();
            x++;
            if(temp.first-1>=0)
            {
                if(grid[temp.first-1][temp.second]==1)
                {
                    q.push({temp.first-1,temp.second});
                    grid[temp.first-1][temp.second]=2;
                }
            }
            if(temp.first+1<grid.size())
            {
                if(grid[temp.first+1][temp.second]==1)
                {
                    q.push({temp.first+1,temp.second});
                    grid[temp.first+1][temp.second]=2;
                }
            }
            if(temp.second-1>=0){
                if(grid[temp.first][temp.second-1]==1)
                {
                    q.push({temp.first,temp.second-1});
                    grid[temp.first][temp.second-1]=2;
                }
            }
            if(temp.second+1<grid[0].size())
            {
                if(grid[temp.first][temp.second+1]==1)
                {
                    q.push({temp.first,temp.second+1});
                    grid[temp.first][temp.second+1]=2;
                }
            }
        }
        // cout<<i<<" i , j "<<j<<endl;
        
        // cout<<x<<endl;
        return x;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=0;
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if (grid[i][j]==1)
                {
                    m=max(m,bfs(grid,i,j));
                }
            }
        }
        return m;
    }
};