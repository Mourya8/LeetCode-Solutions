
class Solution {
public:

    double separateSquares(vector<vector<int>>& squares) {
        double l = 0; 
        double r = 1e10; 
        for(int i=0;i<squares.size();i++)
        {
            l = min(l,(double)squares[i][0]);
            r = max(r,(double)(squares[i][1]+squares[i][2]));
        }
        
        
        const double EPS = 1e-5; 
        double mid = (l + r) / 2.0; 
        while (r - l > EPS) {
            
            double below = 0; 
            double above = 0;

            for (auto& sq : squares) {
                int x = sq[0]; 
                int y = sq[1];
                int side = sq[2]; 

                if (y + side <= mid) {
                    below += 1.0 * side * side;
                } else if (y >= mid) {
                    above += 1.0 * side * side;
                } else {
                    double upperPart = y + side - mid; 
                    double lowerPart = mid - y;        
                    above += upperPart * side;
                    below += lowerPart * side;
                }
            }
            
            if (above > below) {
                l = mid; 
            } else {
                r = mid; 
            }
            mid = (l + r) / 2.0; 
        }

        return mid;
    }
};