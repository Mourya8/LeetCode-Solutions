// class Solution {
// public:
//     int furthestBuilding(vector<int>& heights, int b, int l) {
//         int n=heights.size();
//         if(n==1)return 0;
// 	    if(l>=(n-1))return n-1;

//         priority_queue <int,vector<int> , greater<int>> pq;
//         for(int i=1;i<n;i++)
//         {
//             int h = heights[i]-heights[i-1];
//             if(h<=0) continue;
//             else if(l>0){
//                 l--;
//                 pq.push(h);
//             }
//             else if(b>=h)
//             {
//                 b-=h;
//             }
//             else if(!pq.empty())
//             {
//                 int height = pq.top();
//                 if(b>=height){
// 		            pq.pop();
// 		            b-=height;
// 		            pq.push(h);
//                 }
//                 else{
//                     return i-1;
//                 }

//             }
//             else return i-1;
//         }
//         return n-1;
//     }
// };
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff > 0) {
                pq.push(diff);
                
                if (pq.size() > ladders) {
                    int smallest_diff = pq.top();
                    pq.pop();
                    bricks -= smallest_diff;
                    
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        return heights.size() - 1;
    }
};