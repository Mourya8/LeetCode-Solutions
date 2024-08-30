class Solution {
public:
    vector<vector<int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
    void mapIsland(vector<vector<int>>& grid, map <pair<int,int>, bool> &m, queue <pair<int,int>> &q)
    {
        int x, y ;
        while(!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            m[{x,y}]=1;
            q.pop();
            for(int i=0;i<d.size();i++)
            {
                if(x+d[i][0]>=0 && x+d[i][0]<grid.size()  && y + d[i][1] >=0 && y + d[i][1]<grid[0].size())
                {
                    if(grid[x+d[i][0]][y+d[i][1]]==1)
                    {
                        grid[x+d[i][0]][y+d[i][1]]=2;
                        q.push({x+d[i][0],y+d[i][1]});
                    }
                }
            }
        }
        
    }

    void allExist(vector<vector<int>>& grid, vector<vector<int>>& grid1, queue <pair<int,int>> &q, bool &b)
    {
        int x, y ;
        while(!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i=0;i<d.size();i++)
            {
                if(x+d[i][0]>=0 && x+d[i][0]<grid.size()  && y + d[i][1] >=0 && y + d[i][1]<grid[0].size())
                {
                    if(grid[x+d[i][0]][y+d[i][1]]==1)
                    {
                        if(grid1[x+d[i][0]][y+d[i][1]]!=1) b = 0;
                        grid[x+d[i][0]][y+d[i][1]]=2;
                        q.push({x+d[i][0],y+d[i][1]});
                    }
                }
            }
        }
        
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        map <pair<int,int>, bool> m;
        vector<pair<int,int>> v;
        queue <pair<int,int>> q;
        int count =0;
        // for(int i=0;i<grid1.size();i++)
        // {
        //     for(int j=0;j<grid1[0].size();j++)
        //     {
        //         if(grid1[i][j]==1)
        //         {
        //             q.push({i,j});
        //             grid1[i][j]=2;
        //             mapIsland(grid1,m,q);
        //         }
        //     }
        // }
        bool b = 1;

        for(int i=0;i<grid2.size();i++)
        {
            for(int j=0;j<grid2[0].size();j++)
            {
                if(grid2[i][j]==1)
                {
                    b=1;
                    q.push({i,j});
                    grid2[i][j]=2;
                    if(grid1[i][j]!=1) b = 0;
                    allExist(grid2,grid1,q,b);
                    if(b) 
                    {
                        //cout<< i <<" "<<j<<endl;
                        count++;
                    }
                }
            }
        }
        return count;

    }
};