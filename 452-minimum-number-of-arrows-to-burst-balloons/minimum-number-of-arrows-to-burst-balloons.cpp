class Solution {
    
public:
    static bool compareFirstElement(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compareFirstElement);
        if (points.size()==0)
        {
            return 0;
        }
        int count =1;
        vector <int> current;
        current.push_back(points[0][0]);
        current.push_back(points[0][1]);
        for(int i=1;i<points.size();i++)
        {
            if (current[1]<points[i][0])
            {
                count++;
                current[0]=points[i][0];
                current[1]=points[i][1];
            }
            else
            {
                current[0]=max(current[0],points[i][0]);
                current[1]=min(current[1],points[i][1]);
            }
        }
        return count;
    }
};