class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> r;
        for(int i=0;i<queries.size();i++)
        {
            int d =abs(queries[i][0])+ abs(queries[i][1]);
            pq.push(d);
            if(pq.size()>k) pq.pop();
            if(pq.size()<k) r.push_back(-1);
            else r.push_back(pq.top());
        }
        return r;
    }
};