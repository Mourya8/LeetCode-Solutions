class Solution {
public:
    struct CompareSecond {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if(a[1]==b[1])
        {
            return a[2]>b[2];
        }
        return a[1] > b[1];
    }
};

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector <int> r;
        priority_queue<vector<int>, vector<vector<int>>, CompareSecond> pq;
        int n = tasks.size();
        long time = 0;
        int i=0;
        for(int i=0;i<n;i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        while (i<n || !pq.empty())
        {
            if(pq.empty())
            {
                time=max(time,long(tasks[i][0]));
                while(i<n &&tasks[i][0]<=time )
                {
                    pq.push(tasks[i]);
                    i++;
                }
            }
            if(!pq.empty())
            {
                vector<int> temp = pq.top();
                pq.pop();
                r.push_back(temp[2]);
                if(time<temp[0])
                {
                    time = long(temp[0]+temp[1]);
                }
                else
                {
                    time=time+long(temp[1]);
                }
                while(i<n&&tasks[i][0]<=time)
                {
                    pq.push(tasks[i]);
                    i++;
                }
            }
        }
        return r;

    }
};