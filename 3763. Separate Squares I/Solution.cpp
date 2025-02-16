
class Solution {
public:
    double helper(double line, vector<vector<int>>& squares){
        double aAbove = 0, aBelow = 0;
        int n = squares.size();
        for(int i = 0; i < n; i++){
            int x = squares[i][0], y = squares[i][1];
            int l = squares[i][2];
            double total = (double) l * l;
            
            if(line <= y){
                aAbove += total;
            } 
            else if(line >= y + l){
                aBelow += total;
            } 
            else{
                double aboveHeight = (y + l) - line;
                double belowHeight = line - y;
                aAbove += l * aboveHeight;
                aBelow += l * belowHeight;
            }
        }
        return aAbove - aBelow;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double lo = 1e9, hi = 0;
        for(int i=0;i<squares.size();i++)
        {
            lo = min(lo,(double)squares[i][0]);
            hi = max(hi,(double)(squares[i][1]+squares[i][2]));
        }
        
        
        for(int i = 0; i < 60; i++){
            double mid = (lo + hi) / 2.0;
            double diff = helper(mid, squares);

            if(diff > 0) lo = mid;
            else hi = mid;
        }

        return hi;
    }
};