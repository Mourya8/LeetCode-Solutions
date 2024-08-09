class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3||grid[0].size()<3)
        {
            return 0;
        }
        map<int,bool> dict;
        int count=0;
        map<int,bool> commonSum;
        for(int m=2;m<grid.size();m++)
        {
            for(int n=2;n<grid[0].size();n++)
            {
                dict.clear();
                commonSum.clear();
                for(int i=m-2;i<=m;i++)
                {
                    int tempSum=0;
                    for(int j=n-2;j<=n;j++)
                    {
                        if(grid[i][j]<=9&&grid[i][j]>=1)
                        {
                            dict[grid[i][j]]=1;
                            tempSum+=grid[i][j];
                        }
                        
                    }
                    commonSum[tempSum]=1;
                    cout<<tempSum<<endl;
                }
                for(int j=n-2;j<=n;j++)
                {
                    int tempSum=0;
                    for(int i=m-2;i<=m;i++)
                    {
                        tempSum+=grid[i][j];
                    }
                    commonSum[tempSum]=1;
                }
                int tempSum=0;
                for(int i=m-2,j=n-2; i<=m,j<=n;i++,j++)
                {
                    tempSum+=grid[i][j];
                }
                commonSum[tempSum]=1;
                tempSum=0;
                for(int i=m,j=n-2; i>=m-2,j<=n;i--,j++)
                {
                    tempSum+=grid[i][j];
                }
                commonSum[tempSum]=1;

                if(dict.size()==9 && commonSum.size()==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};