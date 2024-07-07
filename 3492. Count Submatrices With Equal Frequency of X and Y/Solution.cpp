class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count = 0;
        vector<vector<pair<int, int>>> g(grid.size(), vector<pair<int, int>>(grid[0].size(), make_pair(0, 0)));
        for(int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    if(grid[i][j]=='X')
                    {
                        g[i][j].first=1; g[i][j].second=1;
                    }
                    else if(grid[i][j]=='Y')
                    {
                        g[i][j].first=-1; g[i][j].second=1;
                    }
                }
                else if(i==0)
                {
                    if(grid[i][j]=='X'){g[i][j].first=1+g[i][j-1].first; g[i][j].second=1;}
                    else if(grid[i][j]=='Y'){g[i][j].first=-1+g[i][j-1].first;g[i][j].second=1;}
                    else
                    {
                        g[i][j].first=g[i][j-1].first;
                        g[i][j].second=g[i][j-1].second;
                    }
                }
                else if(j==0)
                {
                    if(grid[i][j]=='X'){g[i][j].first=1+g[i-1][j].first; g[i][j].second=1;}
                    else if(grid[i][j]=='Y'){g[i][j].first=-1+g[i-1][j].first; g[i][j].second=1;}
                    else
                    {
                        g[i][j].first=g[i-1][j].first;
                        g[i][j].second=g[i-1][j].second;
                    }
                }
                else
                {
                    if(grid[i][j]=='X'){g[i][j].first=1+g[i-1][j].first+g[i][j-1].first-g[i-1][j-1].first; g[i][j].second=1;}
                    else if(grid[i][j]=='Y'){g[i][j].first=-1+g[i-1][j].first+g[i][j-1].first-g[i-1][j-1].first; g[i][j].second=1;}
                    else
                    {
                        g[i][j].first=g[i-1][j].first+g[i][j-1].first-g[i-1][j-1].first;
                        if(g[i-1][j].second==1||g[i-1][j-1].second==1||g[i][j-1].second==1)g[i][j].second=1;
                    }
                }
                if(g[i][j].first==0&&g[i][j].second==1) 
                {
                    count++;
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        return count;
    }
};