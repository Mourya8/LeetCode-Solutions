class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows* cols;
        vector <vector<int>> r;
        vector<vector<int>> t;
        r.push_back({rStart,cStart});
        t=r;
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int counter = 2;
        int length = 1;
        int d=0;
        while(r.size()<=total)
        {
            if(counter==0)
            {
                counter=2;
                length+=1;
            }
            int tempLen=length;
            d=d%4;
            while(tempLen>0)
            {
                vector<int> temp = t[t.size()-1];
                t.push_back({temp[0]+directions[d][0],temp[1]+directions[d][1]});
                if(temp[0]+directions[d][0]>=0 && temp[0]+directions[d][0]<rows && temp[1]+directions[d][1]>=0 && temp[1]+directions[d][1]<cols)
                {
                    //cout<<temp[0]+directions[d][0]<<" "<<temp[1]+directions[d][1]<<endl;
                    r.push_back({temp[0]+directions[d][0],temp[1]+directions[d][1]});
                }
                if(r.size()==total) return r;
                tempLen--;
            }
            d++;
            counter--;
        }
        return r;
    }
};