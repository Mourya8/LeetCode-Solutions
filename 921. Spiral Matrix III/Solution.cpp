class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows* cols;
        vector <vector<int>> r;
        r.push_back({rStart,cStart});
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int counter = 2;
        int length = 1;
        int d=0;
        int tempLen;
        while(r.size()<=total)
        {
            if(counter==0)
            {
                counter=2;
                length+=1;
            }
            tempLen=length;
            d=d%4;
            while(tempLen>0)
            {
                rStart = rStart+directions[d][0];
                cStart = cStart+directions[d][1];
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                {
                    r.push_back({rStart,cStart});
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