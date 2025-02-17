class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int j = grid[0].size()-1;j>0;j--)
        {
            int i=0;
            int k =  j;
            while(k>=0 && k<grid[0].size() && i>=0  && i<grid.size())
            {
                q.push(grid[i][k]);
                //cout << grid[i][k] <<endl;
                i++;
                k++;
            }
            i=0;
            k =  j;
            while(k>=0 && k<grid[0].size() && i>=0  && i<grid.size())
            {
                grid[i][k]= q.top();
                q.pop();
                i++;
                k++;
            }
        }
        priority_queue<int> pq;
        for(int i = 0;i<grid.size();i++)
        {
            int j=0;
            int k =  i;
            while(k>=0 && k<grid.size() && j>=0  && j<grid[0].size())
            {
                pq.push(grid[k][j]);
                //cout << grid[k][j] <<endl;
                j++;
                k++;
            }
            j=0;
            k = i;
            while(k>=0 && k<grid.size() && j>=0  && j<grid[0].size())
            {
                grid[k][j]= pq.top();
                pq.pop();
                j++;
                k++;
            }
        }
        return grid;
    }
};