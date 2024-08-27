class Solution {
public:
    void dfs(vector<vector<pair<int,double>>> &al, vector<bool> &visit, int current, int end_node, double &p, double currentP)
    {
        if(current==end_node)
        {
            p=max(p,currentP);
            return;
        }

        for(int i=0;i< al[current].size();i++)
        {
            if(visit[al[current][i].first]==0)
            {
                visit[al[current][i].first]=1;
                dfs(al,visit, al[current][i].first, end_node, p, currentP*al[current][i].second);
                visit[al[current][i].first]=0;
            }
        }
        return;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        vector <bool> visit(n,0);

        //cout<<al.size()<<endl;

        for(int i=0;i< edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double> prob(n,0.0);
        prob[start]=1.0;
        queue<pair<int,double>> q;
        q.push({start,1.0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto v:adj[it.first]){
                if(prob[v.first]<(it.second*v.second)){
                    prob[v.first]=it.second*v.second;
                    q.push({v.first,prob[v.first]});
                }
            }
        }
        return prob[end];

    }
};