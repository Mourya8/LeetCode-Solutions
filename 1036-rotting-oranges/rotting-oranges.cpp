class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int counter=0;
        queue <pair<int,int>> q;
        int x=grid.size();
        int y=grid[0].size();
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        // bool check=0;
        while(!q.empty())
        {
            int n=q.size();
            //cout<<counter<<" seconds"<<endl;
            for(int i=0;i<n;i++)
            {
                auto temp=q.front();
                //cout<<temp.first<<" "<<temp.second<<endl;
                q.pop();
                if(temp.first>0)
                {
                    if(grid[temp.first-1][temp.second]==1)
                    {
                        grid[temp.first-1][temp.second]=2;
                        q.push({temp.first-1,temp.second});
                        // check=1;
                    }
                }
                if(temp.first<x-1)
                {
                    if(grid[temp.first+1][temp.second]==1)
                    {
                        grid[temp.first+1][temp.second]=2;
                        q.push({temp.first+1,temp.second});
                        // check=1;
                    }
                }
                if(temp.second>0)
                {
                    if(grid[temp.first][temp.second-1]==1)
                    {
                        grid[temp.first][temp.second-1]=2;
                        q.push({temp.first,temp.second-1});
                        // check=1;
                    }
                }
                if(temp.second<y-1)
                {
                    if(grid[temp.first][temp.second+1]==1)
                    {
                        grid[temp.first][temp.second+1]=2;
                        q.push({temp.first,temp.second+1});
                        // check=1;
                    }
                }
            }
            counter++;
        }
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        //if(check==0)counter=counter-1;
        return max(0,counter-1);
    }
};