class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int x =arrays[0][0];
        int y=arrays[0].back();
        int maxD=0;
        for(int i=1;i<arrays.size();i++)
        {
            maxD=max(maxD,abs(arrays[i][0]-y));
            maxD = max(maxD, abs(arrays[i].back()-x));
            x=min(x,arrays[i][0]);
            y=max(y,arrays[i].back());
        }
        return maxD;
    }
};