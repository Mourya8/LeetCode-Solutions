class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m =matrix[0].size();
        map<int,int> d;
        vector<int> r;
        //vector <int> col(m, INT_MIN);
        for(int i=0;i<n;i++)
        {
            int temp = INT_MAX;
            for(int j=0;j<m;j++)
            {
                temp=min(temp,matrix[i][j]);
            }
            //cout<<i<<" "<<temp<<endl;
            d[temp]=1;
        }
        for(int i=0;i<m;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[temp][i]<matrix[j][i]) 
                {
                    temp = j;
                }
            }
            //cout<<matrix[temp][i]<<endl;
            if(d.find(matrix[temp][i])!=d.end())
            {
                r.push_back(matrix[temp][i]);
            }
        }
        return r;
        
    }
};