class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
        int n=heights.size();
        if(n==1)return 0;

        priority_queue <int,vector<int> , greater<int>> pq;
        for(int i=1;i<n;i++)
        {
            int h = heights[i]-heights[i-1];
            if(h<=0) continue;
            else if(l>0){
                l--;
                pq.push(h);
            }
            else 
            {
                pq.push(h);
                int smallest_diff = pq.top();
                    pq.pop();
                    b -= smallest_diff;
                    
                    if (b < 0) {
                        return i-1;
                    }

            }
        }
        return n-1;
    }
};
